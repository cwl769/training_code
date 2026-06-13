#include <cstdio>
#include <cmath>

typedef long long i64;

void solve() {
    i64 L, R;scanf("%lld%lld", &L, &R);
    i64 lim = sqrt(R);
    i64 ans = 1;
    --L;
    for(i64 d=1;d<=lim;++d) {
        if(R / d - L / d >= 2)
            ans = std::max(ans, d);
    }
    for(i64 c=2;c<=lim;++c) {
        i64 l = std::max(R / (c + 1ll) + 1, L / (c - 1ll) + 1);
        i64 r = R / c;
        if(l<=r) {
            ans = std::max(ans, r);
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }

    return 0;
}