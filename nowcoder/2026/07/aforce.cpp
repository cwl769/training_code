#include <cstdio>
typedef long long i64;

int n;
i64 a[200010];
i64 b[200010];

bool check(int sta) {
    // printf("check %d\n", sta);
    // printf("n = %d\n", n);
    for(int i = 1; i <= n; ++i) {
        int emp = (a[i] & ~(sta));
        // printf("emp %d = %d\n", i, emp);
        b[i] = a[i];

        for(int tmp = sta; ; tmp = ((tmp-1)&sta)) {
            if(emp + tmp >= b[i-1])
                b[i] = emp + tmp;
            else
                break;

            if(tmp == 0)
                break;
        }
    }
    for(int i = 2; i <= n; ++i)
        if(b[i] < b[i-1])
            return false;
    // for(int i = 1; i <= n; ++i)
    //     printf("%lld ", b[i]);
    // printf("\n");
    return true;
}

void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%lld", a+i);
    for(int ans = 0; ans < (1 << 8); ++ans) {
        if(check(ans)) {
            printf("%d\n", ans);
            return;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }

    return 0;
}