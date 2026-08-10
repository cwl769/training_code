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

i64 jc[1000010];
i64 inv[1000010];
i64 jc_inv[1000010];

void init() {
    jc[0] = jc_inv[0] = 1;
    jc[1] = jc_inv[1] = inv[1] = 1;
    for (int i = 2; i < 1000010; ++i) {
        // printf("calculating %d\n", i);
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
        jc[i] = jc[i - 1] * i % MOD;
        jc_inv[i] = jc_inv[i - 1] * inv[i] % MOD;
    }
    // for (int i = 0; i < 10; ++i)
    //     printf("%lld %lld %lld\n", inv[i], jc[i], jc_inv[i]);
}

i64 choose(int n, int m) {
    return jc[n] * jc_inv[n - m] % MOD * jc_inv[m] % MOD;
}

char str[1000010];

void solve() {
    int n;readInt(n);
    scanf("%s", str + 1);

    int cnt[2] = {0, 0};
    int seg[2] = {0, 0};
    int last = 1;
    for (itn i = 1; i <= n; ++i) {
        if (i == n || str[i] != str[i + 1]) {
            int len = i - last + 1;
            cnt[str[i] - '0'] += len;
            seg[str[i] - '0'] += 1;

            last = i + 1;
        }
    }

    i64 ans = 1;
    if(seg[0])
        ans = ans * choose(cnt[0] - 1, seg[0] - 1) % MOD;
    if(seg[1])
        ans = ans * choose(cnt[1] - 1, seg[1] - 1) % MOD;
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
