#include <cstdio>
#include <cstring>
#include <random>

std::random_device random_device;
std::mt19937 gen(random_device());

int rand(int l, int r) {
    return gen() % (r - l + 1) + l;
}

int main() {
    int T = 1;
    printf("%d\n", T);
    while(T--) {
        int n = 200000, m = rand(1, 200000), s = rand(1, 200000);
        printf("%d %d %d\n", n, m, s);
        for(int i=1;i<=n;++i) {
            int x = rand(0, 2);
            switch (x)
            {
            case 0:
                putchar('I');
                break;
            case 1:
                putchar('E');
                break;
            case 2:
                putchar('A');
                break;
            
            default:
                break;
            }
        }
        printf("\n");
    }


    return 0;
}