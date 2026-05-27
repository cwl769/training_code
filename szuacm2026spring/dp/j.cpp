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
#include <bitset>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

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

struct Item {
    int volume, value;
};

void solve() {
    int n, m;readInt(n, m);
    std::vector<Item> item(n+1);
    for(int i=1;i<=n;++i)
        readInt(item[i].volume, item[i].value);
        
    std::vector< std::bitset<1024> > dp[2];
    dp[0].resize(1024);
    dp[1].resize(1024);
    dp[0][0][0] = 1;
    for(itn i=1;i<=n;++i) {
        auto& cur = dp[i&1];
        auto& prev = dp[(i&1)^1];
        cur = prev;
        for(int s=0;s<1024;++s) {
            cur[s^item[i].value] |= (prev[s]<<item[i].volume);
        }
    }
    int ans = -1;
    for(int s=0;s<1024;++s) {
        if(dp[n&1][s][m]) {
            ans = std::max(ans, s);
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