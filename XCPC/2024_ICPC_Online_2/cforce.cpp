#include <cstdio>
typedef long long i64;

int str[300010];
i64 a[300010], b[300010];

i64 suma(int x, const int n) {
    i64 ans = 0;
    for (int i = x, j = 1; i <= n; ++i, ++j) {
        if(str[i] == str[j]) {
            ans += a[i];
        } else {
            break;
        }
    }
    return ans;
}

int main() {
    int n;scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%lld%lld", str + i, a + i, b + i);
        i64 ans = 0;
        for (int t = 1; t <= i; ++t) {
            ans += b[t] * suma(t, i);
        }
        printf("%lld\n", ans);
    }

    return 0;
}