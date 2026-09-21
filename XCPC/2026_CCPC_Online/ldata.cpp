#include <cstdio>
typedef long long i64;

int main() {
    i64 n = 10000000000;
    int m = 100000;

    printf("%lld %d\n", n, m);
    for(int i = 1; i <= m; ++i)
        printf("%d %d\n", i * 2, i * 2);


    return 0;
}