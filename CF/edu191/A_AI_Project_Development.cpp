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

bool check(i64 m ,i64 n, i64 x, i64 y, i64 z) {
    if(x * m + y * m >= n)
        return true;
    if(m >= z && x * m + 10ll * y * (m - z) >= n)
        return true;
    return false;
}

void solve() {
    int n, x, y, z;readInt(n, x, y, z);
    int l = 1, r = 100000;
    while(l < r) {
        int mid = ((l+r)>>1);
        if(check(mid, n, x, y, z)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", l);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}