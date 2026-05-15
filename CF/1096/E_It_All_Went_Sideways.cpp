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

#include <stack>

void solve() {
    int n;readInt(n);
    veci a(n+1);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    i64 ans = 0;
    for(int i=n,cur=INT_MAX;i>=1;--i) {
        cur = std::min(cur, a[i]);
        ans += a[i] - cur;
    }
    
    std::stack<std::pair<int, int> > stack;
    stack.push({INT_MIN, 0});
    i64 mx = 0;
    for(int i=1;i<=n;++i) {
        while(stack.top().first >= a[i]) {
            stack.pop();
        }
        // printf("{%d, %d}\n", i, stack.top().second);
        mx = std::max(mx, i - (stack.top().second) - 1ll);
        stack.push({a[i], i});
    }

    // printf("%d %d\n", ans, mx);
    ans += mx;
    printf("%lld\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}