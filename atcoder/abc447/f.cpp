#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

typedef long long int64;

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

typedef std::vector<std::vector<int> > Graph;
typedef std::vector<int> Vec;

void dfs(int x, int faa, const Graph& g, Vec& dp, Vec& f) {
    std::vector<int> sf;
    for(auto y:g[x]) {
        if(y == faa) continue;
        dfs(y, x, g, dp, f);
        sf.push_back(f[y]);
    }
    std::sort(sf.begin(), sf.end(), std::greater<int>());
    if(sf.size() < 2u) {
        f[x] = 0;
    } else if(sf.size() == 2u) {
        f[x] = 1;
    } else {
        f[x] = sf.front() + 1;
    }

    if((faa && sf.size() >= 3u) || sf.size() >= 4u) {
        dp[x] = std::max(dp[x], sf[0] + sf[1] + 1);
    }
    if((faa && sf.size() >= 2u) || sf.size() >= 3u) {
        dp[x] = std::max(dp[x], sf[0] + 1);
    }
    if(faa && sf.size() >= 1u || sf.size() >= 2u) {
        dp[x] = std::max(dp[x], 1);
    }
}

int main() {
    int q;readInt(q);
    while(q--) {
        int n;readInt(n);
        Graph g(n+1);
        for(int i=1;i<n;++i) {
            int x, y;readInt(x, y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        Vec dp(n+1), f(n+1);
        dfs(1, 0, g, dp, f);
        int ans = 0;
        for(int i=1;i<=n;++i) {
            ans = std::max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }

    return 0;
}