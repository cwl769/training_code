#include <cassert>
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

const int inf = 0x3f3f3f3f;
const i64 inf64 = 0x3f3f3f3f3f3f3f3f;

struct Segtree {
    struct Node {
        int mn, mx;
        Node *son[2];
        Node() : mn(inf), mx(0), son{NULL, NULL} {}
        void pushup() {
            mn = inf;
            mx = 0;
            if (son[0]) {
                mn = std::min(mn, son[0]->mn);
                mx = std::max(mx, son[0]->mx);
            }
            if (son[1]) {
                mn = std::min(mn, son[1]->mn);
                mx = std::max(mx, son[1]->mx);
            }
        }
        void change(int l, int r, int x, int v) {
            if (l == r) {
                this->mx = this->mn = v;
                return;
            }
            int mid = ((l + r) >> 1);
            if (x <= mid)
                son[0]->change(l, mid, x, v);
            else
                son[1]->change(mid + 1, r, x, v);
            this->pushup();
        }
        void maketree(int l, int r, int *arr) {
            if (l == r) {
                mn = mx = arr[l];
                return;
            }
            int mid = ((l + r) >> 1);
            son[0] = new Node;
            son[1] = new Node;
            son[0]->maketree(l, mid, arr);
            son[1]->maketree(mid + 1, r, arr);
            this->pushup();
        }
    };

    int L, R;
    Node *root;
    Segtree(int l, int r) {
        L = l, R = r;
        root = new Node;
    }
    void maketree(int *arr) { root->maketree(L, R, arr); }
    void change(int x, int v) {
        assert(L <= x && x <= R);
        root->change(L, R, x, v);
    }
    int min() { return root->mn; }
    int max() { return root->mx; }
};

void expand(veci &a) {
    int n = a.size();
    int tar = (1 << 20);
    for (int i = 20; i >= 0; --i) {
        if ((1 << i) >= n)
            tar = (1 << i);
        else
            break;
    }
    a.resize(tar, inf);
}

int log2(int x) {
    int ans = 0;
    while (x > 1) {
        ++ans;
        x >>= 1;
    }
    return ans;
}

void solve() {
    int n, q;
    readInt(n, q);
    veci a(n);
    for (int i = 0; i < n; ++i)
        readInt(a[i]);
    expand(a);
    n = a.size();
    int lgn = log2(n);
    // printf("log2(%d) = %d\n", n, lgn);
    std::vector<std::vector<Segtree>> tree(lgn);
    veci cnt(lgn + 1);
    for (int i = 0; i < lgn; ++i) {
        int len = (1 << i);
        for (int st = 0; st + len <= n; st += len) {
            tree[i].emplace_back(st, st + len - 1);
            tree[i].back().maketree(&a[0]);
        }
        for (int j = 1; j < n / len; ++j) {
            if (tree[i][j - 1].max() > tree[i][j].min())
                ++cnt[i];
        }
    }

    auto update = [n, lgn, &tree, &a, &cnt](int p, int x) -> void {
        for (int t = 0; t < lgn; ++t) {
            int len = (1 << t);
            int bl = p / len;
            if (bl != 0) {
                if (tree[t][bl - 1].max() > tree[t][bl].min())
                    --cnt[t];
            }
            if (bl != n / len - 1) {
                if (tree[t][bl].max() > tree[t][bl + 1].min())
                    --cnt[t];
            }

            tree[t][bl].change(p, x);
            
            if (bl != 0) {
                if (tree[t][bl - 1].max() > tree[t][bl].min())
                    ++cnt[t];
            }
            if (bl != n / len - 1) {
                if (tree[t][bl].max() > tree[t][bl + 1].min())
                    ++cnt[t];
            }
        }
        a[p] = x;
    };


    for (int i = 0; i <= lgn; ++i) {
        if (cnt[i] == 0) {
            printf("%d\n", (1 << i) >> 1);
            break;
        }
    }

    while (q--) {
        int p, x;
        readInt(p, x);
        update(p, x);
        for (int i = 0; i <= lgn; ++i) {
            if (cnt[i] == 0) {
                printf("%d\n", (1 << i) >> 1);
                break;
            }
        }
    }
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
