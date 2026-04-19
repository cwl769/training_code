#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

typedef long long int64;

int main() {
    int n, m, s;scanf("%d%d%d", &n, &m, &s);
    std::vector<std::vector< std::pair<int,int> > > edg(n+1);
    for(int i=1;i<=m;++i) {
        int x, y, v;scanf("%d%d%d", &x, &y, &v);
        edg[x].push_back({y, v});
    }

    std::vector<int64> dis(n+1, 0x3f3f3f3f3f3f3f3fll);
    std::vector<bool> vis(n+1);
    //0 T 未确定最短路
    //1 S 已确定最短路
    std::priority_queue<std::pair<int64, int> , std::vector<std::pair<int64, int> >, std::greater<std::pair<int64, int> > > heap;
    dis[s] = 0;
    heap.push({dis[s], s});
    for(;heap.size();) {
        int x = heap.top().second;
        heap.pop();
        if(vis[x])continue;
        vis[x] = 1;
        for(int i=0;i<edg[x].size();++i) {
            int y = edg[x][i].first;
            int w = edg[x][i].second;
            if(dis[x]+w < dis[y]) {
                dis[y] = dis[x] + w;
                heap.push({dis[y], y});
            }
        }
    }
    for(int i=1;i<=n;++i)
        printf("%lld ", dis[i]);
    printf("\n");

    return 0;
}