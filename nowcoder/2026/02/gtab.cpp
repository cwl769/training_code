#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cassert>

typedef std::vector<int> veci;
typedef long long i64;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

void solve(int n) {

    veci dis(n + 2, 0x3f3f3f3f);
    dis[n] = 0;
    for (int x = n - 1; x >= 1; --x) {
        if (gcd(x, n) == 1) {
            dis[x] = 1;
        } else {
            dis[x] = gcd(x, n);
            for (int y = x + 1; y < n; ++y) {
                // dis[x] = std::min(dis[x], gcd(x, y) + dis[y]);
                int tmp = gcd(x, y) + dis[y];
                if (tmp < dis[x]) {
                    dis[x] = tmp;
                }
                if (x == 2184 && tmp == 3) {
                    printf("y = %d update x = 2184 gcd = %d\n", y, gcd(x, y));
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        // printf("%d ", dis[i]);
        if (dis[i] > 2) {
            printf("n = %d, i = %d, dis[i] = %d\n", n, i, dis[i]);
        }
        //assert(dis[i] <= 2);
    }
    // printf("\n");
    printf("%d\n", gcd(2184, 2200));

    return ;
}

int main() {
    for (int n = 2200; n <= 2200; ++n) {
        //printf("[%4d]", n);
        solve(n);
    }


    return 0;
}
