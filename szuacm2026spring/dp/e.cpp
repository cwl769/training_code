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

char str[510];

bool can(int x, char c) {
    return str[x] == '?' || str[x] == c;
}

const i64 MOD = 1000000007;

i64 f[510][510];
i64 g[3][510][510];

void solve() {
    int n, K;readInt(n, K);
    scanf("%s", str+1);
    for(int i=1;i<=n;++i) {
        f[i+1][i] = 1;
    }
    for(int len=1;len<=n;++len) {
        for(int l=1;l+len-1<=n;++l) {
            int r = l + len - 1;
            for(int t=l+1;t<=r;++t) {
                if(can(l, '(') && can(t, ')')) {
                    i64 tmp = f[l+1][t-1] + g[0][l+1][t-1] + g[1][l+1][t-1] + g[2][l+1][t-1];
                    tmp %= MOD;
                    tmp = tmp * ((f[t+1][r] + g[0][t+1][r]) % MOD) % MOD;
                    // if(l==1&&r==n)
                    //     printf("t=%d tmp=%lld\n", t, tmp);
                    f[l][r] = (f[l][r] + tmp) % MOD;
                }
            }
            for(int t=l+1;t<=r&&t<=l+K;++t) {
                //[l, t-1], [t, r]
                if(can(t-1, '*')) {
                    g[0][l][r] = (g[0][l][r] + f[t][r]) % MOD;
                } else {
                    break;
                }
            }
            for(int t=r-1;t>=r-K&&t>=l;--t) {
                //[l, t], [t+1, r];
                if(can(t+1, '*')) {
                    g[1][l][r] = (g[1][l][r] + f[l][t]) % MOD;
                } else {
                    break;
                }
            }
            if(r - l + 1 <= K) {
                bool allstar = true;
                for(int i=l;i<=r;++i) {
                    if(!can(i, '*')) {
                        allstar = false;
                        break;
                    }
                }
                if(allstar)
                    g[2][l][r] = 1;
            }
        }
    }


    // for(int l=1;l<=n;++l) {
    //     for(int r=1;r<=n;++r)
    //         printf("%2lld ", f[l][r]);
    //     printf("\n");
    // }
    // printf("---------------\n");
    // for(int l=1;l<=n;++l) {
    //     for(int r=1;r<=n;++r)
    //         printf("%2lld ", g[0][l][r]);
    //     printf("\n");
    // }
    // printf("---------------\n");
    // for(int l=1;l<=n;++l) {
    //     for(int r=1;r<=n;++r)
    //         printf("%2lld ", g[1][l][r]);
    //     printf("\n");
    // }
    // printf("---------------\n");
    // for(int l=1;l<=n;++l) {
    //     for(int r=1;r<=n;++r)
    //         printf("%2lld ", g[2][l][r]);
    //     printf("\n");
    // }
    // printf("---------------\n");
    printf("%lld\n", f[1][n]);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}