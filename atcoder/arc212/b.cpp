#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <queue>
#include <map>

typedef long long int64;

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

typedef std::vector<std::vector<std::pair<int, int64> > > Graph;

void dij(int st, int n, Graph& g, std::vector<int64>& dis) {
    dis.resize(0);
    dis.resize(n+1, LLONG_MAX);
    dis[st] = 0;
    std::priority_queue<std::pair<int64, int>, std::vector<std::pair<int64, int> >, std::greater<std::pair<int64, int> > > heap;
    heap.push({dis[st], st});
    std::vector<bool> vis(n+1);
    while(heap.size()) {
        int x = heap.top().second;heap.pop();
        if(vis[x])continue;
        vis[x] = 1;
        for(auto e:g[x]) {
            int y = e.first;
            int64 v = e.second;
            if(dis[x] + v < dis[y]) {
                dis[y] = dis[x] + v;
                heap.push({dis[y], y});
            }
        }
    }
}

int main() {
    int n, m;readInt(n, m);
    Graph g(n+1);
    int x0, y0;int64 ans;
    readInt(x0, y0, ans);
    for(int i=2;i<=m;++i) {
        int x, y;int64 val;
        readInt(x, y, val);
        g[x].push_back({y, val});
    }
    std::vector<int64> dis;
    dij(y0, n, g, dis);
    if(dis[x0] == LLONG_MAX)
        printf("-1");
    else
        printf("%lld\n", dis[x0]+ans);

    return 0;
}