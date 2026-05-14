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
//统计小于等于x的和有多少个
i64 check(int x, veci& a, veci& b, const int n) {
    i64 ans = 0;
    for(int i=1;i<=n;++i) {
        int rs = x - a[i];
        //b_j <= rs
        ans += std::upper_bound(b.begin()+1, b.end(), rs) - (b.begin()+1);
    }
    return ans;
}

void solve() {
    int n;readInt(n);
    veci a(n+1), b(n+1);
    std::sort(a.begin()+1, a.end());
    std::sort(b.begin()+1, b.end());
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    for(int i=1;i<=n;++i)
        readInt(b[i]);
    int l = 0, r = 2e9;
    while(l < r) {
        int mid = ((l+r)>>1);
        if(check(mid, a, b, n) >= n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int sum = l;
    veci ans;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if(a[i]+b[j]<sum) {
                ans.push_back(a[i]+b[j]);
            } else {
                break;
            }
        }
    }
    ans.resize(n, sum);
    std::sort(ans.begin(), ans.end());
    for(auto val:ans)
        printf("%d ", val);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}