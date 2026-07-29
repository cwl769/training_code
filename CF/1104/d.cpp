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

char str[1000010];

void solve() {
    int n;
    readInt(n);

    scanf("%s", str + 1);
    veci64 dp[6];
    dp[0].resize(n + 2);//0
    dp[1].resize(n + 2);//1
    dp[2].resize(n + 2);//1...10
    dp[3].resize(n + 2);//0...01
    dp[4].resize(n + 2);//0...10
    dp[5].resize(n + 2);//1...01
    dp[str[1] - '0'][1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (str[i] == '0') {
            dp[0][i] = dp[2][i - 1] + 1;
            dp[1][i] = dp[0][i - 1] + dp[4][i - 1];
            dp[2][i] = dp[5][i - 1] + dp[1][i - 1];
            dp[3][i] = 0;
            dp[4][i] = dp[3][i - 1];
            dp[5][i] = 0;
            if (str[i - 1] == '0') {
                dp[3][i] += dp[0][i - 2] + dp[4][i - 2];
                dp[5][i] += dp[2][i - 2];
            }
        } else {
            dp[0][i] = dp[1][i - 1] + dp[5][i - 1];
            dp[1][i] = dp[3][i - 1] + 1;
            dp[2][i] = 0;
            dp[3][i] = dp[4][i - 1] + dp[0][i - 1];
            dp[4][i] = 0;
            dp[5][i] = dp[2][i - 1];
            if (str[i - 1] == '1') {
                dp[2][i] += dp[1][i - 2] + dp[5][i - 2];
                dp[4][i] += dp[3][i - 2];
            }
        }
    }
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dp[0][i] + dp[1][i];
    }

    for (int j = 0; j < 6; ++j) {
        for (int i = 1; i <= n; ++i)
            printf("%lld ", dp[j][i]);
        printf("\n");
    }
    
    printf("%lld\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
