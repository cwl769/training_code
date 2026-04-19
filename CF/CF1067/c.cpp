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
        int n, k;readInt(n, k);
        std::vector<int64> a(n+1), b(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        for(int i=1;i<=n;++i)
            readInt(b[i]);
        if(n==1) {
            if(k&1)printf("%lld\n", a[1] + b[1]);
            else printf("%lld\n", a[1]);
            continue;
        }
        
        std::vector<int64> pre[2], suf[2];
        pre[0].resize(n+2);
        pre[1].resize(n+2);
        suf[0].resize(n+2);
        suf[1].resize(n+2);
        for(int i=1;i<=n;++i) {
            pre[0][i] = a[i] + std::max(0ll, pre[0][i-1]);
            pre[1][i] = a[i] + b[i] + std::max(0ll, pre[0][i-1]);
            pre[1][i] = std::max(pre[1][i], a[i] + std::max(0ll, pre[1][i-1]));
        }
        for(int i=n;i>=1;--i) {
            suf[0][i] = a[i] + std::max(0ll, suf[0][i+1]);
            suf[1][i] = a[i] + b[i] + std::max(0ll, suf[0][i+1]);
            suf[1][i] = std::max(suf[1][i], a[i] + std::max(0ll, suf[1][i+1]));
        }
        int64 ans = LLONG_MIN;
        if(k&1) {
            for(int i=1;i<n;++i) {
                ans = std::max(ans, pre[0][i] + suf[1][i+1]);
                ans = std::max(ans, pre[1][i] + suf[0][i+1]);
            }
            for(int i=1;i<=n;++i)
                ans = std::max(ans, a[i] + b[i]);
        } else {
            for(int i=1;i<n;++i) {
                ans = std::max(ans, pre[0][i] + suf[0][i+1]);
            }
            for(int i=1;i<=n;++i)
                ans = std::max(ans, a[i]);
        }
        printf("%lld\n", ans);
    }

    return 0;
}