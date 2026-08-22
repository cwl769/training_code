#include <cstdio>
typedef long long i64;

int main() {
    i64 n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    i64 t = n + k - 1ll;
    i64 sum = 0;
    for (i64 rk = 1; rk <= k; ++rk) {
        sum += t + 1ll - rk;
    }
    sum *= m;
    double ans = (double)sum / (t + 1.0);
    printf("%.15lf\n", ans);


    return 0;
}