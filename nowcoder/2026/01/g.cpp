#include <cstdio>
#include <cstring>

const double eps = 0.010569425;

void solve() {
    int n;
    scanf("%d", &n);
    int tot = 0;
    printf("%d\n", n*2);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            ++tot;
            if (tot <= n) {
                printf("%.9lf %.9lf %.9lf\n", i*eps, j*eps, 0.0);
                printf("%.9lf %.9lf %.9lf\n", i*eps, j*eps, 1.0);
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }


    return 0;
}
