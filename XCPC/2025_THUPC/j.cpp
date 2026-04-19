#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

typedef long long int64;

template<typename T>
void readInt(T& x) {
    bool f = 0;
    x = 0;
    char c = getchar();
    for(;c<'0'||c>'9';c=getchar()){if(c=='-')f=!f;}
    for(;'0'<=c&&c<='9';c=getchar())
        x = x * 10 + (c - '0');
    if(f)x = -x;
}

template<typename T, typename ...ARGS>
void readInt(T& x, ARGS&... args) {
    readInt(x);
    readInt(args...);
}

typedef std::vector<std::vector<int> > Graph;

struct dsu {
    int *fa;
    int N;
    dsu(int n) {
        N = n + 1;
        fa = (int*)malloc(N*sizeof(int));
        for(int i=1;i<=n;++i)
            fa[i] = i;
    }
    int get(int x) {
        if(x == fa[x])return x;
        return fa[x] = get(fa[x]);
    }
    void merge(int x, int y) {
        x = get(x);
        y = get(y);
        if(x == y)return ;
        fa[x] = y;
    }
};

void dfs(int x, int fa, Graph& g, std::vector<int>& dis, std::vector<std::vector<int> >& f) {
    // if(dis[x]==0)return;
    // if(fa==0)printf("\n");
    f[x][1] = f[x][2] = 0;
    for(auto y:g[x]) {
        if(y==fa || dis[y]==0)continue;
        dfs(y, x, g, dis, f);
        f[x][1] += std::min(std::min(f[y][0], f[y][1]), f[y][2]);
        f[x][2] += std::min(f[y][0], f[y][1]);
    }
    ++f[x][1];
    // printf("dfson %d:%d %d %d\n", x, f[x][0], f[x][1], f[x][2]);
    if(dis[x]==1) {
        std::vector<int64> tmp;
        int64 sum = 0;
        for(auto y:g[x]) {
            if(y==fa || dis[y]==0)continue;
            sum += f[y][0];
            tmp.push_back(1ll * f[y][1] - f[y][0]);
        }
        if(tmp.size() == 0u) {
            f[x][0] = 1e9;
            return;
        }
        std::sort(tmp.begin(), tmp.end());
        if(tmp[0] <= 0 ) {
            for(auto x:tmp)
                if(x<0)
                    sum += x;
            f[x][0] = sum;
        } else {
            f[x][0] = sum + tmp[0];
        }
    } else {
        f[x][0] = f[x][2];
    }
}

int main() {
    int n, k;readInt(n, k);
    std::vector<int> dis(n+1, INT_MAX);
    std::queue<int> queue;
    for(int i=1;i<=k;++i) {
        int x;readInt(x);
        dis[x] = 0;
        queue.push(x);
    }
    Graph g(n+1);
    for(int i=1;i<n;++i) {
        int x, y;readInt(x, y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    //bfs
    while(!queue.empty()) {
        int x = queue.front();queue.pop();
        // printf("x:%d\n", x);
        for(auto y:g[x]) {
            if(dis[x] + 1 < dis[y]) {
                dis[y] = dis[x] + 1;
                queue.push(y);
            }
        }
    }

    // for(int i=1;i<=n;++i) {
    //     printf("dis[%d] = %d\n", i, dis[i]);
    // }

    dsu dsu(n);
    for(int x=1;x<=n;++x)
        if(dis[x]) {
            for(auto y:g[x]) {
                if(dis[y])
                    dsu.merge(x, y);
            }
        }
    std::vector<std::vector<int> > f(n+1);
    for(int i=0;i<=n;++i)
        f[i].resize(3, 1e9);
    int ans = 0;
    for(int x=1;x<=n;++x) {
        if(dis[x] && dsu.get(x)==x) {
            dfs(x, 0, g, dis, f);
            ans += std::min(f[x][0], f[x][1]);
        }
    }
    // for(int i=1;i<=n;++i) {
    //     if(dis[i])printf("f[%d] %d %d %d\n", i, f[i][0], f[i][1], f[i][2]);
    // }
    printf("%d\n", ans);

    return 0;
}