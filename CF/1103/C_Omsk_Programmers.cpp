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

int func(int a, int b, int x) {
    int ans = b - a;
    int tmp = 0;
    while(b > a) {
        ++tmp;
        b /= x;
        ans = std::min(ans, tmp + std::abs(a - b));   
    }
    return ans;
}

void solve() {
    int a, b, x;readInt(a, b, x);
    if(a > b)
        std::swap(a, b);

    int ans = INT_MAX;
    for(int d=0;;a/=x,++d) {
        ans = std::min(ans, d + func(a, b, x));
        if(a == 0)
            break;
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