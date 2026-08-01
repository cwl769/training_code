#include <cstdio>

int main() {
    int nn = 5;
    int n = (1 << nn) - 1;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int t = (i ^ j);
            //printf("%d, %d\n", i, j);
            if (t > j) {
                printf("%d %d %d\n", i, j, t);
                ++cnt;
            }
        }
    }
    printf("cnt: %d\n", cnt);


    return 0;
}
