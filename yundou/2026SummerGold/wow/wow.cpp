#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
typedef long long i64;
typedef std::pair<int, int> PII;

const i64 MOD = 1000000007;

i64 a[100], b[100], c[100], d[100], l[100];
i64 f[100], siz[100], sa[100], sb[100], sizmod[100];

i64 g(i64 tr, i64 s) {
    if(tr == 0)
        return 0;
    i64 ans = 0;
    if(s < siz[a[tr]]) {
        ans = g(a[tr], s);
        //ans = (ans + (dis(a[tr], s, c[tr]) + l[tr]) % MOD * sizmod[b[tr]] ) % MOD;
        ans = (ans + sb[tr]) % MOD;
    } else {
        s -= siz[a[tr]];
        ans = g(b[tr], s);
        //ans = (ans + (dis(b[tr], s, d[tr]) + l[tr]) % MOD * sizmod[a[tr]] ) % MOD;
        ans = (ans + sa[tr]) % MOD;
    }
    return ans;
}

int main() {
    freopen("wow.in", "r", stdin);
    // freopen("wow.out", "w", stdout);

    int m;scanf("%d", &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%lld%lld%lld%lld%lld", a + i, b + i, c + i, d + i, l + i);
    }
    siz[0] = 1;
    sizmod[0] = 1;
    for(int i = 1; i <= m; ++i) {
        siz[i] = siz[a[i]] + siz[b[i]];
        sizmod[i] = siz[i] % MOD;
    }
    
    

    for(int i = 1; i <= m; ++i) {
        sa[i] = g(a[i], c[i]);
        sb[i] = g(b[i], d[i]);
        f[i] = (f[a[i]] + f[b[i]]) % MOD;
        f[i] = (f[i] + l[i] * sizmod[a[i]] % MOD * sizmod[b[i]] % MOD) % MOD;
        f[i] = (f[i] + sa[i] * sizmod[b[i]] % MOD) % MOD;
        f[i] = (f[i] + sb[i] * sizmod[a[i]] % MOD) % MOD;
    }

    for(int i = 1; i <= m; ++i)
        printf("%lld\n", f[i]);


    fclose(stdin);
    fclose(stdout);
    return 0;
}