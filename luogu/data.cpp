#include <cstdio>
#include <algorithm>
#include <vector>
#include <random>

std::mt19937 gen(std::random_device{}());

int rand(int l, int r) {
    return gen() % (r - l + 1) + l;
}

int main() {
    int n = 2000000;
    printf("%d\n", n);
    int mn = 1, mx = 900000000;
    for (int i = 1; i <= n; ++i) {
        int l = rand(mn, mx);
        int r = rand(mn, mx);
        if(l > r)
            std::swap(l, r);
        printf("%d %d\n", l, r);
    }


    return 0;
}