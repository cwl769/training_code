#include <cstdio>
#include <cstring>

int main() {
    int n = 700000;
    printf("%d\n", n);
    for (int i = 1; i <= 100000; ++i) {
        printf("0 0 1\n");
        printf("0 1 0\n");
        printf("1 0 0\n");
        printf("0 1 0\n");
        printf("1 1 0\n");
        printf("0 0 1\n");
        printf("1 0 1\n");
    }


    return 0;
}