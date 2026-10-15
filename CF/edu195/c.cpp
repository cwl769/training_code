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

void solve() {
    int n, k;readInt(n, k);
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    veci64 s(n + 2);
    for (int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; ++i)
        s[i] %= k;
    veci cnt(n + 2);
    i64 ans = 0;
    for (int r = k + 1; r <= n; ++r) {
        int lim = r - k - 1;
        ++cnt[s[lim]];
        ans += cnt[s[r]];
    }
    printf("%lld\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--)
        solve();

    return 0;
}