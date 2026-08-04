#include <cstdio>
#include <algorithm>
#include <random>
typedef long long i64;
std::mt19937_64 Rand(std::random_device{}());

i64 rand(i64 l, i64 r) {
    return Rand() % (r - l + 1ll) + l;
}

int main() {
    int n = 200000, m = 200000, q = 200000;
    i64 lim = 1000000000;
    for(int i = 1; i <= n; ++i)
        printf("%lld %lld\n", rand(-lim, lim), rand(-lim, lim));
    for(int i = 1; i <= m; ++i)
        printf("%lld %lld\n", rand(-lim, lim), rand(-lim, lim));
    while(q--) {
        printf("%lld\n", rand(1, 1e18));
    }

    return 0;
}