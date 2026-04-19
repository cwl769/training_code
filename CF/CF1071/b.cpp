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
        std::vector<int64> a(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        std::vector<int64> pre(n+2), suf(n+2);
        for(int i=2;i<=n;++i) {
            pre[i] = pre[i-1] + std::abs(a[i] - a[i-1]);
        }
        for(int i=n-1;i>=1;--i) {
            suf[i] = suf[i+1] + std::abs(a[i] - a[i+1]);
        }
        int64 ans = std::min(pre[n-1], suf[2]);
        for(int i=2;i<n;++i) {
            ans = std::min(ans, pre[i-1] + suf[i+1] + std::abs(a[i-1]-a[i+1]));
        }
        printf("%lld\n", ans);
    }

    return 0;
}