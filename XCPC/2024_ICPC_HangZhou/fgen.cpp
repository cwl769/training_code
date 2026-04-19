#include <cstdio>
#include <cstring>
#include <random>

std::random_device random_device;
std::mt19937 gen(random_device());

int main() {
    int T = 1;printf("%d\n", T);
    int n = 200000, k = 1, q = 200000;
    printf("%d %d %d\n", n, k, q);
    for(int id=1;id<=k;++id) {
        for(int i=1;i<=n;++i) {
            printf("%d ", i);
        }
        printf("\n");
    }
    for(int i=1;i<=q;++i)
        printf("%d %d %d\n", gen()%k, gen()%n, gen()%n);

    return 0;
}