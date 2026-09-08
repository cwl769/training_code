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

int log2ceil(int x) {
    --x;
    int ans = 0;
    for (;x;x>>=1)
        ++ans;
    return ans;
}

void solve() {
    int n, m;readInt(n, m);
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    veci cnt(m + 2);
    veci suf(m + 2);
    for (int i = 1; i <= n; ++i)
        ++cnt[a[i]];
    for (int i = m; i >= 1; --i)
        suf[i] = suf[i + 1] + cnt[i];
    veci64 pre(m + 2);
    for (int i = 1; i <= m; ++i)
        pre[i] = pre[i - 1] + cnt[i];
    int bd = log2ceil(m);
    for (int rnd = 1; rnd < bd; ++rnd) {
        // printf("rnd = %d\n", rnd);
        i64 ans = 0;
        for (int x = 1; x <= m; ++x) {
            i64 tmp = 0;
            i64 lim = 1ll * (1ll << rnd) * x - x;

            // for (int c = 1; c <= m; ++c) {
            //     tmp += 1ll * cnt[c] * std::min(lim / x, 1ll * c / x);
            // }

            for(i64 v = 0; ; ++v) {
                i64 l = std::max(1ll, 1ll * v * x);
                i64 r = std::min((i64)m, 1ll * v * x + x - 1ll);
                if(l > m)
                    break;
                tmp += std::min(v, lim / x) * (pre[r] - pre[l - 1]);
            }

            if(x + lim <= m)
                tmp += cnt[x + lim];
            // printf("%d %lld\n", x, tmp);
            ans = std::max(ans, tmp);
        }
        printf("%lld ", ans);
    }

    i64 sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += a[i];
    for (int i = std::max(1, bd); i <= m; ++i)
        printf("%lld ", sum);
    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}