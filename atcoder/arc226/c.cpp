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
    int ans = (n / 2) * (m / 2);
    printf("%d\n", ans);
    for (int i = 1; i + 1 <= n; i += 2) {
        for (int j = 1; j + 1 <= m; j += 2) {
            printf("%d %d 1\n", i, j);
        }
    }
    
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }
    // solve();

    return 0;
}
