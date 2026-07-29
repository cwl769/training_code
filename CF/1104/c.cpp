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

<<<<<<< HEAD
void solve() {
    int n;readInt(n);
    veci64 a(n+2);
    for(int i=1;i<=n;++i)
	
    
=======
const i64 inf = 0x3f3f3f3f3f3f3f3fll;

struct Segtree {
    struct Node {
        i64 mn, mnp;
        i64 tag;
        Node *son[2];
        Node() : mn(inf), mnp(0), tag(0), son{NULL, NULL} {}
        void pushup() {
            i64 mnl = inf, mnr = inf;
            i64 mnlp = 0, mnrp = 0;
            if (son[0]) {
                mnl = son[0]->mn;
                mnlp = son[0]->mnp;
            }
            if (son[1]) {
                mnr = son[1]->mn;
                mnrp = son[1]->mnp;
            }
            if (mnl <= mnr) {
                mn = mnl;
                mnp = mnlp;
            } else {
                mn = mnr;
                mnp = mnrp;
            }
        }
        void modify(i64 val) {
            mn += val;
            tag += val;
        }
        void pushdown() {
            if (son[0] == NULL)
                son[0] = new Node;
            if (son[1] == NULL)
                son[1] = new Node;
            son[0]->modify(this->tag);
            son[1]->modify(this->tag);
            tag = 0;
        }
        void change(int l, int r, int x, i64 val) {
            if (l == r) {
                this->mn = val;
                this->mnp = l;
                return;
            }
            pushdown();
            int mid = ((l + r) >> 1);
            if (x <= mid)
                son[0]->change(l, mid, x, val);
            else
                son[1]->change(mid+1, r, x, val);
            pushup();
        }
        void add(int l, int r, int ql, int qr, i64 val) {
            if (ql <= l && r <= qr) {
                modify(val);
                return;
            }
            pushdown();
            int mid = ((l + r) >> 1);
            if (ql <= mid)
                son[0]->add(l, mid, ql, qr, val);
            if (qr > mid)
                son[1]->add(mid+1, r, ql, qr, val);
            pushup();
        }
        std::pair<i64, i64> query(int l, int r, int ql, int qr) {
            if (ql <= l && r <= qr) {
                return {mn, mnp};
            }
            pushdown();
            int mid = ((l + r) >> 1);
            i64 mnl = inf, mnr = inf;
            i64 mnlp = 0, mnrp = 0;
            if (ql <= mid) {
                auto pr = query(l, mid, ql, qr);
                mnl = pr.first;
                mnlp = pr.second;
            }
            if (qr > mid) {
                auto pr = query(mid + 1, r, ql, qr);
                mnr = pr.first;
                mnrp = pr.second;
            }
            i64 ansmn, ansmnp;
            if (mnl <= mnr) {
                ansmn = mnl;
                ansmnp = mnlp;
            } else {
                ansmn = mnr;
                ansmnp = mnrp;
            }
            pushup();
            return {ansmn, ansmnp};
        }
    };
    Node *root;
    int L, R;
    Segtree(int l, int r) {
        root = new Node;
        L = l;R = r;
    }

    void change(int x, i64 val) { root->change(L, R, x, val); }
    void add(int l, int r, i64 val) {
        if(r < l)return;
        root->add(L, R, l, r, val);
    }
    std::pair<i64, i64> query(int l, int r) { return root->query(L, R, l, r); }
};

void solve() {
    int n;
    readInt(n);
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);

    i64 ans = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i + 1]) {
            a[i + 1] += a[i];
        }
    }
    printf("%lld\n", a[n]);
>>>>>>> 935d85f (2026-07-29 19:33)
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
