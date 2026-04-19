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

struct BIT {
    int *c;
    int N;
    BIT(int n) {
        N = n + 1;
        c = (int*)calloc(N, sizeof(int));
    }
    ~BIT(){free(c);}
    void add(int x, int v) {
        for(;x<N;x+=(x&(-x)))
            c[x] += v;
    }
    int query(int x) {
        int ans = 0;
        for(;x;x-=(x&(-x))) {
            ans += c[x];
        }
        return ans;
    }
};

const int64 M = 998244353;

int main() {
    int n;readInt(n);
    std::vector<int> p(n+1);
    for(int i=1;i<=n;++i)
        readInt(p[i]);
    std::vector<int64> f(n+1), fs(n+1);
    BIT bit(n);
    for(int i=1;i<=n;++i) {
        f[i] = bit.query(p[i] - 1);
        bit.add(p[i], 1);
    }
    int64 ans = 0;
    int64 sum = 0;
    for(int i=1;i<=n;++i) {
        ans = (ans + 1ll * f[i] * (p[i] - 1 - f[i])) % M;
        ans = (ans + 1ll * sum * (p[i] - 1 - f[i])) % M;
        sum = (sum * 2ll + f[i]) % M;
    }
    printf("%lld\n", ans);

    return 0;
}