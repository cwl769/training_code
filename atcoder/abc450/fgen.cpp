#include <cstdio>
#include <random>

std::random_device random_device;
std::mt19937 gen(random_device());

int rand(int l, int r) {
    return gen() % (r - l + 1) + l;
}

int main() {
    int n = 5, m = 3;
    printf("%d %d\n", n+1, m);
    for(int i=1;i<=m;++i) {
        int x = rand(1, n);
        int y = rand(1, n);
        if(x > y)std::swap(x, y);
        printf("%d %d\n", x, y + 1);
    }

    return 0;
}