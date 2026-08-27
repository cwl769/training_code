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
#include <queue>
#include <stack>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

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

i64 qpow(i64 a, i64 b) {
    i64 ans = 1;
    for (; b; b >>= 1) {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
    }
    return ans;
}

constexpr int jcN = 1000010;
i64 jc[jcN], jcinv[jcN];
void init() {
    jc[0] = jcinv[0] = 1;
    for (int i = 1; i < jcN; ++i)
        jc[i] = jc[i - 1] * i % MOD;
    jcinv[jcN - 1] = qpow(jc[jcN - 1], MOD - 2);
    for (int i = jcN - 2; i >= 1; --i)
        jcinv[i] = jcinv[i + 1] * (i + 1) % MOD;
}

i64 lagrange(const veci64 &f, int k, i64 xx) {
    if (xx <= k)
        return f[xx];
    veci64 pre(k + 1), suf(k + 1);
    pre[0] = suf[k] = 1;
    for (int i = 1; i <= k; ++i)
        pre[i] = (xx - (i - 1)) % MOD * pre[i - 1] % MOD;
    for (int i = k - 1; i >= 0; --i)
        suf[i] = (xx - (i + 1)) % MOD * suf[i + 1] % MOD;
    i64 ans = 0;
    for (int i = 0; i <= k; ++i) {
        i64 tmp = f[i] * pre[i] % MOD * suf[i] % MOD;
        tmp = tmp * jcinv[k - i] % MOD * jcinv[i] % MOD;
        if ((k ^ i) & 1)
            ans = (ans + MOD - tmp) % MOD;
        else
            ans = (ans + tmp) % MOD;
    }
    return ans;
}

void solve() {
    i64 n, k;
    readInt(n, k);
    ++k;
    veci64 f(k + 1);
    f[0] = 0;
    for (int x = 1; x <= k; ++x) {
        f[x] = f[x - 1] + qpow(x, k - 1);
        if (f[x] >= MOD)
            f[x] -= MOD;
    }
    // for (int i = 0; i <= k; ++i)
    //     printf("f[%d] = %lld\n", i, f[i]);
    printf("%lld\n", lagrange(f, k, n));
}

int main() {
    init();
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}
