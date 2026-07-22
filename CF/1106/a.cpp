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
    int n, c;
    readInt(n, c);
    veci a(n + 2), b(n + 2);
    for (int i = 1; i <= n; ++i) {
        readInt(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        readInt(b[i]);
    }
    bool can = true;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < b[i]) {
            can = false;
        }
    }
    if (can) {
        for (int i = 1; i <= n; ++i) {
            ans += a[i] - b[i];
        }
        printf("%d\n", ans);
        return;
    }

    std::sort(b.begin() + 1, b.begin() + n + 1);
    std::sort(a.begin() + 1, a.begin() + n + 1);
    can = true;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < b[i]) {
            can = false;
        }
    }
    if (can) {
        ans = c;
        for (int i = 1; i <= n; ++i) {
            ans += a[i] - b[i];
        }
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
