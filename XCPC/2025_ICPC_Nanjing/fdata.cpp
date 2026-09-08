#include <cstdio>
#include <random>

std::mt19937 gen(std::random_device{}());

int rand(int l, int r) {
    return gen() % (r - l + 1) + l;
}

int main() {
    printf("1\n");
    int n = 1000, q = 1000000;
    printf("%d %d\n", n, q);
    for(int i = 1; i <= q; ++i) {
        if(i & 1) {
            printf("+ %d %d %d\n", rand(1, 1000), rand(1, 1000), rand(0, 4095));
        } else {
            printf("? %d %d\n", rand(1, 1000), rand(1, 1000));
        }
    }

    return 0;
}