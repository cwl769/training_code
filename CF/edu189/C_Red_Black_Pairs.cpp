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

char a[2][200010];

void solve() {
    itn n;readInt(n);
    scanf("%s", a[0]+1);
    scanf("%s", a[1]+1);
    veci dp(n+1);
    dp[0] = 0;
    if(a[0][1] == a[1][1]) {
        dp[1] = 0;
    } else {
        dp[1] = 1;
    }
    for(int i=2;i<=n;++i) {
        int cnt1 = 0, cnt2 = 0;
        if(a[0][i] != a[0][i-1])
            ++cnt1;
        if(a[1][i] != a[1][i-1])
            ++cnt1;
        if(a[0][i] != a[1][i])
            ++cnt2;
        dp[i] = std::min(dp[i-2]+cnt1, dp[i-1]+cnt2);
    }
    printf("%d\n", dp[n]);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}