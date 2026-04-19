#include <cstdio>
#include <random>

std::random_device random_device;
std::mt19937_64 Rand(random_device());

int main() {
    int n = 100000, q = 5;
    printf("%d %d\n", n, q);
    for(int i=1;i<=n;++i)
        printf("%d ", Rand() % n + 1);
    printf("\n");
    for(int i=1;i<=q;++i)
        printf("%lld\n", Rand() % (1ll*n*(n-1)/2) + 1);


    return 0;
}