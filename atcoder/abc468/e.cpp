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

i64 pow(i64 a, i64 b) {
    i64 ans = 1;
    for (; b; b >>= 1) {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
    }
    return ans;
}

void solve() {
    int n;
    readInt(n);
    veci64 a(n + 2);
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        readInt(a[i]);
    }

    veci64 s(n + 2), sd(n + 2);
    for (int i = 1; i <= n; ++i) {
        i64 d = std::min(i, n - i + 1);
        s[i] = (s[i - 1] + a[i]) % MOD;
        sd[i] = (sd[i-1] + a[i] * d) % MOD;
    }


    for (int w = 1; w <= n; ++w) {
        i64 d = std::min(w, n - w + 1);
        i64 tmp = 0;
        tmp = (tmp + sd[d - 1]) % MOD;
        tmp = (tmp + MOD + sd[n] - sd[n - d + 1]) % MOD;
        int l = d, r = n - d + 1;
        tmp = (tmp + (s[r] - s[l - 1] + MOD) % MOD * d % MOD) % MOD;
        ans = (ans + tmp * pow(w, MOD-2)) % MOD;
    }
    
    printf("%lld\n", ans);
}

int main() {
    //int T;readInt(T);
    //while(T--) {
        solve();
    //}

    return 0;
}
