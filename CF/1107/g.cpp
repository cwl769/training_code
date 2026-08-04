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

struct Segtree {
    struct Node {
        i64 data;
        Node *son[2];
        Node() : data(), son{NULL, NULL} {}
        void pushup() {
            data = 0;
            if (son[0])
                data = std::__gcd(data, son[0]->data);
            if (son[1])
                data = std::__gcd(data, son[1]->data);
        }
        i64 query(int l, int r, int ql, int qr) {
            // printf("query(%d, %d, %d, %d)\n", l, r, ql, qr);
            if (ql <= l && r <= qr) {
                return data;
            }
            int mid = ((l + r) >> 1);
            i64 ans = 0;
            if (ql <= mid)
                ans = std::__gcd(ans, son[0]->query(l, mid, ql, qr));
            if (qr > mid)
                ans = std::__gcd(ans, son[1]->query(mid + 1, r, ql, qr));
            return ans;
        }
        void mktree(int l, int r, i64 *arr) {
            if (l == r) {
                data = arr[l];
                return;
            }
            int mid = ((l + r) >> 1);
            son[0] = new Node;
            son[1] = new Node;
            son[0]->mktree(l, mid, arr);
            son[1]->mktree(mid + 1, r, arr);
            pushup();
        }
    };
    Node *root;
    int L, R;
    Segtree(int l, int r) : root(new Node), L(l), R(r) {}
    void mktree(i64 *arr) { root->mktree(L, R, arr); }
    i64 query(int l, int r) { return root->query(L, R, l, r); }
};

typedef __int128 i128;

void print(i128 x) {
    if (x == 0) {
        printf("0");
        return;
    }
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    std::vector<char> stack;
    for (; x; x /= 10) {
        stack.emplace_back(x % 10 + '0');
    }
    while (stack.size()) {
        putchar(stack.back());
        stack.pop_back();
    }
}

void solve() {
    int n;
    readInt(n);
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    Segtree tree(1, n);
    tree.mktree(&a[0]);
    i128 ans = 0;
    for (int i = 1; i <= n; ++i) {
        int l = i + 1;
        int r = n + 1;
        while (l < r) {
            int mid = ((l + r) >> 1);
            if (tree.query(i, mid) < a[i])
                r = mid;
            else
                l = mid + 1;
        }
        if (l == n + 1)
            continue;
        i64 cnt = n - l + 1;
        i64 val = std::min(a[l] % a[i], a[i] - a[l] % a[i]);
        ans += (i128) cnt * val;
    }
    print(ans);
    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
