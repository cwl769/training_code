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

void dfs(int x, int faa, const Graph& g, veci &col, veci &fa, veci &dep) {
    fa[x] = faa;
    dep[x] = dep[faa] + 1;
    col[x] = (col[faa] ^ 1);
    for (auto y : g[x]) {
        if(col[y] > 1)
            continue;
        dfs(y, x, g, col, fa, dep);
    }
}

void solve() {
    int n, m;readInt(n, m);
    Graph g(n + 2);
    for (int i = 1; i <= m; ++i) {
        int x, y;readInt(x, y);
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    veci col(n + 2), fa(n + 2), dep(n + 2);
    col[0] = 2;
    dfs(1, 0, g, col, fa, dep);
    for (int x = 1; x <= n; ++x) {
        for(auto y : g[x]) {
            if(col[x] == col[y]) {
                veci ans;
                veci stack;
                if(dep[x] > dep[y])
                    std::swap(x, y);
                while(dep[y] > dep[x]) {
                    stack.emplace_back(y);
                    y = fa[y];
                }
                while(x != y) {
                    ans.emplace_back(x);
                    stack.emplace_back(y);
                    x = fa[x];
                    y = fa[y];
                }
                ans.emplace_back(x);
                while(stack.size()) {
                    ans.emplace_back(stack.back());
                    stack.pop_back();
                }
                printf("%d\n", (int)ans.size());
                for (auto tt : ans)
                    printf("%d ", tt);
                printf("\n");
                return;
            }
        }
    }
    printf("-1\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
