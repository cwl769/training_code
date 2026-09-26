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

struct Segtree {
    struct Node {
        int cnt[2];
        int tag;
        Node *son[2];
        Node():cnt{0, 0}, tag(), son{NULL, NULL} {}
        void pushup() {
            cnt[0] = cnt[1] = 0;
            if(son[0] != NULL){
                cnt[0] += son[0]->cnt[0];
                cnt[1] += son[0]->cnt[1];
            }
            if(son[1] != NULL){
                cnt[0] += son[1]->cnt[0];
                cnt[1] += son[1]->cnt[1];
            }
        }
        void pushdown() {
            if(son[0] == NULL)
                son[0] = new Node;
            if(son[1] == NULL)
                son[1] = new Node;
            if(tag == 0)return;
            std::swap(son[0]->cnt[0], son[0]->cnt[1]);
            std::swap(son[1]->cnt[0], son[1]->cnt[1]);
            son[0]->tag ^= 1;
            son[1]->tag ^= 1;
            tag = 0;
        }
        void add(int l, int r, int x, int p) {
            if(l == r) {
                ++cnt[p];
                return;
            }
            pushdown();
            int mid = ((l + r) >> 1);
            if(x <= mid)
                son[0]->add(l, mid, x, p);
            else
                son[1]->add(mid + 1, r, x, p);
            pushup();
        }
        void rev(int l, int r, int ql, int qr) {
            if(ql <= l && r <= qr) {
                tag ^= 1;
                std::swap(cnt[0], cnt[1]);
                return;
            }
            pushdown();
            int mid = ((l + r) >> 1);
            if(ql <= mid)
                son[0]->rev(l, mid, ql, qr);
            if(qr > mid)
                son[1]->rev(mid+1, r, ql, qr);
            pushup();
        }
        std::pair<int, int> query(int l, int r, int ql, int qr) {
            if(ql <= l && r <= qr) {
                return {cnt[0], cnt[1]};
            }
            pushdown();
            int mid = ((l + r) >> 1);
            int ans[2] = {0, 0};
            if(ql <= mid) {
                auto pr = son[0]->query(l, mid, ql, qr);
                ans[0] += pr.first;
                ans[1] += pr.second;
            }
            if(qr > mid) {
                auto pr = son[1]->query(mid + 1, r, ql, qr);
                ans[0] += pr.first;
                ans[1] += pr.second;
            }
            pushup();
            return {ans[0], ans[1]};
        }
    };

    Node *root;
    int L, R;
    Segtree(int l, int r) {
        root = new Node;
        L = l; R = r;
    }
    void add(int x, int p) {
        root->add(L, R, x, p);
    }
    void rev(int l, int r) {
        root->rev(L, R, l, r);
    }
    auto query(int l, int r) {
        return root->query(L, R, l, r);
    }
    i64 queryMul(int l, int r) {
        auto pr = query(l, r);
        return 1ll * pr.first * pr.second;
    }
};

char str[200010];

void solve() {
    int n, q;readInt(n, q);
    scanf("%s", str + 1);
    veci a(n + 2);
    for (int i = 1; i < n; ++i) {
        if(str[i] != str[i + 1])
            a[i] = 1;
    }
    --n;
    i64 sum = 0;
    Segtree ss(0, n);
    for (int i = 0; i <= n; ++i)
        ss.add(i, 0);
    for (int i = 1; i <= n; ++i) {
        if(a[i]) {
            sum += 1ll * i * (n - i + 1ll);
            ss.rev(i, n);
        }
    }

    // printf("{%lld, %lld}", sum, ss.queryMul(0, n));
    printf("%lld ", (sum + ss.queryMul(0, n)) >> 1);

    auto rev = [&a, &ss, &sum, n](int p) -> void {
        if(p < 1 || p > n)
            return;
        if(a[p]) {
            sum -= 1ll * p * (n - p + 1ll);
        } else{
            sum += 1ll * p * (n - p + 1ll);
        }
        ss.rev(p, n);
        a[p] ^= 1;
    };

    while(q--) {
        int p;readInt(p);
        rev(p);rev(p-1);
        // printf("{%lld, %lld}", sum, ss.queryMul(0, n));
        printf("%lld ", (sum + ss.queryMul(0, n)) >> 1);
    }
    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}