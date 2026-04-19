#include <cstdio>

int main() {
    int n = 8000;
    printf("1\n");
    printf("%d\n", n);
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if(i <= j)
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }

    return 0;
}