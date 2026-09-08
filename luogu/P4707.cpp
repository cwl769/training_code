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

const i64 MOD = 998244353;

i64 qpow(i64 a, i64 b) {
    i64 ans = 1;
    for (; b; b >>= 1) {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
    }
    return ans;
}

void solve() {
    int n, K, m;
    readInt(n, K, m);
    veci p(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(p[i]);
    K = n - K + 1;
    std::vector<veci64> dp[2];
    dp[0].resize(K + 1);
    for (int k = 0; k <= K; ++k)
        dp[0][k].resize(m + 1);
    dp[1].resize(K + 1);
    for (int k = 0; k <= K; ++k)
        dp[1][k].resize(m + 1);
    // printf("%d %d %d\n", n, K, m);
    for (int i = 1; i <= n; ++i) {
        std::vector<veci64> &cur = dp[i & 1];
        std::vector<veci64> &pre = dp[(i & 1) ^ 1];
        for (int k = 1; k <= K; ++k) {
            for (int s = 0; s <= m; ++s) {
                cur[k][s] = pre[k][s];
            }
        }

        for (int k = 1; k <= K; ++k) {
            for (int s = p[i]; s <= m; ++s) {
                // printf("cal dp[%d][%d][%d]\n", i, k, s);
                cur[k][s] = (cur[k][s] + MOD - pre[k][s - p[i]]) % MOD;
                cur[k][s] = (cur[k][s] + MOD - pre[k - 1][s - p[i]]) % MOD;
            }
        }
        cur[1][p[i]] = (cur[1][p[i]] + MOD - 1) % MOD;
        // for (int k = 1; k <= K; ++k) {
        //     for (int s = 0; s <= m; ++s) {
        //         if (cur[k][s]) {
        //             printf("dp[%d][%d][%d] = %lld\n", i, k, s, (cur[k][s] < 10000) ? cur[k][s] : cur[k][s] - MOD);
        //         }
        //     }
        // }
    }
    i64 ans = 0;
    for (int s = 1; s <= m; ++s) {
        ans = (ans + dp[n&1][K][s] * qpow(s, MOD - 2) % MOD) % MOD;
    }
    if (K & 1)
        ans = (MOD - ans) % MOD;
    ans = ans * m % MOD;
    printf("%lld\n", ans);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}
