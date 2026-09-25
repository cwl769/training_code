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

veci prime;
bool pvis[200010];
void init() {
    pvis[0] = pvis[1] = 1;
    for (int x = 2; x < 200010; ++x) {
        if(!pvis[x])
            prime.emplace_back(x);
        for(auto p : prime) {
            i64 tmp = p * x;
            if(tmp >= 200010)
                break;
            pvis[tmp] = 1;
            if(x % p == 0)
                break;
        }
    }
}

void solve() {
    int n, k;readInt(n, k);
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    veci64 dp(n + 2, LLONG_MAX);
    for(int i = 1; i <= k; ++i)
        dp[i] = 0;
    std::priority_queue<std::pair<i64, int> > heap;
    for (int i = 1; i <= k; ++i)
        heap.emplace(-dp[i], i);
    veci vis(n + 2);
    while (heap.size()) {
        int x = heap.top().second;heap.pop();
        if(vis[x])
            continue;
        vis[x] = 1;
        for(auto p : prime) {
            i64 tmp = p * x;
            if(tmp > n)
                break;
            if(p * dp[x] + 1 < dp[tmp]) {
                dp[tmp] = p * dp[x] + 1;
                heap.emplace(-dp[tmp], tmp);
            }
        }
    }
    i64 ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += dp[a[i]];
    printf("%lld\n", ans);
}

int main() {
    init();
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}