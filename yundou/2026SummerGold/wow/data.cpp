#include <cstdio>
typedef long long i64;

int main() {
    int m = 30;
    printf("%d\n", m);
    for(i64 i = 1; i <= m; ++i) {
        printf("%lld %lld %lld %lld %lld\n", i-1, i-1, (1ll << (i-1)) - 1, 0ll, i * 13);
    }


    return 0;
}