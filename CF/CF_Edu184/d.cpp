#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
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

int64 X;
constexpr int64 T = (int64)2e6;

int64 trans(int64 m, int64 x, const int64 y) {
    std::vector<long double> C;C.push_back(1.0);
    long double ans = 0;
    for(int64 tmp=m,i=0;tmp;tmp/=y) {
        if(i&1) ans -= C[i]*tmp;
        else ans += C[i]*tmp;
        ++i;
        if(i<=x) {
            C.push_back(C.back()*(1.0*x-i+1.0)/i);
        } else {
            C.push_back(0);
        }
        printf("    [%lld]%Lf\n", i, ans);
    }
    printf("%lld %lld %lld %Lf\n", m, x, y, ans);
    return std::abs(ans);
}

const int64 M = 1e12;

int main() {
    trans(1234, 3, 10);
    int T;readInt(T);
    for(;T;--T) {
        int64 x, y, k;readInt(x, y, k);
        X = x;
        if(y==1) {
            printf("-1\n");
            continue;
        }
        if(k<y) {
            printf("%lld\n", k);
            continue;
        }
        int64 l = y, r = M+1;
        for(;l<r;) {
            int64 mid = ((l+r)>>1);
            if(trans(mid, x, y) < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if(l>M)printf("-1\n");
        else printf("%lld\n", l);
    }

    return 0;
}