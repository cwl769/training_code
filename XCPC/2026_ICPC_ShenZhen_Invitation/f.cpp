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

int n, k;

int getsg(int x, int faa, const Graph& g, Graph& sg);
void dfs(int x, int faa, int cnt, int cur, veci& ans, const Graph& g, Graph& sg);

int getsg(int x, int faa, const Graph& g, Graph& sg) {
    int id = std::lower_bound(g[x].begin(), g[x].end(), faa) - g[x].begin();
    if(~sg[x][id])return sg[x][id];
    veci vec;
    dfs(x, faa, 1, 0, vec, g, sg);
    std::sort(vec.begin(), vec.end());
    vec.resize(std::unique(vec.begin(), vec.end()) - vec.begin());
    int mex = 0;
    for(int x:vec) {
        if(x == mex) {
            ++mex;
        } else {
            break;
        }
    }
    return sg[x][id] = mex;
}

void dfs(int x, int faa, int cnt, int cur, veci& ans, const Graph& g, Graph& sg) {
    if(cnt > k)return;
    for(auto y:g[x]) {
        if(y == faa)continue;
        cur ^= getsg(y, x, g, sg);
    }
    ans.push_back(cur);
    for(auto y:g[x]) {
        if(y == faa)continue;
        int ysg = getsg(y, x, g, sg);
        dfs(y, x, cnt+1, cur^ysg, ans, g, sg);
    }
}

void solve() {
    readInt(n, k);
    Graph g(n+2);
    for(int i=1;i<n;++i) {
        int x, y;readInt(x, y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    Graph sg(n+2);
    for(int x=1;x<=n;++x) {
        std::sort(g[x].begin(), g[x].end());
        sg[x].resize(g[x].size(), -1);
    }
    for(int rt=1;rt<=n;++rt) {
        int ans = 0;
        for(auto x:g[rt]) {
            ans ^= getsg(x, rt, g, sg);
        }
        if(ans)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}