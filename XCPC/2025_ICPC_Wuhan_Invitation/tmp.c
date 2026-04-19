#include <stdio.h>

int main() {
    int i = 5, k;
    k = (++i) + (++i) + (i++);
    // printf("%d %d\n", k, i);

    return 0;
}