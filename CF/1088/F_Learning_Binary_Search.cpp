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

const i64 MOD = 676767677;

#define N 2000010

i64 pow(i64 a, i64 b) {
    i64 ans = 1;
    for(;b;b>>=1) {
        if(b&1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
    }
    return ans;
}

i64 jc[N], jc_inv[N];

void init() {
    jc[0] = jc[1] = jc_inv[0] = jc_inv[1] = 1;
    for(int i=2;i<N;++i) {
        jc[i] = (jc[i-1] * i) % MOD;
        jc_inv[i] = (jc_inv[i-1] * pow(i, MOD-2)) % MOD;
    }
}

i64 choose(int n, int m) {
    return jc[n] * jc_inv[m] % MOD * jc_inv[n-m] % MOD;
}

i64 g(int n, int m) {
    return choose(m + n - 1, m - 1);
}

void cal(i64 dep, int l, int r, i64 &ans, int n, int m) {
    if(l > r) return;
    // printf("[%d]cal [%d, %d]\n", dep, l, r);
    int mid = ((l+r)>>1);
    int len = r - l + 1ll;
    int a = len / 2;
    int b = a + 1;
    i64 cnt = 0;
    if(l == 1 && r == n) {
        cnt = g(n, m);
    } else if(l == 1) {
        cnt = (g(n, m) - g(n-r+mid-1, m) + MOD) % MOD;
    } else if(r == n) {
        cnt = (g(n, m) - g(n-mid+l-1, m) + MOD) % MOD;
    } else {
        cnt = (g(n, m) - g(n-r+mid-1, m) - g(n-mid+l-1, m) + MOD + MOD + g(n-r+l-2, m)) % MOD;
    }
    printf("[%lld][%d, %d]cnt = %lld\n", dep, l, r, cnt);
    ans = (ans + cnt * dep) % MOD;
    cal(dep+1, l, mid-1, ans, n, m);
    cal(dep+1, mid+1, r, ans, n, m);
}

void solve() {
    i64 n, m;readInt(n, m);
    i64 ans = 0;
    // veci64 s(n+1), p(n+1);
    // s[0] = 0;p[0] = choose(m+n, m-1);
    // for(int t=1;t<=n;++t)
    //     s[t] = (s[t-1] + choose(m+n-t, m-1) * t) % MOD;
    // for(int t=1;t<=n;++t)
    //     p[t] = (p[t-1] + choose(m+n-t, m-1)) % MOD;
    cal(1, 1, n, ans, n, m);
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