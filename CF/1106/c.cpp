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

typedef std::vector<veci> Graph;

int dfs(int x, int faa, const Graph &g, i64 &ans) {
    veci vec;
    for (auto y : g[x]) {
        if (y == faa)
            continue;
        vec.push_back(dfs(y, x, g, ans));
    }
    int mx = 0, smx = 0;
    for (auto val : vec) {
        if (val > mx) {
            smx = mx;
            mx = val;
        } else if (val > smx) {
            smx = val;
        }
    }
    ans += smx + 1;
    return mx + 1;
}

void solve() {
    int n;
    readInt(n);
    Graph g(n + 2);
    for (int i = 2; i <= n; ++i) {
        int fa;
        readInt(fa);
        g[fa].push_back(i);
        g[i].push_back(fa);
    }
    i64 ans = 0;
    dfs(1, 0, g, ans);
    printf("%lld\n", ans);
    
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
