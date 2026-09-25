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

bool check(i64 tar, std::map<i64, i64> map) {
    static constexpr i64 lim = (1ll << 60);
    i64 pub = 0;
    for(auto &[x, y] : map)
        y = -y;
    map[tar] = 1;
    for(i64 x = tar; x >= 0; --x) {
        i64 cnt = map[x];
        if(cnt >= lim || pub >= lim)
            return false;
        cnt += pub;
        if(x == 0) {
            if(cnt > 0)
                return false;
            continue;
        }
        if(cnt > 0) {
            pub += cnt;
            if(pub >= lim)
                return false;
        } else if(cnt < 0) {
            map[0] += cnt;
            if(map[0] >= lim)
                return false;
        }
    }
    return true;
}

void solve() {
    int n;readInt(n);
    std::map<i64, i64> map;
    i64 mx = 0;
    for(int i = 1; i <= n; ++i) {
        i64 x, y;readInt(x, y);
        mx = std::max(x, mx);
        map[x] += y;
    }
    i64 l = mx, r = mx + 60;
    while(l < r) {
        i64 mid = ((l + r + 1) >> 1);
        if(check(mid, map))
            l = mid;
        else
            r = mid - 1;
    }
    printf("%lld\n", l);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}