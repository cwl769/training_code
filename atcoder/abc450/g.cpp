#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

typedef long long int64;
typedef long long i64;
typedef std::vector<i64> veci64;
typedef std::vector<int> veci;

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

const i64 MOD = 998244353;

i64 pow(i64 a, i64 b) {
    i64 ans = 1;
    for(;b;b>>=1) {
        if(b & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
    }
    return ans;
}

int main() {
    int n;readInt(n);
    veci64 a(n+1);
    for(int i=1;i<=n;++i) {
        readInt(a[i]);
    }
    if(n == 1) {
        printf("%lld\n", a[1] * a[1] % MOD);
        return 0;
    }
    
    veci64 kk(n+1);
    if(n>=2)
        kk[2] = MOD - 2;
    if(n>=3)
        kk[3] = MOD - pow(3, MOD-2) * 2;
    for(int i=4;i<=n;++i) {
        i64 tmp = ((kk[i-1] * (i-2) % MOD * (i-3) - 4) % MOD + MOD) % MOD;
        tmp = tmp * pow(i, MOD - 2) % MOD;
        tmp = tmp * pow(i-1, MOD - 2) % MOD;
        kk[i] = tmp;
    }
    // printf("%lld %lld %lld\n", kk[4], kk[5], MOD - 4*pow(9, MOD-2)%MOD);
    
    i64 k = kk[n] * pow(2, MOD - 2) % MOD;

    i64 ans = 0;
    for(int i=1;i<=n;++i) {
        ans = (ans + a[i] * a[i]) % MOD;
    }
    i64 sum = 0;
    for(int i=1;i<=n;++i)
        sum = (sum + a[i]) % MOD;
    for(int i=1;i<=n;++i) {
        i64 tmp = a[i] * ((sum - a[i]) % MOD + MOD) % MOD;
        ans = (ans + tmp * k) % MOD;
    }
    printf("%lld\n", ans);

    return 0;
}