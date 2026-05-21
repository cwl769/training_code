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

int dep[200010], dfn[200010], sr[200010], seq[200010];
int dfn_tot = 0;

void dfs(int x, int faa, const Graph& g) {
    ++dfn_tot;
    dfn[x] = dfn_tot;
    seq[dfn_tot] = x;
    dep[x] = dep[faa] + 1;
    sr[x] = dfn[x];
    for(auto y:g[x]) {
        if(y == faa)
            continue;
        dfs(y, x, g);
        sr[x] = std::max(sr[x], sr[y]);
    }
}

/*
struct Fenwick {
    int *c;
    int N;
    Fenwick(int n) {
        N = n + 10;
        c = (int*)calloc(N, sizeof(int));
    }
    ~Fenwick() {
        free(c);
    }
    void add(int x, int v) {
        for(;x<N;x+=(x&(-x)))
            c[x] += v;
    }
    int get(int x) {
        if(x == 0)return 0;
        int ans = 0;
        for(;x;x-=(x&(-x)))
            ans += c[x];
    }
    int get(int l, int r) {
        return get(r) - get(l-1);
    }
};
*/

void solve() {
    int n;readInt(n);
    Graph g(n+1);
    for(int i=1;i<n;++i) {
        int x, y;readInt(x, y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int rt = 1;
    while(g[rt].size()<=1llu)++rt;
    for(int i=1;i<=n;++i) {
        dep[i] = dfn[i] = sr[i] = 0;
        dfn_tot = 0;
    }
    dfs(rt, 0, g);
    // Fenwick tree(n+1);
    std::set<int> lf;
    i64 ans = 0;
    for(int i=1;i<=n;++i) {
        if(g[i].size()<=1llu) {
            // tree.add(i, 1);
            lf.insert(dfn[i]);
            ans += dep[i];
        }
    }
    // printf("ori ans %lld\n", ans);
    std::set<std::pair<int, int> > set;
    for(int i=1;i<=n;++i) {
        set.insert({-dep[i], i});
    }
    for(auto pr:set) {
        int x = pr.second;
        if(g[x].size() == 1llu)
            continue;
        auto beg = lf.lower_bound(dfn[x]);
        auto end = lf.upper_bound(sr[x]);
        auto mxit = beg;
        int tot = 0;
        for(auto it=beg;it!=end;++it) {
            ++tot;
            if(dep[seq[*it]] > dep[seq[*mxit]]) {
                mxit = it;
            }
        }
        int mxdfn = *mxit;
        for(auto it=beg;it!=end;) {
            auto ori_it = it;
            ++it;
            lf.erase(ori_it);
            ans -= dep[x];
        }
        if(tot&1) {
            ans += dep[x];
            lf.insert(mxdfn);
        }
        // printf("[%d] %lld\n", x, ans);
    }
    if(lf.size()) {
        ans -= dep[seq[*lf.begin()]];
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