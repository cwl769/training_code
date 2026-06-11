#include <cstdio>

int main() {
    int q = 200000;
    printf("%d\n", q);
    for(int x=2;x<=q+1;++x) {
        printf("%d ", x / 2);
    }

    return 0;
}