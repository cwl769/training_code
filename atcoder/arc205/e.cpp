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

int popcnt(int x) {
    int ans = 0;
    while(x) {
        if(x&1)
            ++ans;
        x >>= 1;
    }
    return ans;
}

void solve() {
    int n;readInt(n);
    veci a(n + 2);
    for (int i = 1; i <= n; ++i) {
        readInt(a[i]);
    }
    veci64 dp(1 << 20, 1);
    int cover = (1 << 10) - 1;
    for (int i = 1; i <= n; ++i) {
        i64 ans = 1;
        int high = (a[i] >> 10) & cover;
        int low = cover & a[i];

        // printf("[%d] %d %d\n", i, high, low);

        for (int t = 0; t <= cover; ++t) {
            if((t & high) == high) {
                int tmp = (t << 10) | low;
                dp[tmp] = dp[tmp] * a[i] % MOD;
                // printf("update|(%d) dp[%d] = %lld\n", t, tmp, dp[tmp]);
            }
        }

        for (int s = low; ; s = (s - 1) & low) {
            ans = (ans * dp[(high << 10) | s]) % MOD;
            // printf("query|(%d) dp[]")
            if(s == 0)break;
        }

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