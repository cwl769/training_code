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
#include <queue>
#include <stack>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

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

int innerL, innerR;
struct SegtreeInner {
    struct Node {
        i64 sum;
        int tag;
        int son[2];
        void pushup();
        void pushdown(int l, int r);
        void add(int l, int r, int ql, int qr);
        i64 query(int l, int r, int ql, int qr);
    } ;

    Node *root;
    SegtreeInner() {
        root = new Node;
    }
    void add(int l, int r) {
        root->add(innerL, innerR, l, r);
    }
    i64 query(int l, int r) {
        return root->query(innerL, innerR, l, r);
    }
};

SegtreeInner::Node node[62022420];
int node_tot = 1;

struct Segtree {
    struct Node {
        SegtreeInner tree;
        int son[2];

        void maketree(int l, int r);

        void add(int l, int r, int xx, int yl, int yr);

        i64 query(int l, int r, int xl, int xr, int yl, int yr);
    };

    Node *root;
    int L, R;
    Segtree(int xl, int xr, int yl, int yr) {
        root = new Node;
        L = xl;
        R = xr;
        innerL = yl;
        innerR = yr;
        root->maketree(L, R);
    }
    void add(int xx, int yl, int yr) {
        root->add(L, R, xx, yl, yr);
    }
    i64 query(int xl, int xr, int yl, int yr) {
        return root->query(L, R, xl, xr, yl, yr);
    }
};

Segtree::Node nodeout[3522000];
int nodeout_tot = 1;

void solve() {
    int n, m, Q;readInt(n, m, Q);
    Segtree tree(1, n, 1, m);
    for (int i = 1; i <= n; ++i) {
        int l, r;readInt(l, r);
        tree.add(i, l, r);
    }
    while(Q--) {
        int a, b, c, d;
        readInt(a, b, c, d);
        i64 ans = tree.query(a, b, c, d);
        printf("%lld\n", ans);
    }
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}

void Segtree::Node::maketree(int l, int r) {
    if(l == r)
        return;
    int mid = ((l + r) >> 1);
    son[0] = ++nodeout_tot;
    son[1] = ++nodeout_tot;
    nodeout[son[0]].maketree(l, mid);
    nodeout[son[1]].maketree(mid + 1, r);
}

void Segtree::Node::add(int l, int r, int xx, int yl, int yr) {
    tree.add(yl, yr);
    if(l == r)
        return;
    int mid = ((l + r) >> 1);
    if(xx <= mid)
        nodeout[son[0]].add(l, mid, xx, yl, yr);
    else
        nodeout[son[1]].add(mid+1, r, xx, yl, yr);
}

i64 Segtree::Node::query(int l, int r, int xl, int xr, int yl, int yr) {
    if(xl <= l && r <= xr)
        return tree.query(yl, yr);
    int mid = ((l + r) >> 1);
    i64 ans = 0;
    if(xl <= mid)
        ans += nodeout[son[0]].query(l, mid, xl, xr, yl, yr);
    if(xr > mid)
        ans += nodeout[son[1]].query(mid + 1, r, xl, xr, yl, yr);
    return ans;
}




void SegtreeInner::Node::pushup() {
    sum = 0;
    if(son[0])
        sum += node[son[0]].sum;
    if(son[1])
        sum += node[son[1]].sum;
}
void SegtreeInner::Node::pushdown(int l, int r) {
    if(son[0] == 0)son[0] = ++node_tot;
    if(son[1] == 0)son[1] = ++node_tot;
    int mid = ((l + r) >> 1);
    node[son[0]].sum += (mid - l + 1ll) * tag;
    node[son[1]].sum += 1ll * (r - mid) * tag;
    node[son[0]].tag += tag;
    node[son[1]].tag += tag;
    tag = 0;
}
void SegtreeInner::Node::add(int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        sum += (r - l + 1ll);
        tag ++;
        return;
    }
    pushdown(l, r);
    int mid = ((l + r) >> 1);
    if(ql <= mid)
        node[son[0]].add(l, mid, ql, qr);
    if(qr > mid)
        node[son[1]].add(mid+1, r, ql, qr);
    pushup();
}
i64 SegtreeInner::Node::query(int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr)
        return sum;
    pushdown(l, r);
    int mid = ((l + r) >> 1);
    i64 ans = 0;
    if(ql <= mid)
        ans += node[son[0]].query(l, mid, ql, qr);
    if(qr > mid)
        ans += node[son[1]].query(mid + 1, r, ql, qr);
    pushup();
    return ans;
}