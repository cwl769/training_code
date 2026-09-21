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
    int n, m;readInt(n, m);
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    i64 ans = LLONG_MIN;
    i64 sum = 0;
    std::multiset<i64, std::greater<i64> > set;
    for (int i = 1; i < m; ++i) {
        set.insert(a[i]);
        sum += a[i];
    }
    for (int i = m; i <= n; ++i) {
        i64 tmp = 1ll * m * a[i];
        tmp -= sum;
        ans = std::max(tmp, ans);
        sum += a[i];
        set.insert(a[i]);
        sum -= *set.begin();
        set.erase(set.begin());
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