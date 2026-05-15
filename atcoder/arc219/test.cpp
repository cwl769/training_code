#include <cstdio>
#include <cassert>

typedef long long i64;

const i64 MOD = 1000000007;

i64 jc[500010];

int main() {
    jc[0] = 1;
    int N = 500000;
    for(int i=1;i<=N;++i) {
        jc[i] = jc[i-1] * i % MOD;
    }
    i64 sum = 0;
    for(int n=1;n<=N;++n) {
        sum += (n-1) * jc[n-1] % MOD;
        assert((sum + 1ll) % MOD == jc[n]);
        if((n&0xff) == 0) {
            printf("ac [%d]\n", n);
        }
    }

    return 0;
}