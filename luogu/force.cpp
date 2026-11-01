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

i64 qpow(i64 a, i64 b) {
    i64 ans = 1;
    for(;b;b>>=1) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
    }
    return ans;
}

i64 inv(i64 a) {
    return qpow(a, MOD - 2);
}

int a[2010];
int b[2010];

void dfs(int i, const int n, veci64& ll, veci64& rr, i64 &ans) {
    if(i > n) {
        for (int i = 1; i <= n; ++i) {
            if(a[i] != a[i - 1])
                b[i] = 1;
            else
                b[i] = b[i - 1] + 1;
        }
        for (int i = 1; i <= n; ++i) {
            ans = (ans + b[i] + b[i] - 1) % MOD;
        }
        return;
    }
    for (int c = ll[i]; c <= rr[i]; ++c) {
        a[i] = c;
        dfs(i + 1, n, ll, rr, ans);
    }
}

void solve() {
    itn n;readInt(n);
    veci64 ll(n + 2), rr(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(ll[i], rr[i]);
    veci64 leninv(n + 2);
    for (int i = 1; i <= n; ++i)
        leninv[i] = inv(rr[i] - ll[i] + 1);
    i64 pp = 1;
    for (int i = 1; i <= n; ++i)
        pp = pp * leninv[i] % MOD;
    i64 ans = 0;
    dfs(1, n, ll, rr, ans);
    printf("%lld\n", ans);
    ans = ans * pp % MOD;
    printf("%lld\n", ans);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}