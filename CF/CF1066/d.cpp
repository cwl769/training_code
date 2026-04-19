#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>

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
        int64 n, l, r;readInt(n, l, r);
        std::vector<int64> a(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        std::sort(a.begin()+1, a.end());
        std::vector<int64> sum(n+1);
        for(int i=1;i<=n;++i)
            sum[i] = sum[i-1] + a[i];
        if(l>a[n/2+1]) {
            int64 cnt = n + 1ll - (std::lower_bound(a.begin()+1, a.end(), l) - a.begin());
            printf("%lld\n", sum[n] - sum[n-cnt] - sum[cnt] + l * (n-cnt*2ll) - (sum[n-cnt] - sum[cnt]));
        } else if(r < a[(n+1)/2]) {
            int64 cnt = (std::upper_bound(a.begin()+1, a.end(), r) - a.begin()) - 1ll;
            printf("%lld\n", sum[n] - sum[n-cnt] - sum[cnt] + (sum[n-cnt] - sum[cnt]) - r*(n-cnt*2ll));
        } else {
            if(n&1)
                printf("%lld\n", sum[n]-sum[n/2+1]-sum[n/2]);
            else
                printf("%lld\n", sum[n]-sum[n/2]-sum[n/2]);
        }
    }

    return 0;
}