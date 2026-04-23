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

int dfn = 0;
veci sl, sr;

void dfs(int x, Graph& g, veci& seq) {
    ++dfn;
    seq.push_back(x);
    sl[x] = sr[x] = dfn;
    for(auto y:g[x]) {
        dfs(y, g, seq);
        sl[x] = std::min(sl[x], sl[y]);
        sr[x] = std::max(sr[x], sr[y]);
    }
}

struct Query {
    int id;
    int l, r;
    i64 lim;
};

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
        if(x == 0)return;
        for(;x<N;x+=(x&(-x)))
            c[x] += v;
    }
    int get(int x) {
        if(x == 0) return 0;
        int ans = 0;
        for(;x;x-=(x&(-x)))
            ans += c[x];
        return ans;
    }
    int query(int l, int r) {
        return get(r) - get(l-1);
    }
};

void solve() {
    int n;i64 t;readInt(n, t);
    veci64 dep(n+1);
    dep[1] = 0;
    Graph g(n+1);
    for(int i=2;i<=n;++i) {
        int fa;i64 v;readInt(fa, v);
        dep[i] = dep[fa] + v;
        g[fa].push_back(i);
    }
    dfn = 0;
    sl.clear();sr.clear();
    sl.resize(n+1);
    sr.resize(n+1);
    veci seq(1);
    dfs(1, g, seq);
    std::vector<Query> query;
    for(int i=1;i<=n;++i) {
        query.push_back((Query){
            .id = i,
            .l = sl[i],
            .r = sr[i],
            .lim = dep[i] + t
        });
    }
    std::vector<std::pair<i64, int> > set;
    for(int i=1;i<=n;++i) {
        set.push_back({dep[seq[i]], i});
    }
    std::sort(set.begin(), set.end(), std::greater<std::pair<i64, int> >());
    std::sort(query.begin(), query.end(), [](Query a, Query b)->bool {
        return a.lim < b.lim;
    });
    Fenwick tree(n+1);
    std::vector<int> ans(n+1);
    for(auto [id, l, r, lim]:query) {
        while(set.size() && set.back().first <= lim) {
            tree.add(set.back().second, 1);
            set.pop_back();
        }
        ans[id] = tree.query(l, r);
    }
    for(int i=1;i<=n;++i)
        printf("%d\n", ans[i]);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}