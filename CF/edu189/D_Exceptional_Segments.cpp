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

i64 cal(i64 l, i64 r, i64 v) {
    i64 tl, tr;
    for(i64 x=l;;++x) {
        if(x % 4ll == v) {
            tl = (x - v) / 4;
            break;
        }
    }
    if(r<=4ll) {
        if(r>=v)
            tr = 0;
        else
            tr = -1;
    } else {
        for(i64 x=r;;--x) {
            if(x % 4ll == v) {
                tr = (x - v) / 4;
                break;
            }
        }
    }
    i64 ans;
    if(tl <= tr) ans = (tr - tl + 1ll) % MOD;
    else ans = 0;
    if(l==0 && v == 3)
        ++ans;
    if(ans >= MOD)
        ans -= MOD;
    return ans;
}

void solve() {
    i64 n, x;readInt(n, x);
    // printf("n, x:%lld %lld\n", n, x);
    i64 ans = 0;
    ans = (ans + cal(0, x-1, 1) * cal(x, n, 1) % MOD) % MOD;
    ans = (ans + cal(0, x-1, 3) * cal(x, n, 3) % MOD) % MOD;
    printf("%lld\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}