#include <cstdio>
#include <random>

std::random_device random_device;
std::mt19937 gen(random_device());

char str[] = "()?*";

int main() {
    int n = 10, k = 3;
    printf("%d %d\n", n, k);
    putchar((gen()%2)?'?':'(');
    for(int i=2;i<=n-1;++i) {
        putchar(str[gen()%4]);
    }
    putchar((gen()%2)?'?':')');
    putchar('\n');


    return 0;
}