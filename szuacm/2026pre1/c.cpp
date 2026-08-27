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
#include <queue>
typedef std::vector<std::vector<std::pair<int, int> > > Graph;
const i64 inf = 0x3f3f3f3f3f3f3f3f;

void dijkstra(int st, int n, const Graph &g, veci64 &dis) {
    dis.resize(n + 2);
    for (int i = 1; i <= n; ++i)
        dis[i] = inf;
    std::priority_queue<std::pair<i64, int> > heap;
    dis[st] = 0;
    heap.emplace(0, st);
    veci vis(n + 2);
    while (heap.size()) {
        int x = heap.top().second;
        heap.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (auto [y, w] : g[x]) {
            if (dis[x] + w < dis[y]) {
                dis[y] = dis[x] + w;
                heap.emplace(-dis[y], y);
            }
        }
    }
}

void solve() {
    int n, m, s;
    readInt(n, m, s);
    Graph g(n + 2);
    for (int i = 1; i <= m; ++i) {
        int x, y, z;
        readInt(x, y, z);
        g[x].emplace_back(y, z);
        g[y].emplace_back(x, z);
    }
    i64 tar;
    readInt(tar);
    veci64 dis(n + 2);
    dijkstra(s, n, g, dis);
    int ans = 0;
    for (int x = 1; x <= n; ++x) {
        if (dis[x] == tar) {
            ++ans;
            // printf("point %d ++\n", x);
        }
        for (auto [y, w] : g[x]) {
            if (x > y)
                continue;
            i64 t2 = dis[y] + w - dis[x];
            if (t2 <= 0) {
                if (dis[y] + w > tar && dis[y] < tar)
                    ++ans;
            } else if (t2 >= w * 2ll) {
                if (dis[x] + w > tar && dis[x] < tar)
                    ++ans;
            } else {
                if (tar * 2ll == dis[x] + dis[y] + w)
                    ++ans;
                else if (dis[x] + dis[y] + w > tar * 2ll) {
                    if (dis[x] < tar)
                        ++ans;
                    if (dis[y] < tar)
                        ++ans;
                }
            }
        }
    }
    // for (int i = 1; i <= n; ++i)
    //     printf("%lld ", dis[i]);
    // printf("\n");
    printf("%d\n", ans);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}
