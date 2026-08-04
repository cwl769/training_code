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

i64 cal(i64 rest, i64 n, i64 m, veci64 &p, veci64 &r, i64 sr) {
    i64 ans = 0;
    while (rest >= n) {
        ans += sr;
        rest -= n;
    }
    for (int i = 1; i <= m; ++i) {
        if (p[i] <= rest)
            ans += r[i];
    }
    return ans;
}

bool solve() {
    i64 n, m, d;
    readInt(n, m, d);
    veci64 p(m * 2 + 2), r(m * 2 + 2);
    for (int i = 1; i <= m; ++i)
        readInt(p[i], r[i]);
    if (m == 0) {
        return false;
    }
    i64 tot = n + n;
    i64 tar = 0;
    for (int i = 1; i <= m; ++i)
        tar += r[i];
    i64 sr = tar;
    
    tar <<= 1ll;
    for (int i = 1; i <= m; ++i) {
        p[m + i] = p[m] + n;
        r[m + i] = r[m];
    }
    i64 cur = 0;
    for (int i = 1; i <= m * 2; ++i) {
        if()
        cur += r[i];

        if (cal(tot - p[i] - 1, n, m, p, r, sr) + cur - d > tar) {
            printf("true at %d\n", i);
            return true;
        }
    }
    return false;
}

int main() {
    int T;readInt(T);
    while(T--) {
        if (solve())
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
