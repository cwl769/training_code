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

char str[300010];

void solve() {
    int ans = 0;
    scanf("%s", str+1);
    int n = strlen(str+1);
    for(int i=1;i<=n;++i) {
        if(str[i] == '4')
            ++ans;
    }
    // int first13 = n+1, last2 = 0;
    veci cntpre(n+2), cntsuf(n+2);
    for(int i=1;i<=n+1;++i) {
        cntpre[i] = cntpre[i-1];
        if(str[i] == '1' || str[i] == '3'){
            ++cntpre[i];
            // first13 = std::min(first13, i);
        }
    }
    for(int i=n;i>=0;--i) {
        cntsuf[i] = cntsuf[i+1];
        if(str[i] == '2'){
            ++cntsuf[i];
            // last2 = std::max(last2, i);
        }
    }

    // printf("%d %d %d %d %d\n", ans, first13, last2, cntpre[last2], cntsuf[first13]);
    // ans += std::min(cntpre[last2], cntsuf[first13]);
    int mn = INT_MAX;
    for(int d=1;d<=n+1;++d) {
        mn = std::min(mn, cntpre[d-1] + cntsuf[d]);
    }
    ans += mn;
    printf("%d\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}