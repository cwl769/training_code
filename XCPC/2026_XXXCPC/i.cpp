#include <cstdio>
#include <cstring>
#include <vector>

typedef long long i64;
typedef unsigned long long ui64;

int mat[128][510][510];
int s[510][510];
int l[510],r[510];
int n,q;

const int MOD = 998244353;

int add(int x, int y) {
    int res = x + y;
    if (res >= MOD) res -= MOD;
    if (res < 0) res += MOD;
    return res;
}
void cal(int lv) {
    for(int j=1;j<=n;++j) {
        for(int i=1;i<=n;++i)
            s[i][j] = add(s[i-1][j], mat[lv-1][i][j]);
    }

    for(int i=1;i<=n;++i) {
        if(l[i] == 0)continue;
        for(int j=1;j<=n;++j) {
            mat[lv][i][j] = add(s[r[i]][j], -s[l[i]-1][j]);
        }
    }
}

int main() {
    scanf("%d%d", &n, &q);
    for(int i=1;i<=n;++i)
        scanf("%d%d", l+i, r+i);
    for(int i=1;i<=n;++i)
        mat[0][i][i] = 1;
    for(int i=1;i<=100;++i)
        cal(i);
    
    while(q--) {
        int s, t, d, k;scanf("%d%d%d%d", &s, &t, &d, &k);
        if(s == d || t == d) {
            printf("0\n");
            continue;
        }

        std::vector<int> dp(k + 1);
        dp[0] = 0;
        dp[1] = mat[1][s][d];

        for(int i=2;i<=k;++i) {
            dp[i] = mat[i][s][d];
            for(int t=0;t<i;++t) {
                dp[i] = (dp[i] ,-(1ll * dp[t] * mat[i-t][d][d] % MOD));
            }
        }

        int ans = mat[k][s][t];
        for(int tt=0;tt<k;++tt) {
            ans = (ans, -(1ll * dp[tt] * mat[k-tt][d][t] % MOD));
        }
        printf("%d\n", ans);
    }

    return 0;
}