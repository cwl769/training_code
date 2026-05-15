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

const i64 MOD = 1000000007;

i64 dfs(int x, int faa, const Graph& g, const veci64& a) {
    i64 ans = 1;
    bool noson = true;
    for(auto y:g[x]) {
        if(y == faa)
            continue;
        noson = false;
        ans = (ans * dfs(y, x, g, a)) % MOD;
    }
    if(noson) {
        ans = a[x];
    } else {
        ++ans;
        if(ans >= MOD)
            ans -= MOD;
        ans = (ans * a[x]) % MOD;
    }
    return ans;
}

i64 pow(i64 a, i64 b) {
    i64 ans = 1;
    for(;b;b>>=1) {
        if(b&1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
    }
    return ans;
}

i64 jc[200], jc_inv[200];

void init() {
    jc[0] = jc_inv[0] = 1;
    for(int i=1;i<200;++i) {
        jc[i] = jc[i-1] * i % MOD;
        jc_inv[i] = jc_inv[i-1] * pow(i, MOD-2) % MOD;
    }
}

void solve() {
    int n, q;readInt(n, q);
    veci64 a(n+1);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    Graph g(n+1);
    for(int i=1;i<n;++i) {
        int x, y;readInt(x, y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    veci pos;
    for(int i=1;i<=n;++i)
        if(a[i] == 0)
            pos.push_back(i);
    int tot = (int)pos.size();
    veci64 val(tot+3);
    for(int v=1;v<=tot+1;++v) {
        for(auto p:pos)
            a[p] = v;
        val[v] = dfs(1, 0, g, a);
    }
    // for(int i=1;i<=tot+1;++i)
    //     printf("[%d]%lld\n", i, val[i]);
    while(q--) {
        i64 k;readInt(k);
        veci64 pre(tot+3), suf(tot+3);
        pre[0] = 1;
        suf[tot+2] = 1;
        for(int i=1;i<=tot+1;++i)
            pre[i] = pre[i-1] * (k - i + MOD) % MOD;
        for(int i=tot+1;i>=1;--i)
            suf[i] = suf[i+1] * (k - i + MOD) % MOD;
        i64 ans = 0;
        for(int i=1;i<=tot+1;++i) {
            i64 tmp = pre[i-1] * suf[i+1] % MOD;
            tmp = tmp * jc_inv[i-1] % MOD;
            tmp = tmp * jc_inv[tot+1-i] % MOD;
            tmp = tmp * val[i] % MOD;
            if((tot+1-i)&1) {
                ans = (ans - tmp + MOD) % MOD;
            } else {
                ans = (ans + tmp ) % MOD;
            }
        }
        printf("%lld\n", ans);
    }
}

int main() {
    init();
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}