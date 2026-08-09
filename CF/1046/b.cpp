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

i64 move(int dir, i64 k) {
    if (dir == 0) {
        printf("? R %lld\n", k);
    } else if (dir == 1) {
        printf("? U %lld\n", k);
    } else if (dir == 2) {
        printf("? L %lld\n", k);
    } else {
        printf("? D %lld\n", k);
    }
    fflush(stdout);
    i64 res;
    readInt(res);
    return res;
}

void answer(i64 x, i64 y) {
    printf("! %lld %lld\n", x, y);
    fflush(stdout);
}

const i64 T = 1000000000;

void solve() {
    int n;
    readInt(n);
    i64 mx1 = -1e18, mx2 = -1e18;
    for (int i = 1; i <= n; ++i) {
        i64 x, y;
        readInt(x, y);
        mx1 = std::max(mx1, x + y);
        mx2 = std::max(mx2, y - x);
    }

    i64 d1, d2;
    move(0, T);
    move(0, T);
    move(1, T);
    d1 = move(1, T);
    move(2, T);
    move(2, T);
    move(2, T);
    d2 = move(2, T);
    i64 a1 = mx1 + d1 - T * 4ll;
    i64 a2 = mx2 + d2 - T * 4ll;
    answer((a1 - a2) >> 1ll, (a1 + a2) >> 1ll);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
