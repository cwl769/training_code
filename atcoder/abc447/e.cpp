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

typedef Int<998244353> int_mod;

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

struct DSU {
    int *fa;
    int *siz;
    DSU(int n) {
        fa = (int*)malloc((n+1)*sizeof(int));
        siz = (int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;++i){
            fa[i] = i;
            siz[i] = 1;
        }
    }
    ~DSU() {
        free(fa);
    }
    int get(int x) {
        if(fa[x] == x) return x;
        return fa[x] = get(fa[x]);
    }
    void merge(int x, int y) {
        x = get(x);
        y = get(y);
        if(x == y)return ;
        if(siz[x] > siz[y]) {
            std::swap(x, y);
        }
        fa[x] = y;
        siz[y] += siz[x];
    }
};

int main() {
    int n, m;readInt(n, m);
    std::vector< std::pair<int, int> > edg(m+1);
    for(int i=1;i<=m;++i) {
        readInt(edg[i].first, edg[i].second);
    }
    int_mod ans;
    DSU dsu(n), dsu_cp(n);
    int i=m;
    for(;i>=1;--i) {
        int x = edg[i].first;
        int y = edg[i].second;
        dsu_cp.merge(x, y);
        if(dsu_cp.siz[dsu_cp.get(1)] == n) {
            break;
        }
        dsu.merge(x, y);
    }
    for(;i>=1;--i) {
        int x = edg[i].first;
        int y = edg[i].second;
        if(dsu.get(x) != dsu.get(y)) {
            ans += (int_mod(2) ^ i);
        }
    }
    printf("%lld\n", ans.val());

    return 0;
}