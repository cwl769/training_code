#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

const i64 MOD = 998244353;

struct Limit {
    int p, v;
};

i64 pow2[110];
i64 w[110][110][10010];

void solve() {
    int n, m; scanf("%d%d", &n, &m);
    veci vm(n + 2, -1);
    std::vector<Limit> limit(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &limit[i].p, &limit[i].v);
    }
    if(m == 0) {
        printf("%lld\n", pow2[n - 1]);
        return;
    }
    if(limit[0].p == 1 && limit[0].v) {
        printf("0\n");
        return;
    }
    veci64 dp[2];
    dp[0].resize(n + 2);
    dp[1].resize(n + 2);
    veci64 *preptr = &dp[1];
    veci64 *curptr = &dp[0];
    dp[0][0] = 1;
    int lst = 1, lstv = 0;
    for (auto [p, tar] : limit) {
        if(p == lst)continue;
        int dlim = p - lst;
        std::swap(preptr, curptr);
        veci64 &pre = *preptr;
        veci64 &cur = *curptr;
        int vd_base = tar - lstv;
        for (int v = 0; v <= n; ++v) {
            if(pre[v] == 0)continue;
            i64 vd = vd_base - 1ll * dlim * v;
            for (int d = 0; d <= dlim; ++d) {
                if(0 <= vd && vd <= 10000)
                cur[v + d] = (cur[v + d] + pre[v] * w[dlim][d][vd] % MOD) % MOD;
            }
        }

        printf("[%d, %d]\n", p, tar);
        for (int i = 0; i <= n; ++i)
            printf("%lld ", cur[i]);
        printf("\n");
    }
    i64 ans = 0;
    auto &cur = *curptr;
    for (int v = 0; v <= n; ++v)
        ans = (ans + cur[0]) % MOD;
    ans = ans * pow2[n - limit.back().p] % MOD;
    printf("%lld\n", ans);
}

int main() {
    
    pow2[0] = 1;
    for (int i = 1; i < 110; ++i)
        pow2[i] = pow2[i - 1] * 2ll % MOD;
    
    w[0][0][0] = 1;
    for (int i = 1; i <= 100; ++i)
    for (int j = 1; j <= i; ++j)
    for (int s = 0; s <= 10000; ++s) {
        w[i][j][s] = w[i-1][j][s];
        if(s >= i)
            w[i][j][s] = (w[i][j][s] + w[i-1][j-1][s-i]) % MOD;
    }
    for (int i = 1; i <= 5; ++i)
    for (int j = 1; j <= i; ++j)
    for (int s = 0; s <= 30; ++s) {
        printf("w[%d][%d][%d] = %lld\n", i, j, s, w[i][j][s]);
    }
    
    int T;scanf("%d", &T);
    while(T--)
        solve();

    return 0;
}