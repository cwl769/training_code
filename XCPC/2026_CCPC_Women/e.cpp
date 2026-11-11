#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

void solve() {
    int n;scanf("%d", &n);
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    i64 sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += a[i];
    int Q;scanf("%d", &Q);
    while(Q--) {
        i64 tar;scanf("%lld", &tar);
        tar += sum;
        if(tar < 0) {
            printf("NO\n");
            continue;
        }
        // printf("tar: %lld\n", tar);
        veci c(n + 2);
        for (int i = n; i >= 1; --i) {
            if(a[i] + a[i] <= tar) {
                tar -= a[i] + a[i];
                c[i] = 1;
            } else if(a[i] <= tar) {
                tar -= a[i];
                c[i] = 0;
            } else {
                c[i] = -1;
            }
        }
        if(tar) {
            printf("NO\n");
        } else {
            printf("YES\n");
            for (int i = 1; i <= n; ++i)
                printf("%d ", c[i]);
            printf("\n");
        }
    }
}

int main() {
    int T;scanf("%d", &T);
    while(T--)
        solve();

    return 0;
}