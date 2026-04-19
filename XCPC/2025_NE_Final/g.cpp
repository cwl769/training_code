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
        if(n&1) {
            std::vector<int64> x(n+1);
            x[n] = a[n];
            for(int i=1;i<n;++i) {
                if(i&1)
                    x[n] -= a[i];
                else
                    x[n] += a[i];
            }
            x[n] /= 2;
            for(int i=n-1;i>=1;--i) {
                x[i] = a[i] - x[i+1];
            }
            int64 s = 0, m = 0;
            // for(int i=1;i<=n;++i)
            //     printf("%lld ", x[i]);
            // printf("\n");
            for(int i=1;i<=n;++i) {
                s += x[i];
                m = std::max(m, x[i]);
            }
            printf("%lld\n", std::max(m, (s-1)/(n-1)+1));
        } else {
            std::vector<int64> b(n+1);
            b[1] = 0;
            for(int i=2;i<=n;++i) {
                b[i] = a[i-1] - b[i-1];
            }
            int64 lowb = LLONG_MIN, uppb = LLONG_MAX;
            int64 mxodd = LLONG_MIN;
            int64 mxeve = LLONG_MIN;
            for(int i=1;i<=n;++i) {
                if(i&1) {
                    lowb = std::max(lowb, -b[i]);
                    mxodd = std::max(mxodd, b[i]);
                } else {
                    uppb = std::min(uppb, b[i]);
                    mxeve = std::max(mxeve, b[i]);
                }
            }
            int64 m = (mxodd + mxeve - 1) / 2 + 1;
            m = std::max(m, lowb + mxodd);
            m = std::max(m, mxeve - uppb);
            int64 s = 0;
            for(int i=1;i<=n;++i)
                s += a[i];
            s /= 2;
            printf("%lld\n", std::max(m, (s-1)/(n-1)+1));
        }
    }

    return 0;
}