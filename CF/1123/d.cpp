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

void solve() {
    int n;readInt(n);
    veci a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    veci ty(n + 2);
    for (int i = 1; i <= n; ++i) {
        ty[a[i]] = (i & 1);
    }
    veci dp[3];
    dp[0].resize(n + 2);
    dp[1].resize(n + 2);
    dp[2].resize(n + 2);
    if(n & 1)
        dp[1][0] = 1;
    else
        dp[2][0] = 1;
    for (int v = 1; v < n; ++v) {
        if(dp[ty[v]][v - 1]) {
            dp[2][v] = 1;
        }
        if(dp[2][v - 1]) {
            dp[!ty[v]][v] = 1;
        }
    }
    if(dp[ty[n]][n - 1])
        printf("YES\n");
    else
        printf("NO\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}