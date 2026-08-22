#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

typedef std::vector<int> veci;
typedef std::vector<bool> vecb;
typedef std::vector<veci> Graph;

std::stack<int> stack;
int dfn_tot = 0;
int root;

void tarjan(int x, int fa, const Graph& g, Graph &dcc, veci &dfn, veci &low, vecb &cut, veci &bl) {
    dfn[x] = low[x] = ++dfn_tot;
    stack.push(x);
    if(x == root && g[x].size() == 0) {
        dcc.emplace_back();
        dcc.back().push_back(x);
        return;
    }
    int f = 0;
    for (auto y : g[x]) {
        if(!dfn[y]) {
            tarjan(y, x, g, dcc, dfn, low, cut, bl);
            low[x] = std::min(low[x], low[y]);
            if(low[y] >= dfn[x]) {
                if(++f > 1 || x != root) cut[x] = true;
                dcc.emplace_back();
                int tmp;
                do {
                    tmp = stack.top();
                    bl[tmp] = dcc.size();
                    stack.pop();
                    dcc.back().push_back(tmp);
                } while(tmp != y);
                dcc.back().push_back(x);
                bl[x] = dcc.size();
            }
        } else {
            low[x] = std::min(low[x], dfn[y]);
        }
    }
}

void solve() {
    int n, m;scanf("%d%d", &n, &m);
    Graph g(n + 2);
    veci dgr(n + 2);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].emplace_back(y);
        g[y].emplace_back(x);
        ++dgr[x];
        ++dgr[y];
    }
    while(stack.size())stack.pop();
    dfn_tot = 0;
    veci dfn(n + 2), low(n + 2), bl(n + 2);
    vecb cut(n + 2);
    Graph dcc;
    for (int i = 1; i <= n; ++i) {
        if(!dfn[i]) {
            root = i;
            tarjan(i, 0, g, dcc, dfn, low, cut, bl);
        }
    }
    veci cnt(dcc.size() + 2);
    for (int x = 1; x <= n; ++x) {
        if(cut[x]) {
            int ans = 0;
            for(auto y : g[x]) {
                ++cnt[bl[y]];
            }
            for(auto y : g[x]) {
                if(cnt[bl[y]]) {
                    ans += cnt[bl[y]] / 2;
                    cnt[bl[y]] = 0;
                }
            }
            printf("%d ", ans);
        } else {
            printf("%d ", dgr[x] / 2);
        }
    }
    printf("\n");
}

int main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}