#include <cstdio>
#include <random>

std::random_device random_device;
std::mt19937 gen(random_device());

int rand(int l, int r) {
    return gen() % (r - l + 1) + l;
}

int main() {
    int T = 10;
    printf("%d\n", T);
    while(T--) {
        int n = 20;int f = rand(0, 100);
        printf("%d %d\n", n, f);
        for(int i=1;i<=n;++i) {
            int l = rand(1, 98);
            int r = rand(1, 98);
            if(l == r) ++r;
            if(l > r)std::swap(l, r);
            printf("%d %d\n", l, r);
        }
        printf("\n");
    }


    return 0;
}