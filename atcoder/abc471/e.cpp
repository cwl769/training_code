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

const i64 MOD = 998244353;

i64 qpow(i64 a, i64 b) {
    i64 ans = 1;
    for(;b;b>>=1) {
        if(b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
    }
    return ans;
}

i64 jc(int n) {
    i64 ans = 1;
    for (int i = 2; i <= n; ++i)
        ans = ans * i % MOD;
    return ans;
}

i64 jc_inv(int n) {
    return qpow(jc(n), MOD - 2);
}

void solve() {
    int n, k;
    readInt(n, k);
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    if (k == 1) {
        i64 ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = (ans + a[i] * a[i]) % MOD;
        }
        printf("%lld\n", ans);
        return;
    }

    i64 chsn2k2 = jc(n - 2) * jc_inv(k - 2) % MOD * jc_inv(n - k) % MOD;
    i64 chsn1k1 = jc(n - 1) * jc_inv(k - 1) % MOD * jc_inv(n - k) % MOD;
    

    veci64 b(n + 2);
    for(int i = 1; i <= n; ++i) {
        b[i] = a[i] * chsn2k2 % MOD;
    }
    i64 sb = 0;
    for (int i = 1; i <= n; ++i)
        sb = (sb + b[i]) % MOD;
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        i64 tmp = a[i] * chsn1k1 % MOD;
        tmp = (tmp + sb + MOD - b[i]) % MOD;
        ans = (ans + a[i] * tmp) % MOD;
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