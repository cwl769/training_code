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

i64 getbit(i64 x, i64 pos) {
    return (x >> pos) & 1ll;
}

i64 func(i64 x, i64 y, i64 &ansp, i64 &ansq) {
    i64 ans = 0x3f3f3f3f3f3f3f3f;
    for (i64 i = 0; i <= 31; ++i) {
        if (getbit(x, i))
            continue;
        if ((1ll << i) < (x & y))
            continue;
        i64 p = x;
        i64 q = y;
        p |= (1ll << i);
        p &= ~((1ll << i) - 1ll);
        if (getbit(q, i)) {
            q ^= (1ll << i);
            q |= ((1ll << i) - 1ll);
        } else {
        }
        i64 tmp = std::abs(x - p) + std::abs(y - q);
        if (tmp < ans) {
            ans = tmp;
            ansp = p;
            ansq = q;
        }
    }
    return ans;
}

void solve() {
    i64 x, y;
    readInt(x, y);
    if ((x & y) == 0) {
        printf("%lld %lld\n", x, y);
        return;
    }
    i64 p1 = (x & (~y));
    i64 q1 = y;
    for (i64 i = 0; i <= 31; ++i) {
        if ((1ll << i) <= (x & y) && getbit(x | y, i) == 0) {
            p1 |= (1ll << i);
        }
    }
    i64 ans1 = std::abs(x - p1) + std::abs(y - q1);

    i64 p2 = x, q2 = y;
    i64 p3 = x, q3 = y;
    i64 ans2 = func(x, y, p2, q2);
    i64 ans3 = func(y, x, q3, p3);

    i64 minans = std::min(std::min(ans1, ans2), ans3);
    if (ans1 == minans) {
        printf("%lld %lld\n", p1, q1);
    } else if (ans2 == minans) {
        printf("%lld %lld\n", p2, q2);
    } else {
        printf("%lld %lld\n", p3, q3);
    }
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
