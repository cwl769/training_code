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
    veci a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    veci b(n + 2);
    for (int i = 1; i <= n + 1; ++i)
        b[i] = (a[i - 1] ^ a[i]);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (b[i])
            ++ans;
    int mxd = 0;
    for (int i = 1; i < n; ++i) {
        int ori = 0;
        if (b[i])
            ++ori;
        if (b[i + 2])
            ++ori;
        int cur = 0;
        if (b[i] ^ a[i] ^ a[i + 1])
            ++cur;
        if (b[i + 2] ^ a[i] ^ a[i + 1])
            ++cur;
        mxd = std::max(mxd, cur - ori);
    }
    printf("%d\n", ans + mxd);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
