#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::vector<veci> Graph;

bool squ[1000010];

void dfs1(int x, int faa, Graph &g, veci &siz) {
    for (auto y : g[x]) {
        if (y == faa)
            continue;
        dfs1(y, x, g, siz);
        siz[x] += siz[y];
    }
    ++siz[x];
}

void dfs2(int x, int faa, Graph &g, veci &siz, veci &a, const int n, i64& ans) {
    std::vector<int> son;
    for (auto y : g[x]) {
        if (y == faa)
            continue;
        son.emplace_back(siz[y]);
    }
    if (faa) {
        son.emplace_back(n - siz[x]);
    }
    int sum = 0;
    for (auto s : son) {
        if(squ[a[x]])
            ans += 1ll * sum * s * (n - sum - s);
        sum += s;
    }
    for (auto y : g[x]) {
        if (y == faa)
            continue;
        dfs2(y, x, g, siz, a, n, ans);
    }
}

void solve() {
    int n;
    scanf("%d", &n);
    veci a(n + 2);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    Graph g(n + 2);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    veci siz(n + 2);
    dfs1(1, 0, g, siz);
    i64 ans = 0;
    dfs2(1, 0, g, siz, a, n, ans);
    printf("%lld\n", ans);
}

int main() {
    for (int i = 1; i <= 1000; ++i) {
        squ[i*i] = 1;
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }

    return 0;
}
