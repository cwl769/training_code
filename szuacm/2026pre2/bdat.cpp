#include <cstdio>
#include <cstring>
#include <random>

std::mt19937_64 gen(std::random_device{}());

int rand(int l, int r) { return gen() % (r - l + 1) + l; }


int main() {
    int n = 5;
    printf("%d\n", n);
    while (n--) {
        int len = rand(5, 10);
        for (int i = 1; i <= len; ++i)
            putchar(rand('a', 'z'));
        putchar('\n');
    }

    return 0;
}
