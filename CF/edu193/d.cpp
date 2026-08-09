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
    i64 x, y;
    readInt(x, y);
    i64 k = 0;
    while (((k * k + k) >> 1ll) <= x + y)
        ++k;
    --k;
    i64 sum = (k * k + k) / 2;

    i64 val = 0;
    if (x + sum - y < 0)
        val = 0;
    else
        val = (x + sum - y) / 2;
    // printf("%lld %lld %lld %lld\n", sum, x, y, val);
    
    i64 cur = 0;
    veci64 ans(k + 2);
    for (i64 t = k; t >= 1; --t) {
        if (cur + t < val) {
            ++ans[k - t + 1];
            cur += t;
        } else {
            i64 nd = val - cur;
            ++ans[k - nd + 1];
            break;
        }
    }
    for (int i = 1; i <= k; ++i) {
        if (ans[i])
            printf("X");
        else
            printf("Y");
    }
    printf("\n");
    
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
