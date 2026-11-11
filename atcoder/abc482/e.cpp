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

std::pair<int, int> dfs0(int x, int faa, const Graph& g) {
    std::pair<int, int> ans = {0, x};
    for (auto y : g[x]) {
        if(y == faa)continue;
        auto tmp = dfs0(y, x, g);
        ++tmp.first;
        ans = std::max(ans, tmp);
    }
    return ans;
}

void dfs1(int x, int faa, const Graph& g, veci&dep) {
    dep[x] = dep[faa] + 1;
    for (auto y : g[x]) {
        if(y == faa)
            continue;
        dfs1(y, x, g, dep);
    }
}

void dfs2(int x, int faa, const Graph& g, veci&dep, int tar, veci& node) {
    dep[x] = dep[faa] + 1;
    // printf("[%d] %d\n", x, dep[x]);
    if(dep[x] == tar) {
        node.emplace_back(x);
    }
    for (auto y : g[x]) {
        if(y == faa)
            continue;
        dfs2(y, x, g, dep, tar, node);
    }
}

void solve() {
    int n;readInt(n);
    Graph g(n + 2);
    for (int i = 1; i < n; ++i) {
        int x, y;readInt(x, y);
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    veci col(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(col[i]);
    int a = dfs0(1, 0, g).second;
    veci dep(n + 2);
    dfs1(a, 0, g, dep);
    int dia = 0;
    for (int i = 1; i <= n; ++i)
        dia = std::max(dia, dep[i] - 1);
    
    if(dia & 1) {
        veci node0, node1;
        for (int i = 1; i <= n; ++i)
            if(dep[i] - 1 == dia)
                node0.emplace_back(i);
        int b = node0[0];
        dfs1(b, 0, g, dep);
        for (int i = 1; i <= n; ++i)
            if(dep[i] - 1 == dia)
                node1.emplace_back(i);
        veci cnt(n + 2);
        for (auto x : node0) {
            ++cnt[col[x]];
        }
        i64 ans = 0;
        for (auto x : node1) {
            ans += cnt[col[x]];
        }
        printf("%lld\n", ans);
    } else {
        int b = 0;
        for (int i = 1; i <= n; ++i)
            if(dep[i] - 1 == dia)
                b = i;
        dfs1(b, 0, g, dep);
        int rt = a;
        while(dep[rt] > dia / 2 + 1) {
            int fa = 0;
            for(auto y : g[rt])
                if(dep[y] + 1 == dep[rt])
                    fa = y;
            rt = fa;
        }

        dep[rt] = 0;
        veci cnt(n + 2);
        i64 ans = 0;
        for (auto yy : g[rt]) {
            veci node;
            dfs2(yy, rt, g, dep, dia / 2, node);
            for (auto x : node) {
                ans += cnt[col[x]];
            }
            for (auto x : node) {
                ++cnt[col[x]];
            }
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