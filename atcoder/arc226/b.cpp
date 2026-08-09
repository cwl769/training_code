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

bool check(i64 w, i64 n, i64 m, veci64 a) {
    i64 rest = w / (1ll << m);
    rest *= n;
    for (int i = m - 1; i >= 0; --i) {
        rest <<= 1;
        if ((w >> i) & 1)
            rest += n;
        if (rest < a[i]) {
            return false;
        } else {
            rest -= a[i];
        }
    }
    return true;
}

void solve() {
    int n, m;
    readInt(n, m);
    veci64 a(m);
    for (int i = 0; i < m; ++i)
        readInt(a[i]);
    i64 l = 0, r = 4e18 / n + 1;
    while (l < r) {
        i64 mid = ((l + r) >> 1);
        if (check(mid, n, m, a))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%lld\n", l);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }
    // solve();

    return 0;
}
