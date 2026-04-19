#include <cstdio>
#include <cstdlib>
#include <random>

std::random_device random_device;

int main() {
    srand(random_device());
    int T = 1;
    printf("%d\n", T);
    for(;T;--T) {
        int n = 10;
        printf("%d\n", n);
        for(int i=1;i<=n;++i) {
            printf("%d ", rand() % n + 1);
        }
        printf("\n");
    }

    return 0;
}