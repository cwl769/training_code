#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

typedef long long int64;

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

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<int> c(n+2), p(n+2);
        for(int i=1;i<=n;++i)
            readInt(c[i], p[i]);
        std::vector<double> dp(n+2);
        dp[n+1] = 0.0;
        for(int i=n;i>=1;--i) {
            dp[i] = std::max(dp[i+1], c[i] + dp[i+1] * (1.0-p[i]/100.0));
        }
        printf("%.10lf\n", dp[1]);
    }

    return 0;
}