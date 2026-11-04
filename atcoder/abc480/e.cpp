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
typedef long long i64;
typedef __int128_t i128;
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

bool check(i64 a, i64 d, i64 n, i64 lim) {
    i128 cur = 1;
    for (int i = 0; i < n; ++i) {
        cur *= a;
        if(cur > lim)
            return false;
        a += d;
    }
    return cur <= lim;
}

void solve() {
    i64 lim;readInt(lim);
    i64 ans = 0;
    for (i64 n = 3; n <= 19; ++n) {
        for (i64 d = 1; ; ++d) {
            if(!check(1, d, n, lim))
                break;
            i64 l = 1, r = 1e6;
            while(l < r) {
                i64 mid = ((l + r + 1) >> 1);
                if(check(mid, d, n, lim))
                    l = mid;
                else
                    r = mid - 1;
            }
            i64 a = l;
            
            // ans += a;
            // printf("n = %lld d = %lld a = %lld\n", n, d, a);

            l = d; r = 1e9;
            while(l < r) {
                i64 mid = ((l + r + 1) >> 1);
                if(check(a, mid, n, lim))
                    l = mid;
                else
                    r = mid - 1;
            }
            l = d;
            ans += a * (r - l + 1);
            d = r;
            // printf("n = %lld d = [%lld, %lld] a = %lld\n", n, l, r, a);
        }
    }
    printf("%lld\n", ans);
}

int main() {
    // int T;readInt(T);
    // while(T--)
        solve();

    return 0;
}