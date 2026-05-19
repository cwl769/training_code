#include <cstdio>
#include <algorithm>
#include <random>

std::random_device random_device;
std::mt19937 gen(random_device());

int main() {
    int n = 200000, m=400000;
    std::uniform_int_distribution dist(0, 1000000);
    printf("%d\n", n);
    for(int i=1;i<=n;++i)
        printf("%d ", dist(gen));
    printf("\n");
    for(int i=1;i<=n;++i)
        printf("%d ", dist(gen));
    printf("\n");
    printf("%d\n", m);
    for(int i=1;i<=m;++i)
        printf("%d ", dist(gen));
    printf("\n");
    for(int i=1;i<=m;++i)
        printf("%d ", dist(gen));
    printf("\n");
    for(int i=1;i<=m;++i)
        printf("%d ", dist(gen));
    printf("\n");

    return 0;
}