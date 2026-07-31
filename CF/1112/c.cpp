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

int l[5010], r[5010], u[5010], v[5010];

void solve() {
    int n;
    readInt(n);
    for (int i = 1; i <= n; ++i)
        readInt(l[i], r[i], u[i], v[i]);
    int ans = 0;
    for (int m = 1; m <= n; ++m) {
        int cur = 1;
        for (int i = 1; i <= n; ++i) {
            if (!(l[i] <= cur && cur <= r[i]) &&
                !(m - v[i] + 1 <= cur && cur <= m - u[i] + 1)) {
                ++cur;
            }
        }
        if (cur > m)
            ans = std::max(ans, m);
    }
    printf("%d\n", ans);
    
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
