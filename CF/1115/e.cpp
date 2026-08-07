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

const i64 MOD = 1000000007;

i64 pow2[100];

i64 cal(i64 n, i64 w) {
    return ((n & ((1ll << w) - 1ll)) + 1) % MOD;
}

void solve() {
    i64 n;
    readInt(n);
    i64 ans = 0;

    int nh = 60;
    while ((1ll << nh) > n)
        --nh;

    for (i64 h = 60; h >= 1; --h) {
        i64 ed = h - 1;
        i64 pre = 0;
        for (; ed >= 0; ed -= 2) {
            pre |= (1ll << ed);
            pre |= (1ll << (ed + 1));
            if (pre > n)
                break;
            if (ed == 0) {
                ++ans;
                ans %= MOD;
                break;
            }
            if (nh == h) {
                if (((n >> (ed - 1)) & 1)) {
                    ans = (ans + pow2[ed-1]) % MOD;
                } else {
                    ans = (ans + cal(n, ed-1)) % MOD;
                }
            } else {
                ans = (ans + pow2[ed-1]) % MOD;
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    pow2[0] = 1;
    for (int i = 1; i < 100; ++i)
        pow2[i] = pow2[i-1] * 2ll % MOD;
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
