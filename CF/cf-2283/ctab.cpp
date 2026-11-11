#include <cstdio>

int main() {
    int tmp = 0;
    for (int x = 1; x <= 64; ++x) {
        tmp |= x;
        printf("[%2d] %2d\n", x, tmp);
    }
    for (int x = 1; x <= 64; ++x) {
        printf("[%2d] %2d\n", x, x^(x<<1));
    }
    tmp = 0;
    for (int x = 1; x <= 64; ++x) {
        tmp ^= x;
        printf("[%2d] %2d\n", x, tmp);
    }

    return 0;
}