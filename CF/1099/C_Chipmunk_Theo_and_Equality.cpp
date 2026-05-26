#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>
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

void func(int x, veci& disv) {
    if(x==1)return;
    while(x!=2) {
        disv.push_back(x);
        int faa = ((x&1)?(x+1):(x/2));
        x = faa;
    }
    disv.push_back(2);
}
void func2(int x, veci& disv, veci &fa, Graph& g) {
    if(x==1)return;
    while(x!=2) {
        // int dix = disc[x];
        int dix = std::lower_bound(disv.begin(), disv.end(), x) - disv.begin();
        if(fa[dix]) {
            break;
        }
        int faa = ((x&1)?(x+1):(x/2));
        int difaa = std::lower_bound(disv.begin(), disv.end(), faa) - disv.begin();
        g[difaa].push_back(dix);
        fa[dix] = difaa;
        x = faa;
    }
}

void dfs(int x, int faa, veci& dep, const Graph& g) {
    dep[x] = dep[faa] + 1;
    for(auto y:g[x]) {
        dfs(y, x, dep, g);
    }
}

void solve() {
    int n;readInt(n);
    veci a(n+2);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    
    std::vector<int> disv;
    for(int i=1;i<=n;++i) {
        if(a[i] == 1) {
            disv.push_back(2);
        } else {
            func(a[i], disv);
        }
    }
    disv.push_back(0);
    std::sort(disv.begin(), disv.end());
    disv.resize(std::unique(disv.begin(), disv.end()) - disv.begin());
    int tot = disv.size() ;
    Graph g(tot+1);
    veci fa(tot+1);
    for(int i=1;i<=n;++i) {
        if(a[i] == 1) {
        } else {
            func2(a[i], disv, fa, g);
        }
    }
    // for(int x=1;x<=tot;++x) {
    //     printf("size[%d] = %lu\n", x, g[x].size());
    // }
    veci dep(tot + 1);
    dfs(1, 0, dep, g);
    // for(int i=1;i<=tot;++i)
    //     printf("dep %d\n", dep[i]);


    veci vis(tot+1);
    int cnt1 = 0;
    for(int i=1;i<=n;++i) {
        if(a[i] == 1) {
            ++cnt1;
            vis[1] = 1;
            a[i] = -1;
        } else {
            a[i] = std::lower_bound(disv.begin(), disv.end(), a[i]) - disv.begin();
            vis[a[i]] = 1;
        }
    }

    int fin = 1;
    while(!vis[fin] && g[fin].size() == 1u) {
        fin = g[fin][0];
    }

    i64 ans = 0;
    for(int i=1;i<=n;++i) {
        if(a[i] == -1)continue;
        ans += dep[a[i]] - dep[fin];
    }

    printf("%lld\n", ans + std::min(cnt1, n-cnt1));
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}