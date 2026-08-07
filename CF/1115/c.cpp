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
    int n, m;
    readInt(n, m);
    veci64 v(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(v[i]);
    std::vector<veci64> map(n + 2);
    for (int i = 1; i <= n; ++i) {
        map[i].resize(m + 2);
        for (int j = 1; j <= m; ++j)
            readInt(map[i][j]);
    }
    int ans = m;
    std::multiset<i64, std::greater<i64> > set;
    for (int i = n; i >= 1; --i) {
        // printf("calculating [%d]\n", i);
        for (int j = 1; j <= m; ++j)
            set.emplace(map[i][j]);
        i64 cur = 0;
        int cnt = 0;
        for (auto val : set) {
            ++cnt;
            if (cnt > ans) {
                break;
            }
            cur += val;
            // printf("(%d, %lld)\n", cnt, cur);
            if (cur >= v[i]) {
                ans = std::min(ans, cnt);
                break;
            }
        }
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
