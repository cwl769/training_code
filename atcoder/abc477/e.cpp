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

typedef std::vector<std::vector<std::pair<int, i64> > > Graph;

void dij(int s, const int n, const Graph&g, veci64 &dis) {
    for (int i = 1; i <= n + 1; ++i)
        dis[i] = 0x3f3f3f3f3f3f3f3fll;
    dis[s] = 0;
    std::priority_queue<std::pair<i64, int> > heap;
    heap.emplace(-dis[s], s);
    veci vis(n + 2);
    while(heap.size()) {
        int x = heap.top().second;heap.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for (auto [y, w] : g[x]) {
            if(dis[x] + w < dis[y]) {
                dis[y] = dis[x] + w;
                heap.emplace(-dis[y], y);
            }
        }
    }
}

void solve() {
    int n, Q;readInt(n, Q);
    veci64 a(n + 2), b(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    for (int i = 1; i <= n; ++i)
        readInt(b[i]);
    Graph g(n + 2);
    for (int i = 1; i <= n; ++i) {
        int x = i, y = i % n + 1, w = a[i];
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
    }
    for (int i = 1; i <= n; ++i) {
        int x = i, y = n + 1, w = b[i];
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
    }
    veci64 dis(n + 2);
    dij(n + 1, n, g, dis);
    veci64 sa(n + 2);
    for (int i = 1; i <= n; ++i)
        sa[i] = sa[i - 1] + a[i];
    while(Q--) {
        int s, t;readInt(s, t);
        if(t == n + 1) {
            printf("%lld\n", dis[s]);
        } else {
            i64 ans = dis[s] + dis[t];
            i64 tmp = sa[t - 1] - sa[s - 1];
            ans = std::min(ans, std::min(tmp, sa[n] - tmp));
            printf("%lld\n", ans);
        }
    }
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}