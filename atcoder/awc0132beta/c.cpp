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
    int n, q;
    readInt(n, q);
    veci64 p(n + 2), d(n + 2);
    for (int i = 1; i <= n; ++i) {
        readInt(p[i], d[i]);
    }
    std::map<i64, int> map;
    i64 sd = 0;
    i64 last = 1e18;
    map[last] = 0;
    for (int i = 1; i <= n; ++i) {
        i64 cur = p[i] - sd;
        // printf("cur[%d] = %lld\n", i, cur);
        cur = std::min(last, cur);
        map[cur] = i;
        
        last = std::min(last, cur);
        sd += d[i];
    }

    while (q--) {
        i64 x;
        readInt(x);
        int ans = map.lower_bound(x)->second;
        printf("%d\n", ans);
    }
}

int main() {
    // int T;readInt(T);
    // while(T--) {
    //     solve();
    // }
    solve();

    return 0;
}
