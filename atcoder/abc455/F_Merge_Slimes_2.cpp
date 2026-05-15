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
const i64 inv2 = 499122177;

struct Segtree {
    struct Node {
        i64 sum, len, sqs, tag;
        Node *son[2];
        Node():sum(), len(), sqs(), tag(), son{NULL, NULL}{}
        void pushup(){
            sum = sqs = 0;
            if(son[0]){
                sum += son[0]->sum;
                sqs += son[0]->sqs;
            }
            if(son[1]){
                sum += son[1]->sum;
                sqs += son[1]->sqs;
            }
            sum %= MOD;
            sqs %= MOD;
        }
        void pushdown() {
            if(son[0]==NULL)
                son[0] = new Node;
            if(son[1]==NULL)
                son[1] = new Node;
            
            son[0]->sqs = (son[0]->sqs + 2ll*tag*son[0]->sum%MOD + tag*tag%MOD*son[0]->len%MOD) % MOD;
            son[0]->sum = (son[0]->sum + tag*son[0]->len) % MOD;
            son[0]->tag = (son[0]->tag + tag) % MOD;
            son[1]->sqs = (son[1]->sqs + 2ll*tag*son[1]->sum%MOD + tag*tag%MOD*son[1]->len%MOD) % MOD;
            son[1]->sum = (son[1]->sum + tag*son[1]->len) % MOD;
            son[1]->tag = (son[1]->tag + tag) % MOD;

            tag = 0;
        }
        void add(int l, int r, int ql, int qr, i64 v) {
            if(ql<=l&&r<=qr) {
                this->sqs = (this->sqs + 2ll*v*this->sum%MOD + v*v%MOD*this->len%MOD) % MOD;
                this->sum = (this->sum + v*this->len) % MOD;
                this->tag = (this->tag + v) % MOD;
                return;
            }
            pushdown();
            int mid = ((l+r)>>1);
            if(ql<=mid)
                son[0]->add(l, mid, ql, qr, v);
            if(qr>mid)
                son[1]->add(mid+1, r, ql, qr, v);
            pushup();
        }
        std::pair<i64, i64> query(int l, int r, int ql, int qr) {
            if(ql<=l&&r<=qr) {
                return {this->sum, this->sqs};
            }
            pushdown();
            int mid = ((l+r)>>1);
            i64 ans_sum = 0, ans_sqs = 0;
            if(ql<=mid) {
                auto res = son[0]->query(l, mid, ql, qr);
                ans_sum = (ans_sum + res.first) % MOD;
                ans_sqs = (ans_sqs + res.second) % MOD;
            }
            if(qr>mid) {
                auto res = son[1]->query(mid+1, r, ql, qr);
                ans_sum = (ans_sum + res.first) % MOD;
                ans_sqs = (ans_sqs + res.second) % MOD;
            }
            pushup();
            return {ans_sum, ans_sqs};
        }
        void maketree(int l, int r) {
            this->len = r - l + 1;
            if(l == r)
                return;
            int mid = ((l+r)>>1);
            this->son[0] = new Node;
            this->son[1] = new Node;
            son[0]->maketree(l, mid);
            son[1]->maketree(mid+1, r);
        }
    };

    Node *root;
    int L, R;
    Segtree(int l, int r) {
        L = l;R = r;
        root = new Node;
        root->maketree(L, R);
    }
    void add(int l, int r, i64 v) {
        root->add(L, R, l, r, v);
    }
    std::pair<i64, i64> query(int l, int r) {
        return root->query(L, R, l, r);
    }
};

void solve() {
    int n, q;readInt(n, q);
    Segtree tree(1, n);
    while(q--) {
        int l, r;i64 v;readInt(l, r, v);
        tree.add(l, r, v);
        auto res = tree.query(l, r);
        i64 sum = res.first;
        i64 sqs = res.second;
        i64 ans = sum * sum % MOD;
        ans = (ans - sqs + MOD) % MOD;
        ans = ans * inv2 % MOD;
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