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

void solve() {
    int n;
    readInt(n);
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    i64 ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += a[i];
    veci cnt(1010);
    for (int i = 1; i <= n; ++i) {
        ++cnt[a[i]];
    }

    for (int v = 1; v <= 1000; ++v) {
        if (cnt[v] > n - cnt[v]) {
            int mx = n - cnt[v] + 2;
            if (cnt[v] > mx) {
                ans -= 1ll * (cnt[v] - mx) * v;
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
