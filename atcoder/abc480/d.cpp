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
#include <queue>
#include <stack>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

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
    int n, Q;readInt(n, Q);
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    veci64 ssa(n + 2);
    veci64 sa(n + 2);
    for (int i = 1; i <= n; ++i) 
        sa[i] = sa[i - 1] + a[i];
    for (int i = 1; i <= n; ++i)
        ssa[i] = ssa[i - 1] + sa[i];
    veci64 sp;
    i64 tmp = 0;
    for (int i = 1; i <= n; ++i) {
        tmp += i;
        sp.emplace_back(tmp);
    }
    auto sumb = [&sp, &ssa, &sa](i64 x) -> i64 {
        if(x == 0)return 0;
        i64 pre = std::lower_bound(sp.begin(), sp.end(), x) - sp.begin();
        i64 ans = 0;
        ans += ssa[pre];
        x -= pre * (pre + 1) / 2;
        ans += sa[x];
        return ans;
    };
    while(Q--) {
        i64 l, r;readInt(l, r);
        printf("%lld\n", sumb(r) - sumb(l - 1));
    }
}

int main() {
    // int T;readInt(T);
    // while(T--)
        solve();

    return 0;
}