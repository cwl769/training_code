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

constexpr i64 MOD = 998244353;

void solve() {
    int n;readInt(n);
    veci a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    int T = sqrt(n);
    std::vector<veci64> ss(T + 2);
    for (int i = 0; i <= T; ++i)
        ss[i].resize(T + 2);
    veci64 dp(n + 2);
    dp[1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int v = 1; v <= T; ++v) {
            dp[i] += ss[v][i % v];
            if(dp[i] >= MOD) dp[i] -= MOD;
        }
        if(a[i] <= T) {
            (ss[a[i]][i % a[i]] += dp[i]) %= MOD;
        } else {
            for (int j = i + a[i]; j <= n; j += a[i]) {
                dp[j] += dp[i];
                if(dp[j] >= MOD) dp[j] -= MOD;
            }
        }
    }
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dp[i];
        if(ans >= MOD) ans -= MOD;
    }
    printf("%lld\n", ans);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}