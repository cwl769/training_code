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
typedef unsigned long long uint64;

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
    Int operator ^ (uint64 b) const {
        Int ans = 1;
        Int base = *this;
        for(;b;b>>=1) {
            if(b&1)
                ans *= base;
            base *= base;
        }
        return ans;
    }
    int64 val() const {return v;}
};

typedef Int<998244353> intmod;

int main() {
    int n, m;readInt(n, m);
    std::vector<int64> a(n);
    std::vector<int64> b(m);
    for(int i=0;i<n;++i)
        readInt(a[i]);
    for(int i=0;i<m;++i)
        readInt(b[i]);
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    intmod ans = 0;
    int64 sp = 0;
    int64 lb = a[0];
    intmod tmp = 0;
    for(int i=0;i<n;++i)
        tmp += a[i] - a[0];
    for(int t=0;t<m;++t) {
        tmp += (sp) * (b[t] - lb);
        while(sp<n && a[sp]<=b[t]) {
            tmp -= a[sp] - lb;
            tmp += b[t] - a[sp];
            ++sp;
        }
        tmp -= (1ll * n - sp) * (b[t] - lb);
        ans += tmp;
        lb = b[t];
    }
    printf("%lld", ans.val());
    

    return 0;
}