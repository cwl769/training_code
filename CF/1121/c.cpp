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

constexpr i64 MOD = 998244353;

i64 jc[200010];
i64 inv[200010];

void init() {
    jc[0] = 1;
    for (int i = 1; i < 200010; ++i)
        jc[i] = jc[i - 1] * i % MOD;
    inv[1] = 1;
    for (int i = 2; i < 200010; ++i) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
}

void solve() {
    int n;readInt(n);
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    if(n == 1) {
        printf("0\n");
        return;
    }
    std::sort(a.begin() + 1, a.begin() + n + 1, std::greater<i64>());
    veci64 s(n + 2);
    for (int i = 1; i <= n; ++i) {
        s[i] = (s[i - 1] + a[i]) % MOD;
    }
    i64 ans = 0;
    for (int i = 2; i <= n; ++i) {
        i64 tmp = jc[n - 1] * inv[i - 1] % MOD;
        tmp = tmp * (s[i - 1] + MOD - (i - 1ll) * a[i] % MOD) % MOD;
        ans = (ans + tmp) % MOD;        
    }
    printf("%lld\n", ans);
}

int main() {
    init();
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}