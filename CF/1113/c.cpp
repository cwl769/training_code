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

void solve() {
    int n;
    readInt(n);
    veci a(n * 2 + 2);
    for (int i = 1; i <= n * 2; ++i)
        readInt(a[i]);
    veci64 dp(n * 2 + 2);
    veci vis(n + 2);
    for (int i = 1; i <= n * 2; ++i) {
        int v = a[i];
        if(vis[v]) {
            dp[i] = dp[vis[v]-1] + 1ll * (i - vis[v] + 1ll) * (i - vis[v] + 1ll);
            dp[i] = std::max(dp[i], dp[i-1] + 1);
        } else {
            vis[v] = i;
            dp[i] = dp[i-1] + 1;
        }
    }
    printf("%lld\n", dp[n * 2]);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
