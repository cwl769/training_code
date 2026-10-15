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

constexpr int inf = 0x3f3f3f3f;

struct Segtree {
    struct Node {
        int mn;
        Node *son[2];
        Node():mn(inf), son{NULL, NULL} {}
        void pushup() {
            mn = inf;
            if(son[0] != NULL)
                mn = std::min(mn, son[0]->mn);
            if(son[1] != NULL)
                mn = std::min(mn, son[1]->mn);
        }
        void change(int l, int r, int x, int v) {
            // printf("change [%d, %d] %d %d\n", l, r, x, v);
            if(l == r) {
                mn = std::min(mn, v);
                return;
            }
            int mid = ((l + r) >> 1);
            if(x <= mid) {
                if(son[0] == NULL)  son[0] = new Node;
                son[0]->change(l, mid, x, v);
            } else {
                if(son[1] == NULL)  son[1] = new Node;
                son[1]->change(mid + 1, r, x, v);
            }
            pushup();
            // printf("now [%d, %d] mn = %d\n", l, r, mn);
        }
        int query(int l, int r, int ql, int qr) const {
            if(ql <= l && r <= qr)
                return mn;
            int ans = inf;
            int mid = ((l + r) >> 1);
            if(ql <= mid && son[0] != NULL) {
                ans = std::min(ans, son[0]->query(l, mid, ql, qr)); 
            }
            if(qr > mid && son[1] != NULL) {
                ans = std::min(ans, son[1]->query(mid + 1, r, ql, qr));
            }
            return ans;
        }
    };

    Node *root;
    int L, R;
    Segtree(int l, int r) {
        root = new Node;
        L = l;R = r;
    }
    void change(int x, int v) {
        // printf("tree change(%d, %d)\n", x, v);
        root->change(L, R, x, v);
    }
    int min(int l, int r) {
        if(l > r)
            return inf;
        return root->query(L, R, l, r);
    }
};

void solve() {
    int n;readInt(n);
    veci a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    Segtree tree(1, n);
    veci dm(n + 2), dc(n + 2), nxt(n + 2);
    for (int x = n; x >= 1; --x) {
        tree.change(a[x], x);
        int y = tree.min(a[x] + 1, n);
        // printf("[%d] query(%d, %d) y = %d\n", x, a[x] + 1, n, y);
        if(y > n)
            continue;
        ++dc[y];
        dm[y] = x;
        nxt[x] = y;
    }

    // for (int i = 1; i <= n; ++i)
    //     printf("%d ", dm[i]);
    // printf("\n");
    // for (int i = 1; i <= n; ++i)
    //     printf("%d ", dc[i]);
    // printf("\n");

    veci64 dp(n + 2);
    veci cnt(n + 2);
    for (int x = 1; x <= n; ++x) {
        if(dc[x] == 0)
            continue;
        dp[x] = 2ll * (x - dm[x]) - dc[x];
        cnt[x] = x - dm[x];
        dp[x] += dp[dm[x]] + 1ll * cnt[dm[x]];
        cnt[x] += cnt[dm[x]];
    }

    // for (int i = 1; i <= n; ++i)
    //     printf("%lld ", dp[i]);
    // printf("\n");
    // for (int i = 1; i <= n; ++i)
    //     printf("%d ", cnt[i]);
    // printf("\n");

    i64 ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += dp[i];
    for (int i = 1; i <= n; ++i)
        ans += i - 1;

    std::map<int, i64> map;
    map[n + 1] = 0;
    map[0] = 0;

    i64 tmp = 0;
    auto change = [&map, &tmp](int x, i64 v)-> void {
        if(map.find(x) != map.end()) {
            auto it = map.find(x);
            --it;
            i64 len = x - (it->first) - 1;
            if(len > 0)
                tmp += (v - map[x]) * len;
            map[x] = v;
            return;
        }
        auto it = map.upper_bound(x);
        int nn = it->first;
        i64 val = it->second;
        
        while(it->first >= x)
            --it;
        int pp = it->first;
        tmp -= 1ll * (x - pp) * val;
        tmp += 1ll * (x - pp - 1) * val;
    };

    for (int x = 1; x <= n; ++x) {
        change(x, 0);
        if(nxt[x])
            change(nxt[x], 2);
        ans += tmp;
    }

    printf("%lld\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}