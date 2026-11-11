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


int fa[300010];
int tin[300010], tout[300010], timer;
bool vis[300010];
std::vector<PII> qry[300010];
int qcnt;
int qans[1000010];

int find(int x) {
    while(fa[x] != x) {
        fa[x] = fa[fa[x]];
        x = fa[x];
    }
    return x;
}

bool isAnc(int u, int v) {
    return tin[u] <= tin[v] && tin[v] <= tout[u];
}

int addQuery(int x, int y) {
    int id = ++qcnt;
    qry[x].emplace_back(y, id);
    qry[y].emplace_back(x, id);
    return id;
}

void dfs(int x, int faa, const Graph& g) {
    tin[x] = ++timer;
    fa[x] = x;
    for (auto y : g[x]) {
        if(y == faa)continue;
        dfs(y, x, g);
        fa[y] = x;
    }
    vis[x] = true;
    for (auto& q : qry[x]) {
        if(vis[q.first])
            qans[q.second] = find(q.first);
    }
    tout[x] = timer;
}


bool onPath(int z, int x, int y, int w) {
    if(!isAnc(z, x) && !isAnc(z, y))return false;
    return isAnc(w, z);
}

void solve() {
    int n;readInt(n);
    Graph g(n + 2);
    for (int i = 1; i < n; ++i) {
        int x, y;readInt(x, y);
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    if(n % 2 == 0){
        printf("%d\n", n + 1);
        return;
    }
    timer = 0;
    qcnt = 0;
    for (int i = 1; i <= n; ++i) {
        qry[i].clear();
        vis[i] = false;
    }
    std::vector<int> idn(n + 1), idm(n + 1), id1(n + 1);
    for (int i = 1; i < n; ++i)
        idn[i] = addQuery(i, n - i);
    int mid = (n + 1) / 2;
    for (int i = 1; i <= n; ++i) {
        if(i == mid)continue;
        idm[i] = addQuery(i, n + 1 - i);
    }
    for (int i = 1; i <= n; ++i) {
        if(i == 1)continue;
        id1[i] = addQuery(i, n + 2 - i);
    }
    dfs(1, 0, g);

    int cnt, xx;
    std::vector<PII> ans;
    // n
    cnt = 0;
    xx = n;
    for (int i = 1; i < n; ++i) {
        if(onPath(xx, i, n - i, qans[idn[i]])) {
            cnt = 1;
        }
    }
    ans.emplace_back(cnt, n);
    // n + 1
    cnt = 0;
    xx = mid;
    for (int i = 1; i <= n; ++i) {
        if(i == xx)continue;
        if(onPath(xx, i, n + 1 - i, qans[idm[i]])) {
            cnt = 1;
        }
    }
    ans.emplace_back(cnt, n + 1);
    // n + 2
    cnt = 0;
    xx = 1;
    for (int i = 1; i <= n; ++i) {
        if(i == xx) continue;
        if(onPath(xx, i, n + 2 - i, qans[id1[i]])) {
            cnt = 1;
        }
    }
    ans.emplace_back(cnt, n + 2);
    std::sort(ans.begin(), ans.end());
    printf("%d\n", ans.back().second);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}