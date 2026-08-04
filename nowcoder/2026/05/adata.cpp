#include <cstdio>
#include <algorithm>
#include <random>

std::mt19937 Rand(std::random_device{}());

int rand(int l, int r) {
    return Rand() % (r - l + 1) + l;
}

int main() {
    int n = 200000, q = 200000;
    printf("%d %d\n", n, q);
    for(int i = 1; i <= n; ++i) {
        printf("%c", 'a' + rand(0, 25));
    }
    printf("\n");
    for(int i = 1; i <= n; ++i)
        printf("%d ", rand(0, 1000000));
    printf("\n");
    while(q--) {
        int tp = rand(1, 2);
        printf("%d ", tp);
        if (tp == 1) {
            int i = rand(1, n);
            int x = rand(0, 1000000);
            printf("%d %d\n", i, x);
        } else {
            int l = rand(1, n);
            int r = rand(1, n);
            if (l > r)
                std::swap(l, r);
            printf("%d %d\n", l, r - l + 1);
        }
    }

    return 0;
}