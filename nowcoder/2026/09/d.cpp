#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::vector<veci> Graph;

int dis[200010], siz[200010], hs[200010];
int col[200010];
int pos[200010], time[200010];
std::vector<std::pair<int, int> > peo[200010];
int ans[200010];

void dfs1(int x, int faa, const Graph& g) {
    dis[x] = dis[faa] + 1;
    siz[x] = 1;
    for(auto y : g[x]) {
        if(y == faa)
            continue;
        dfs1(y, x, g);
        siz[x] += siz[y];
        if(siz[y] > siz[hs[x]])
            hs[x] = y;
    }

}

typedef std::map<int, std::pair<int, int> > Map;

Map* dfs2(int x, int faa, const Graph& g) {
    Map *cur = new Map;
    veci del;
    for(auto [col, p] : peo[x]) {
        auto &cnt = (*cur)[col];
        ++cnt.first;
        cnt.second = p;
        if(cnt.first == 2)
            del.emplace_back(col);
    }
    // for (auto [col, pr] : *cur) {
    //     printf("[%d]%d %d %d\n", x, col, pr.first, pr.second);
    // }
    // printf("----------\n");
    for (auto y : g[x]) {
        if(y == faa)
            continue;
        auto smap = dfs2(y, x, g);
        if(cur->size() < smap->size())
            std::swap(cur, smap);
        for (auto &[col, soncnt] : (*smap)) {
            auto &cnt = (*cur)[col];
            int oricnt = cnt.first;
            cnt.first += soncnt.first;
            cnt.second = soncnt.second;
            if(oricnt < 2 && cnt.first >= 2)
                del.emplace_back(col);
        }
        delete smap;
    }
    for (auto col : del) {
        cur->erase(col);
    }
    del.clear();
    return cur;
}

int main() {
    int n, m;scanf("%d%d", &n, &m);
    Graph g(n + 2);
    for (int i = 1; i < n; ++i) {
        int x, y;scanf("%d%d", &x, &y);
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", pos+i, time+i);
    }
    dis[0] = -1;
    dfs1(1, 0, g);
    std::map<int, int> disc;
    for (int i = 1; i <= m; ++i) {
        col[i] = time[i] + dis[pos[i]];
        disc[col[i]] = 0;
    }
    int tot = 0;
    for (auto &[x, y] : disc) {
        y = ++tot;
    }

    // for(int i = 1; i <= m; ++i)
    //     printf("%d ", col[i]);
    // printf("\n");

    for (int i = 1; i <= m; ++i) {
        col[i] = disc[col[i]];
    }

    // for(int i = 1; i <= m; ++i)
    //     printf("%d ", col[i]);
    // printf("\n");

    for (int i = 1; i <= m; ++i) {
        peo[pos[i]].emplace_back(col[i], i);
    }

    auto ansmap = dfs2(1, 0, g);
    for(auto [col, pr] : *ansmap) {
        if(pr.first == 1)
            ans[pr.second] = 1;
    }
    delete ansmap;

    for(int i = 1; i <= m; ++i)
        printf("%d", ans[i]);
    printf("\n");


    return 0;
}