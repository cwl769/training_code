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

bool leaf[200010];
i64 sum[200010];
i64 rest[200010];
i64 dep[200010];
i64 sumrt[200010];
// i64 restrt[200010];

void dfs1(int x, int faa, const Graph& g) {
    dep[x] = dep[faa] + 1;
    veci64 vec;
    for(auto y:g[x]) {
        if(y == faa)continue;
        dfs1(y, x, g);
        sum[x] += sum[y];
        if(~rest[y])
            vec.push_back(rest[y]);
    }
    if(leaf[x])
        vec.push_back(dep[x]);
    i64 su = 0;
    for(auto x:vec) {
        su += x;
    }
    i64 mx = 0;
    for(auto x:vec) {
        mx = std::max(mx, x);
    }
    if(vec.size()&1) {
        sum[x] += su - mx - ((i64)vec.size()-1ll)*dep[x];
        rest[x] = mx;
    } else {
        sum[x] += su - (i64)vec.size() * dep[x];
    }
}

void dfs2(int x, int faa, const Graph& g, i64 sumfa, i64 restfa) {
    // printf("dfs2(%d, %d, %lld, %lld)\n", x, faa, sumfa, restfa);
    veci64 vec;
    i64 delta = -dep[x]+dep[1];
    for(auto y:g[x]) {
        if(y == faa)continue;
        sumrt[x] += sum[y];
        // printf("%d->%d\n", x, y);
        if(~rest[y])
            vec.push_back(rest[y]+delta);
    }
    if(faa)
    {
        sumrt[x] += sumfa;
        if(~restfa)
            vec.push_back(restfa);
    }
    // printf("sumrt[%d] = %lld\n", x, sumrt[x]);
    if(leaf[x])
        vec.push_back(dep[x]);
    // printf("vec[%d]\n", x);
    // for(auto x:vec)
    //     printf("%lld ", x);
    // printf("\n");
    i64 su = 0;
    for(auto x:vec) {
        su += x;
    }
    i64 mx = 0, smx = 0;
    for(auto x:vec) {
        if(x > mx) {
            smx = mx;
            mx = x;
        } else {
            smx = std::max(smx, x);
        }
    }
    if(vec.size()&1) {
        sumrt[x] += su - mx - ((i64)vec.size()-1ll)*1ll;
    } else {
        sumrt[x] += su - (i64)vec.size() * 1ll;
    }
    // printf("sumrt[%d] = %lld\n", x, sumrt[x]);
    for(auto y:g[x]) {
        if(y == faa)continue;
        i64 sumson = sumrt[x] - sum[y];
        if(rest[y]==-1) {
            dfs2(y, x, g, sumson, (vec.size()&1)?mx+1:-1);
            continue;
        }
        i64 restson = -1;
        if(vec.size()&1) {
            if(rest[y]+delta == mx) {
                dfs2(y, x, g, sumson, -1);
            } else {
                dfs2(y, x, g, sumson - (rest[y]+delta) + mx, -1);
            }
        } else {
            if(rest[y]+delta == mx) {
                sumson -= rest[y]+delta-1;
                sumson -= smx-1;
                restson = smx;
            } else {
                sumson -= rest[y]+delta-1;
                sumson -= mx-1;
                restson = mx;
            }
            dfs2(y, x, g, sumson, restson+1);
        }
    }
}

void solve() {
    int n;readInt(n);
    Graph g(n+2);
    for(int i=1;i<n;++i) {
        int x, y;readInt(x, y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;++i) {
        leaf[i] = (g[i].size() == 1u);
    }
    for(int i=1;i<=n;++i) {
        sum[i] = 0;
        rest[i] = -1;
        dep[i] = 0;
        sumrt[i] = 0;
    }

    // printf("leaf: ");
    // for(int i=1;i<=n;++i)
    //     if(leaf[i])
    //         printf("%d ", i);
    // printf("\n");

    dfs1(1, 0, g);

    // printf("sum\n");
    // for(int i=1;i<=n;++i)
    //     printf("%lld ", sum[i]);
    // printf("\n");

    // printf("rest\n");
    // for(int i=1;i<=n;++i)
    //     printf("%lld ", rest[i]);
    // printf("\n");

    // printf("dep\n");
    // for(int i=1;i<=n;++i)
    //     printf("%lld ", dep[i]);
    // printf("\n");

    dfs2(1, 0, g, 0, -1);

    // printf("sumrt\n");
    // for(int i=1;i<=n;++i)
    //     printf("%lld ", sumrt[i]);
    // printf("\n");

    i64 ans = LLONG_MAX;
    for(int i=1;i<=n;++i) {
        ans = std::min(ans, sumrt[i]);
    }
    printf("%lld\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}