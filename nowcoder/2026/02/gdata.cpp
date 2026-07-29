#include <cstdio>
#include <random>

std::random_device random_device;
std::mt19937 Rand(random_device());

typedef long long i64;

i64 rand(i64 l, i64 r) {
    return Rand() % (r - l + 1) + l;
}

int main() {
    int T = 100;
    printf("%d\n", T);
    while (T--) {
        int n = rand(10, 300);
        int l = rand(1, n - 1);
        int r = rand(1, n - 1);
        if (l > r)
            std::swap(l, r);
        printf("%d %d %d\n", l, r, n);
    }


    return 0;
}
