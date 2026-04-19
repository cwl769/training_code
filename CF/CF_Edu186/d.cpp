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
template<int64 M>
class Int {
private:
    int64 v;
public:
    Int():v(){}
    Int(const Int& b) {
        v = b.v;
    }
    Int(Int&& b) {
        v = b.v;
    }
    Int(int64 x) {
        if(x<0) {
            v = (x%M)+M;
            if(v==M)v = 0;
        } else if (x >= M) {
            v = x % M;
        } else {
            v = x;
        }
    }
    Int& operator = (const Int& b) {
        v = b.v;
        return *this;
    }
    Int& operator = (Int&& b) {
        v = b.v;
        return *this;
    }
    Int operator + (Int b) const {
        return v + b.v;
    }
    Int operator - (Int b) const {
        return v - b.v;
    }
    Int operator * (Int b) const {
        return v * b.v;
    }
    Int& operator += (Int b) {
        v += b.v;
        if(v >= M)
            v -= M;
        return *this;
    }
    Int& operator -= (Int b) {
        v -= b.v;
        if(v < 0)
            v += M;
        return *this;
    }
    Int& operator *= (Int b) {
        v = (v * b.v) % M;
        return *this;
    }
    // Int operator ^ (uint64 b) const {
    //     Int ans = 1;
    //     Int base = *this;
    //     for(;b;b>>=1) {
    //         if(b&1)
    //             ans *= base;
    //         base *= base;
    //     }
    //     return ans;
    // }
    int64 val() const {return v;}
};

typedef Int<998244353> int_mod;

int_mod jc[60];
int_mod C[60][60];

int_mod chs(int64 n, int64 m) {
    return C[n][m];
}

int main() {
    jc[0] = 1;
    for(int i=1;i<=55;++i) {
        jc[i] = jc[i-1] * i;
    }
    for(int i=0;i<=55;++i)
        C[i][0] = 1;
    for(int i=1;i<=55;++i) {
        for(int j=1;j<=i;++j) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }

    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<int64> a(n+1);
        for(int i=0;i<=n;++i)
            readInt(a[i]);
        int64 mx = 0;
        for(int i=1;i<=n;++i)
            mx = std::max(mx, a[i]);
        int64 mxcnt = 0;
        for(int i=1;i<=n;++i)
            if(a[i] == mx)
                ++mxcnt;
        for(int i=1;i<=n;++i) {
            if(a[i] != mx) {
                a[0] -= mx - 1 - a[i];
                a[i] = mx - 1;
            }
        }
        if(a[0] < 0){
            printf("0\n");
            continue;
        }
        if(mxcnt + a[0] <= n) {
            printf("%lld\n", ( chs(n - mxcnt, a[0]) * jc[mxcnt + a[0]] * jc[n-mxcnt-a[0]] ).val());
            continue;
        }
        a[0] %= n;
        printf("%lld\n", ( chs(n, a[0]) * jc[a[0]] * jc[n-a[0]] ).val());
    }

    return 0;
}