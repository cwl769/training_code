#include <cstdio>

int a[100];

void print(int n) {
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    print(n);
    while (1) {
        int i, j;
        scanf("%d%d", &i, &j);
        a[j] = (a[j] ^ a[i]);
        print(n);
    }

    return 0;
}
