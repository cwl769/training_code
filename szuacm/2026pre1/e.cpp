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

struct Fenwick {
    i64 *c;
    int N;
    Fenwick(int n) {
        N = n + 10;
        c = (i64*)calloc(N, sizeof(i64));
    }
    ~Fenwick() {
        free(c);
    }
    void add(int x, i64 v) {
        for(;x < N; x += (x & (-x))) {
            c[x] += v;
        }
    }
    i64 query(int x) {
        i64 ans = 0;
        for(;x;x -= (x & (-x)))
            ans += c[x];
        return ans;
    }
    i64 sum(int l, int r) {
        if(l > r)
            return 0;
        return query(r) - query(l - 1);
    }
};

struct Ope {
    int tp;
    int v;
    i64 x;
};

typedef std::vector<veci> Graph;

std::vector<std::pair<int, i64> > opv[500010];

void dfs(int x, const int n, const Graph& g, Fenwick& tree, veci& time, veci64 &ans) {
    // printf("dfs %d\n", x);
    for(auto [ti, val] : opv[x]) {
        tree.add(ti, val);
    }
    ans[x] = tree.sum(time[x] + 1, n);
    for (auto y : g[x]) {
        dfs(y, n, g, tree, time, ans);
    }
    for(auto [ti, val] : opv[x]) {
        tree.add(ti, -val);
    }
}

void solve() {
    int n;
    readInt(n);
    std::vector<Ope> op(n + 2);
    for (int i = 1; i <= n; ++i) {
        readInt(op[i].tp, op[i].v);
        if (op[i].tp == 2)
            readInt(op[i].x);
    }
    Graph g(n + 2);
    int sz = 1;
    veci time(n + 2);
    time[1] = 0;
    for (int i = 1; i <= n; ++i) {
        if (op[i].tp == 1) {
            int cur = ++sz;
            g[op[i].v].emplace_back(cur);
            time[cur] = i;
        }
    }
    Fenwick tree(n+2);

    for (int i = 1; i <= n; ++i) {
        if (op[i].tp == 2) {
            int v = op[i].v;
            i64 x = op[i].x;
            opv[v].emplace_back(i, x);
        }
    }

    veci64 ans(sz + 2);
    dfs(1, n, g, tree, time, ans);

    for (int i = 1; i <= n; ++i) {
        if (op[i].tp == 2) {
            int v = op[i].v;
            opv[v].pop_back();
        }
    }

    for (int i = 1;  i <= sz; ++i)
        printf("%lld ", ans[i]);
    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
