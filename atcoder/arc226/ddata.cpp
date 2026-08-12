#include <cstdio>

int main() {
    int q = 5000;
    printf("%d\n", q);
    for (int i = q; i >= 1; --i)
        printf("1 %d\n", i);
    for (int i = 1; i <= q; ++i)
        printf("2\n");

    return 0;
}
