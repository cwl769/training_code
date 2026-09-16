#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
constexpr i64 MOD = 998244353;

struct Fenwick {
    int *c, N;
    Fenwick(int n) {
        N = n + 10;
        c = (int*)calloc(N, sizeof(int));
    }
    ~Fenwick() {
        free(c);
    }
    void add(int x, int v) {
        x += 5;
        for(;x < N; x += (x & (-x)))
            c[x] += v;
    }
    int query(int x) {
        x += 5;
        int ans = 0;
        for(;x;x-=(x&(-x)))
            ans += c[x];
        return ans;
    }
};

bool dfs(int x, int tot, int nolf, veci& sav, veci& lim, int cur) {
    if(x > tot)
        return true;
    if(sav[x] && sav[x] > cur)
        return false;
    if(sav[x])
        cur = std::min(cur, sav[x]);
    if(x <= nolf) {
        int ls = x * 2;
        int rs = ls + 1;
        if(!dfs(ls, tot, nolf, sav, lim, cur))
            return false;
        if(!dfs(rs, tot, nolf, sav, lim, cur))
            return false;
    } else {
        lim[x - nolf] = cur;
    }
    return true;
}

i64 solve() {
    int n, Q;scanf("%d%d", &n, &Q);
    int tot = (1 << (n + 1)) - 1;
    int nolf = (1 << n) - 1;
    veci sav(tot + 10);
    veci mxbyv((1 << n) + 10);
    veci vis((1 << n) + 10);
    while(Q--) {
        int p, x;
        scanf("%d%d", &p, &x);
        if(sav[p] && sav[p] != x)
            return 0;
        sav[p] = x;
        mxbyv[x] = std::max(mxbyv[x], p);
        vis[x] = 1;
    }
    veci ll(tot + 10), rr(tot + 10);
    ll[1] = 1;
    rr[1] = (1 << n);
    for (int i = 1; i <= nolf; ++i) {
        int mid = ((ll[i] + rr[i]) >> 1);
        int ls = i * 2;
        int rs = ls + 1;
        ll[ls] = ll[i];
        rr[ls] = mid;
        ll[rs] = mid + 1;
        rr[rs] = rr[i];
    }
    veci lim((1 << n) + 10);
    if(!dfs(1, tot, nolf, sav, lim, (1 << n)))
        return 0;
    for(int x = 1; x <= tot; ++x) {
        if(!sav[x])
            continue;
        int pl = ll[mxbyv[sav[x]]];
        int pr = rr[mxbyv[sav[x]]];
        if(!(ll[x] <= pl && pr <= rr[x]))
            return 0;
    }
    std::vector<veci> wait((1 << n) + 10);
    for (int i = (1 << n); i >= 1; --i) {
        //i is position
        wait[lim[i]].emplace_back(i);
    }
    Fenwick tree((1 << n) + 10);
    i64 ans = 1;
    for (int v = (1 << n); v >= 1; --v) {
        for(auto p : wait[v])
            tree.add(p, 1);
        int can = 0;
        if(vis[v]) {
            int l = ll[mxbyv[v]];
            int r = rr[mxbyv[v]];
            can = tree.query(r) - tree.query(l - 1);
        } else {
            can = tree.query((1 << n)) - ((1 << n) - v);
        }
        ans = ans * can % MOD;
    }
    return ans;
}

int main() {
    i64 ans = solve();
    printf("%lld\n", ans);

    return 0;
}