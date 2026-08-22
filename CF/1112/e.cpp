#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

#define debug(...) fprintf(stderr, __VA_ARGS__)

template<typename T>
void readInt(T& x) {
    static bool f;
    x = 0;f = false;
    char c = getchar();
    for(;c<'0' || c>'9';c=getchar())if(c=='-')f=!f;
    for(;'0'<=c&&c<='9';c=getchar()) {
        x = x * 10 + c - '0';
    }
    if(f)x = -x;
}
template<typename T, typename ...Args>
void readInt(T& x, Args&... args) {
    readInt(x);
    readInt(args...);
}

const i64 inf = 0x3f3f3f3f3f3f3f3f;

struct Segtree {
    struct Node {
        i64 mx;
        i64 tag;
        Node *son[2];
        Node() : mx(-inf), tag(), son{NULL, NULL} {}
        void pushup() {
            mx = -inf;
            if (son[0])
                mx = std::max(mx, son[0]->mx);
            if (son[1])
                mx = std::max(mx, son[1]->mx);
        }
        void pushdown() {
            if (son[0] == NULL)
                son[0] = new Node;
            if (son[1] == NULL)
                son[1] = new Node;
            son[0]->mx += tag;
            son[1]->mx += tag;
            son[0]->tag += tag;
            son[1]->tag += tag;
            tag = 0;
        }
        void change(int l, int r, int x, i64 v) {
            if (l == r) {
                mx = v;
                return;
            }
            pushdown();
            int mid = ((l + r) >> 1);
            if (x <= mid)
                son[0]->change(l, mid, x, v);
            else
                son[1]->change(mid + 1, r, x, v);
            pushup();
        }
        void add(int l, int r, int ql, int qr, i64 v) {
            if (ql <= l && r <= qr) {
                mx += v;
                tag += v;
                return;
            }
            pushdown();
            int mid = ((l + r) >> 1);
            if (ql <= mid)
                son[0]->add(l, mid, ql, qr, v);
            if (qr > mid)
                son[1]->add(mid + 1, r, ql, qr, v);
            pushup();
        }
        int find(int l, int r) {
            if (l == r) {
                return l;
            }
            pushdown();
            int mid = ((l + r) >> 1);
            int ans;
            if (son[0]->mx >= son[1]->mx)
                ans = son[0]->find(l, mid);
            else
                ans = son[1]->find(mid + 1, r);
            pushup();
            return ans;
        }
    };

    Node *root;
    int L, R;
    Segtree(int l, int r) : root(new Node), L(l), R(r) {}
    void change(int x, i64 v) {
        // printf("change %d %lld\n", x, v);
        root->change(L, R, x, v);
    }
    void add(int l, int r, i64 v) {
        // printf("add [%d, %d] %lld\n", l, r, v);
        root->add(L, R, l, r, v);
    }
    int find() {
        if (root->mx <= 2)
            return 0;
        int ans = root->find(L, R);
        // printf("find %d\n", ans);
        return ans;
    }
};

void solve() {
    int n;
    readInt(n);
    veci p(n * 2 + 2);
    for (int i = 1; i <= n; ++i) {
        readInt(p[i]);
    }

    for (int i = n + 1; i <= n + n; ++i)
        p[i] = p[i - n];

    veci pos(n + 2);
    for (int i = 1; i <= n; ++i)
        pos[p[i]] = i;

    Segtree tree(1, n);
    for (int i = 1; i <= n; ++i)
        tree.change(i, 0);

    int ans = n;
    for (int i = 1; i <= n + n; ++i) {
        // printf("------cur pos [%d]-------\n", i);
        int l = std::max(1, i - n + 1);
        int r = std::min(n, i);
        tree.add(l, r, 1);
        if (p[i] - 1 >= 1) {
            // printf("handle %d\n", p[i] - 1);
            int v = p[i] - 1;
            int pp = pos[v];
            if (l <= pp && pp <= r)
                tree.add(l, pp, -1);
            else if (r <= pp && pp <= i)
                tree.add(l, r, -1);
            pp = pos[v] + n;
            if (l <= pp && pp <= r)
                tree.add(l, pp, -1);
            else if (r <= pp && pp <= i)
                tree.add(l, r, -1);
        }
        if (p[i] + 1 <= n) {
            // printf("handle %d\n", p[i] + 1);
            int v = p[i] + 1;
            int pp = pos[v];
            if (l <= pp && pp <= r)
                tree.add(l, pp, -1);
            else if (r <= pp && pp <= i)
                tree.add(l, r, -1);
            pp = pos[v] + n;
            if (l <= pp && pp <= r)
                tree.add(l, pp, -1);
            else if (r <= pp && pp <= i)
                tree.add(l, r, -1);
        }
        for (int it = tree.find(); it; it = tree.find()) {
            --ans;
            tree.change(it, -inf);
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
