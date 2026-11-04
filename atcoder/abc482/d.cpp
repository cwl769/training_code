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
    int n;readInt(n);
    veci64 x(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(x[i]);
    printf("%lld\n", (x[n] - x[1]) / 2ll);
    for (int i = 2; i < n; ++i) {
        i64 ansl = std::max((x[i] - x[i-1]) / 2 + (x[n] - x[i]) / 2, (x[i] - x[1]) / 2);
        i64 ansr = std::max((x[i+1] - x[i]) / 2 + (x[i] - x[1]) / 2, (x[n] - x[i]) / 2);
        printf("%lld\n", std::min(ansl, ansr));
    }
    if(n > 1)
        printf("%lld\n", (x[n] - x[1]) / 2ll);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}