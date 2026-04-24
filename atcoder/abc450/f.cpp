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

const i64 MOD = 998244353;

struct Segtree {
    struct Node {
        i64 val;
        i64 tag;
        Node *son[2];
        Node():val(),tag(1),son{NULL, NULL} {}
        void update() {
            val = 0;
            if(son[0])
                val += son[0]->val;
            if(son[1])
                val += son[1]->val;
        }
        void pushdown() {
            if(!son[0])
                son[0] = new Node;
            if(!son[1])
                son[1] = new Node;
            son[0]->val = (son[0]->val * tag) % MOD;
            son[1]->val = (son[1]->val * tag) % MOD;
            son[0]->tag = (son[0]->tag * tag) % MOD;
            son[1]->tag = (son[1]->tag * tag) % MOD;
            tag = 1;
        }
        void change(int l, int  r, int x, i64 v) {
            if(l == r) {
                this->val = v;
                this->tag = 1;
                return;
            }
            this->pushdown();
            int mid = ((l+r)>>1);
            if(x <= mid)
                son[0]->change(l, mid, x, v);
            else
                son[1]->change(mid+1, r, x, v);
            this->update();
        }
        void mul(int l, int r,int ql, int qr, i64 v) {
            if(ql<=l&&r<=qr) {
                this->val = (this->val * v) % MOD;
                this->tag = (this->tag * v) % MOD;
                return;
            }
            this->pushdown();
            int mid = ((l+r)>>1);
            if(ql<=mid)
                son[0]->mul(l, mid, ql, qr, v);
            if(qr>mid)
                son[1]->mul(mid+1, r, ql, qr, v);
            this->update();
        }
        i64 query(int l, int r, int ql, int qr) {
            if(ql<=l&&r<=qr)
                return this->val;
            this->pushdown();
            int mid = ((l+r)>>1);
            i64 ans = 0;
            if(ql<=mid)
                ans = (ans + son[0]->query(l, mid, ql, qr)) % MOD;
            if(qr>mid)
                ans = (ans + son[1]->query(mid+1, r, ql, qr)) % MOD;
            this->update();
            return ans;
        }
    };
    Node *root;
    int L, R;
    Segtree(int l, int r) {
        root = new Node;
        L = l;R = r;
    }
    void change(int x, i64 v) {
        root->change(L, R, x, v);
    } 
    void mul(int l, int r, i64 v) {
        root->mul(L, R, l, r, v);
    }
    i64 sum(int l, int r) {
        return root->query(L, R, l, r);
    }
};

i64 pow2[200010];

void solve() {
    itn n, m;readInt(n, m);
    --n;
    std::vector<veci> ls(n+1);
    for(int i=1;i<=m;++i) {
        int x, y;readInt(x, y);
        --y;
        int len = y - x + 1;
        // printf("(%d %d)\n", y, len);
        ls[y].push_back(len);
    }
    Segtree dps(0, n);
    dps.change(0, 1);
    i64 ans = 0;
    for(int i=1;i<=n;++i) {
        i64 cur = 0;
        std::sort(ls[i].begin(), ls[i].end());
        for(int j=0;j<(int)ls[i].size();++j) {
            int len = ls[i][j];
            cur = (cur + pow2[j] * dps.sum(i-len, i-1)) % MOD;
        }
        dps.change(i, cur);
        for(int j=0;j<(int)ls[i].size();++j) {
            int len = ls[i][j];
            int r = i;
            int l = i - len + 1;
            if(l>=2) {
                dps.mul(0, l-2, 2);
            }
        }
        // printf("dp[%d]=%lld\n", i, cur);
        ans = cur;
    }
    printf("%lld\n", ans);
}

int main() {
    pow2[0] = 1;
    for(int i=1;i<200010;++i)
        pow2[i] = (pow2[i-1] * 2) % MOD;
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}