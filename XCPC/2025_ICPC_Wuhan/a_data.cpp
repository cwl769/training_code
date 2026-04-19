#include <cstdio>
#include <random>

std::random_device random_device;
std::mt19937_64 Rand(random_device());

int main() {
    int t = 1;
    printf("%d\n", t);
    printf("%lld %lld %lld %lld 0 1\n", Rand()%100000000+1, Rand()%100000000+1, Rand()%100000000+1, Rand()%10000+1);

    return 0;
}