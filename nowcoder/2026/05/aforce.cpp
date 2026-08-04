#include <cstdio>
#include <algorithm>
typedef long long i64;

int n, q;
char str[1010];
i64 a[1010];

i64 h(int l, int len) {
    i64 ans = 0;
    for(int i = 1; i + len - 1 <= n; ++i) {
        bool eq = true;
        for(int j = 0; j < len; ++j) {
            if(str[i + j] != str[l + j]) {
                eq = false;
                break;
            }
        }
        if(eq)
            ans += a[i];
    }
    return ans;
}

int main() {scanf("%d%d", &n, &q);
    scanf("%s", str+1);
    for(int i = 1; i <= n; ++i)
        scanf("%lld", a + i);
    while(q--) {
        int tp;scanf("%d", &tp);
        if(tp == 1) {
            int i, x;scanf("%d%d", &i, &x);
            a[i] = x;
        } else if(tp == 2) {
            int p, m;scanf("%d%d", &p, &m);
            i64 ans = 0;
            for(int len = 1; len <= m; ++len)
                ans += h(p, len);
            printf("%lld\n", ans);
        }
    }


    return 0;
}