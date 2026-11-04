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
    int n, k, t;readInt(n, k, t);
    veci a(n);
    for (int i = 0; i < n; ++i)
        readInt(a[i]);
    std::sort(a.begin(), a.end());
    std::vector<PII> covered;
    int ll = (int)-1e9, rr = (int)-1e9;
    for (auto l : a) {
        int r = l + k - 1;
        if(l > rr + 1) {
            if(ll != (int)-1e9)
                covered.emplace_back(ll, rr);
            ll = l;
            rr = r;
        } else {
            rr = std::max(rr, r);
        }
    }
    if(ll != (int)-1e9)
        covered.emplace_back(ll, rr);
    
    // for(auto [l, r] : covered)
    //     printf("[%d, %d] ", l, r);
    // printf("\n");

    std::vector<PII> ncov;
    int cur = 0;
    for (auto [l, r] : covered) {
        //[cur, l - 1]
        if(cur <= std::min(t - 1, l - 1))
            ncov.emplace_back(cur, std::min(t - 1, l - 1));
        cur = r + 1;
    }
    if(cur <= t-1)
        ncov.emplace_back(cur, t-1);

    // for(auto [l, r] : ncov)
    //     printf("[%d, %d] ", l, r);
    // printf("\n");

    int ans = 0;
    for(auto [l, r] : ncov) {
        int len = r - l + 1;
        ans += (len - 1) / (k) + 1;
        // printf("{%d %d}", len, ans);
    }
    printf("%d", ans);
}

int main() {
    // int T;readInt(T);
    // while(T--)
        solve();

    return 0;
}