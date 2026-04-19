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
typedef std::vector<std::vector< int > > Graph;

const int64 M = 998244353;

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n, m;readInt(n, m);
        std::vector<int64> a(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        Graph g(n+1);
        std::vector<std::map<int64, int64> > dp(n+1);
        for(int i=1;i<=m;++i) {
            int x, y;readInt(x, y);
            g[x].push_back(y);
            ++dp[y][a[x]];
        }
        std::vector<std::pair<int64, int> > order;
        for(int i=1;i<=n;++i)
            order.push_back({a[i], i});
        std::sort(order.begin(), order.end());
        int64 ans = 0;
        for(auto ord:order) {
            int x = ord.second;
            for(auto tmp:dp[x])
                ans = (ans + tmp.second) % M;
            
            for(auto y:g[x]) {
                if(a[y]<=a[x])continue;
                auto it = dp[x].find(a[y]-a[x]);
                if(it == dp[x].end())continue;
                dp[y][a[x]] = (dp[y][a[x]] + it->second) % M;
            }
        }
        printf("%lld\n", ans);
    }


    return 0;
}