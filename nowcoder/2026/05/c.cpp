#include <cstdio>
#include <algorithm>

int a[1000010];
int b[1000010];
int c[1000010];

int main() {
    int n;scanf("%d", &n);
    if((n & 1) || n == 2) {
        printf("-1\n");
        return 0;
    }
    int n2 = n / 2;
    for(int i = 0; i < n2; ++i) {
        a[i * 2 + 1] = i;
        a[i * 2] = n - 1 - a[i * 2 + 1];
        
        if(i + 1 < n2) {
            b[i * 2 + 1] = i + 1;
            b[i * 2] = n - 1 - b[i * 2 + 1];
        } else {
            b[i * 2] = a[0];
            b[i * 2 + 1] = a[1];
        }

        if(i + 1 == n / 4) {
            std::swap(b[i * 2], b[i * 2 + 1]);
        }
    }

    for (int i = 0; i < n; ++i) {
        int t = c[i] + b[i] + a[i];
        if (t >= n) {
            ++c[i+1];
            c[i] = t - n;
        } else {
            c[i] = t;
        }
    }
    for(int i = n - 1; i >= 0; --i)
        printf("%d ", a[i]);
    printf("\n");
    for(int i = n - 1; i >= 0; --i)
        printf("%d ", b[i]);
    printf("\n");
    for(int i = n - 1; i >= 0; --i)
        printf("%d ", c[i]);
    printf("\n");

    return 0;
}