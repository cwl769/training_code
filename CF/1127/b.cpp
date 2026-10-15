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
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    veci64 mns(n + 2, LLONG_MAX), mxs(n + 2, LLONG_MIN);
    mns[1] = mxs[1] = a[1];
    i64 ans = a[1];
    for (int i = 2; i <= n; ++i) {
        i64 curmx = std::max(a[i] + mxs[i - 1], a[i] - mns[i - 1]);
        curmx = std::max(curmx, a[i]);
        i64 curmn = std::min(a[i] - mxs[i - 1], a[i] + mns[i - 1]);
        curmn = std::min(curmn, a[i]);

        // printf("i = %d: [%lld, %lld]\n", i, curmn, curmx);

        ans = std::max(ans, curmx);
        
        mxs[i] = std::max(mxs[i], mxs[i - 1] + a[i]);
        mxs[i] = std::max(mxs[i], mxs[i - 1] + a[i] + mxs[i - 1]);
        mxs[i] = std::max(mxs[i], a[i]);
        mns[i] = std::min(mns[i], mns[i - 1] + a[i]);
        mns[i] = std::min(mns[i], mns[i - 1] + a[i] + mns[i - 1]);
        mns[i] = std::min(mns[i], a[i]);
    }

    // for (int i = 1; i <= n; ++i)
    //     printf("%3lld ", mxs[i]);
    // printf("\n");
    // for (int i = 1; i <= n; ++i)
    //     printf("%3lld ", mns[i]);
    // printf("\n");

    printf("%lld\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}