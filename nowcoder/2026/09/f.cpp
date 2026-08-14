#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long i64;

int p[500010];
int l[500010], r[500010];
i64 tl[500010], tr[500010];
i64 fl[500010], fr[500010];

i64 solve(int n){
    
    for (int i = 1; i <= n; ++i) {
        l[i] = r[i] = p[i];
        tl[i] = tr[i] = 0;
        fl[i] = fr[i] = 0;
    }

    i64 ans = 0;
    l[0] = r[0] = -1;
    for (int i = 1; i <= n; ++i) {
        i64 len = r[i] - l[i] + 1;
        while(1) {
            if(l[i] - 1 == r[i - len]) {
                // i64 tmp = std::max(fl[i], tr[i - len]) + len - 1ll + (r[i - len] - l[i - len] + 1ll);
                // ans = std::max(ans, tmp);
                i64 mid = std::max(fl[i], tr[i - len]);
                i64 prlen = r[i - len] - l[i - len] + 1ll;
                // printf("[%d] %lld %lld %lld\n", i, mid, len, prlen);
                fr[i] = std::max(std::max(mid + prlen, fr[i - len] + 1) + len - 1, std::max(mid + len, fr[i] + 1) + prlen - 1);
                fl[i] = fl[i - len];
                tl[i] = std::max(std::max(mid + prlen, tl[i - len] + 1) + len - 1, std::max(mid + len, tl[i] + 1) + prlen - 1);
                l[i] = l[i - len];
                len = r[i] - l[i] + 1;
            } else if(r[i] + 1 == l[i - len]) {
                // i64 tmp = std::max(fr[i], tl[i - len]) + len - 1ll + (r[i - len] - l[i - len] + 1ll);
                // ans = std::max(ans, tmp);
                i64 mid = std::max(fr[i], tl[i - len]);
                i64 prlen = r[i - len] - l[i - len] + 1ll;
                fr[i] = fr[i - len];
                fl[i] = std::max(std::max(mid + prlen, fl[i - len] + 1) + len - 1, std::max(mid + len, fl[i] + 1) + prlen - 1);
                tr[i] = std::max(std::max(mid + prlen, tr[i - len] + 1) + len - 1, std::max(mid + len, tr[i] + 1) + prlen - 1);
                r[i] = r[i - len];
                len = r[i] - l[i] + 1;
            } else {
                break;
            }
            ans = std::max(ans, fl[i]);
            ans = std::max(ans, fr[i]);
            ans = std::max(ans, tl[i]);
            ans = std::max(ans, tr[i]);
        }
    }

    // for(int i = 1; i <= n; ++i)
    //     printf("%d ", l[i]);
    // printf("\n");
    // for(int i = 1; i <= n; ++i)
    //     printf("%d ", r[i]);
    // printf("\n");
    // for(int i = 1; i <= n; ++i)
    //     printf("%lld ", tl[i]);
    // printf("\n");
    // for(int i = 1; i <= n; ++i)
    //     printf("%lld ", tr[i]);
    // printf("\n");
    // for(int i = 1; i <= n; ++i)
    //     printf("%lld ", fl[i]);
    // printf("\n");
    // for(int i = 1; i <= n; ++i)
    //     printf("%lld ", fr[i]);
    // printf("\n");

    i64 res = -1;

    if(l[n] > 1 || r[n] < n)
        printf("-1\n");
    else {
        printf("%lld\n", ans);
        res = ans;
    }


    return res;
}

int main() {
    // int n = 6;
    // int cnt = 1;
    // for (int i = 1; i <= n; ++i)
    //     cnt *= i;
    // while(cnt--) {
    //     for (int i = 1; i <= n; ++i) {
    //         scanf("%d", p + i);
    //     }
    //     i64 res = solve(n);
    //     i64 ans;
    //     scanf("%lld", &ans);
    //     if(ans != res) {
    //         printf("------WA------\n");
    //         for (int i = 1; i <= n; ++i) {
    //             printf("%d ", p[i]);
    //         }
    //         printf("ans: %lld res: %lld\n", ans, res);

    //         return -1;
    //     }
    // }

    int n;scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", p + i);
    solve(n);


    return 0;
}