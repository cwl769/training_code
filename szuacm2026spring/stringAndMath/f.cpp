#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

#define debug(...) fprintf(stderr, __VA_ARGS__)

template<typename T>
void readInt(T& x) {
    static bool f;
    x = 0;f = false;
    char c = getchar();
    for(;c<'0' || c>'9';c=getchar())if(c=='-')f=!f;
    for(;'0'<=c&&c<='9';c=getchar()) {
        x = x * 10 + c - '0';
    }
    if(f)x = -x;
}
template<typename T, typename ...Args>
void readInt(T& x, Args&... args) {
    readInt(x);
    readInt(args...);
}

const i64 MOD = 1000000007;

char s1[100010];

i64 trans[26][26];
i64 tmp[2][26][26];
i64 ansmat[26][26];

void mul(i64 a[][26], i64 b[][26], i64 ans[][26], int n, int k, int m) {
    for(int i=0;i<n;++i)
    for(int j=0;j<m;++j) {
        ans[i][j] = 0;
        for(int t=0;t<k;++t)
            ans[i][j] = (ans[i][j] + a[i][t] * b[t][j]) % MOD;
    }
}

void qpow(i64 a[26][26], i64 b) {
    for(int i=0;i<26;++i)
        ansmat[i][i] = 1;
    for(;b;b>>=1) {
        if(b&1) {
            //ans = ans * a;
            mul(ansmat, a, tmp[0], 26, 26, 26);
            memcpy(ansmat, tmp[0], sizeof(ansmat));
        }
        mul(a, a, tmp[0], 26, 26, 26);
        memcpy(a, tmp[0], sizeof(tmp[0]));
    }
}

void solve() {
    i64 n;readInt(n);
    scanf("%s", s1+1);
    if(n==1) {
        printf("26\n");
        return;
    }
    for(int i=0;i<26;++i) {
        for(int j=0;j<26;++j)
            trans[i][j] = 1;
    }
    int len = strlen(s1+1);
    for(int i=2;i<=len;++i) {
        int a = s1[i-1] - 'a';
        int b = s1[i] - 'a';
        trans[a][b] = 0;
    }
    memcpy(tmp[1], trans, sizeof(trans));
    // for(int i=2;i<n;++i) {
    //     mul(trans, tmp[(i&1)^1], tmp[i&1], 26, 26, 26);
    // }
    qpow(tmp[1], n-1);
    i64 ans = 0;
    for(int i=0;i<26;++i) {
        for(int j=0;j<26;++j) {
            ans = (ans + ansmat[i][j]) % MOD;
        }
    }
    printf("%lld\n", ans);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}