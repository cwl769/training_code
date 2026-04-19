#include <cstdio>
#include <random>

std::random_device random_device;
std::mt19937 Rand(random_device());

int main() {
    int T = 1;
    printf("%d\n", T);
    for(;T;--T) {
        int n = 2;
        int m = 50000;
        int S = n * m;
        printf("%d %d\n", n, m);
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=m;++j) {
                printf("%d ", Rand() % 100 + 1);
            }
            printf("\n");
        }
    }

    return 0;
}