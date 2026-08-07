#include <cstdio>
#include <random>

std::mt19937 Rand(std::random_device{}());

int rand(int l, int r) {
    return Rand() % (r - l + 1) + l;
}

int main() {
    int T = 1;
    printf("%d\n", T);
    while(T--) {
        int n = 5;
        printf("%d\n", n);
        for(int i = 1; i <= n; ++i) {
            printf("%d ", rand(0, 7));
        }
        printf("\n");
    }


    return 0;
}