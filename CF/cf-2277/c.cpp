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

typedef std::vector<veci> Graph;

void dfs(int x, int faa, const Graph& g, veci &fa1, veci &son1, veci& dep) {
    dep[x] = dep[faa] + 1;
    if(x == 1) {fa1[x] = 1; son1[x] = 1;}
    if(son1[faa]) son1[x] = 1;
    for (auto y : g[x]) {
        if(y == faa)
            continue;
        dfs(y, x, g, fa1, son1, dep);
        if(fa1[y]) fa1[x] = 1;
    }
}

void solve() {
    int n, m;readInt(n, m);
    Graph g(n + 2);
    for (int i = 1; i < n; ++i) {
        int x, y;readInt(x, y);
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    veci fa1(n + 2), son1(n + 2), dep(n + 2);
    dep[0] = -1;
    dfs(n, 0, g, fa1, son1, dep);
    int ans = dep[1];
    for (int rnd = 1; rnd <= m; ++rnd) {
        int x;readInt(x);
        if(son1[x]) continue;
        ans = std::max(ans, dep[x] + 1);
    }
    printf("%d\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}