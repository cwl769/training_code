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

std::pair<int, int> dfs1(int x, int faa, const Graph &g) {
    int mxlen = 0, mxp = x;
    for (auto y : g[x]) {
        if (y == faa)
            continue;
        auto pr = dfs1(y, x, g);
        if (pr.first + 1 > mxlen) {
            mxlen = pr.first + 1;
            mxp = pr.second;
        }
    }
    return {mxlen, mxp};
}

bool dfs2(int x, int faa, const Graph &g, veci &res, int tar) {
    res.emplace_back(x);
    if (x == tar)
        return true;
    for (auto y : g[x]) {
        if (y == faa)
            continue;
        if (dfs2(y, x, g, res, tar)) {
            return true;
        }
    }
    res.pop_back();
    return false;
}

bool dfs3(int x, int faa, const Graph &g, int tarl, int dep, veci &res) {
    // printf("dfs3 %d %d %d %d\n", x, faa, tarl, dep);
    if (tarl == 0)
        return true;
    int cnt = 0;
    for (auto y : g[x]) {
        if (y == faa)
            continue;
        if (dfs3(y, x, g, tarl - 1, dep + 1, res)) {
            ++cnt;
        }
    }
    if (cnt >= 2)
        res.emplace_back(dep);
    return cnt;
}

void solve() {
    int n;
    readInt(n);
    Graph g(n + 2);
    for (int i = 1; i < n; ++i) {
        int x, y;
        readInt(x, y);
        g[x].emplace_back(y);
        g[y].emplace_back(x);
        // printf("%d -- %d\n", x, y);
    }
    int ed0 = dfs1(1, 0, g).second;
    int ed1 = dfs1(ed0, 0, g).second;
    // printf("%d, %d\n", ed0, ed1);

    veci diam;
    dfs2(ed0, 0, g, diam, ed1);

    int diamlen = (int)diam.size() - 1;
    // printf("diamlen %d\n", diamlen);
    int a = diam[diamlen/2];
    int b = diam[diamlen / 2 + 1];
    // printf("%d, %d| %d\n", a, b, diamlen);

    veci lena;
    veci lenb;
    lena.emplace_back(diamlen / 2);
    lenb.emplace_back(diamlen / 2);
    dfs3(a, b, g, (diamlen - 1) / 2, 0, lena);
    dfs3(b, a, g, (diamlen - 1) / 2, 0, lenb);
    std::sort(lena.begin(), lena.end());
    lena.resize(std::unique(lena.begin(), lena.end()) - lena.begin());
    std::sort(lenb.begin(), lenb.end());
    lenb.resize(std::unique(lenb.begin(), lenb.end()) - lenb.begin());

    std::set<int> ans;
    for (auto x : lena) {
        for (auto y : lenb) {
            ans.insert(x + y + 1);
        }
    }
    printf("%d ", (int)ans.size());
    for (auto x : ans)
        printf("%d ", x);
    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
