#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <cassert>

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

typedef int64 int_mod;
const int64 M = 998244353;

int_mod qpow(int_mod x, int64 b) {
    int_mod ans = 1;
    for(;b;b>>=1) {
        if(b&1) {
            ans = (ans * x) % M;
        }
        x = (x * x) % M;
    }
    return ans;
}

int_mod C[600010][64];
void C_init() {
    for(int i=0;i<600010;++i)
        C[i][0] = 1;
    for(int i=1;i<600010;++i) {
        for(int j=1;j<=i&&j<64;++j){
            C[i][j] = (C[i-1][j] + C[i-1][j-1]);
            if(C[i][j] >= M)
                C[i][j] -= M;
        }
    }
}

int_mod chs(int64 n, int64 m) {
    return C[n][m];
}

int_mod chssum(int64 n, int64 m) {
    if(m<=n) {
        int_mod ans = 0;
        for(int i=0;i<=m;++i) {
            ans += C[n][i];
            if(ans >= M)
                ans -= M;
        }
        return ans;
    }
    return qpow(2, n);
}

int_mod solve(std::vector<int64> cnt, int64 x) {
    if(x == 0) {
        int64 cs = 0;
        for(int i=0;i<64;++i)
            cs += cnt[i];
        return qpow(2, cs);
    }
    int64 t = 61;
    while((1ll<<t) > x) -- t;
    int64 tc = 0;
    for(int64 tmp=0;t-tc>=0;++tc) {
        tmp |= (1ll<<(t-tc));
        if(tmp > x)
            break;
    }
    // printf("t:%lld tc:%lld\n", t, tc);
    int_mod ans = 0;
    int64 a = 0, b = 0, c = 0;
    for(int i=t+1;i<64;++i)
        a += cnt[i];
    b = cnt[t];
    for(int i=0;i<t;++i)
        c += cnt[i];
    ans += (qpow(2, a)-1ll) * qpow(int_mod(2ll), (b+c)) % M;
    if(ans >= M) ans -= M;
    if(ans < 0)ans = (ans + M) % M;
    // printf("solve(, %lld) = %lld\n", x, ans);

    ans += (qpow(2, b) - chssum(b, tc)) * qpow(int_mod(2ll), c) % M;
    if(ans >= M) ans -= M;
    if(ans < 0)ans = (ans + M) % M;
    // printf("%lld %lld %lld %lld %lld\n", b, tc, qpow(2, b), chssum(b, tc), qpow(int_mod(2ll), c));
    // printf("solve(, %lld) = %lld\n", x, ans);
    
    for(int i=t+1;i<64;++i) {
        cnt[i] = 0;
    }
    cnt[t] = 0;
    ans += chs(b, tc) * solve(cnt, (x&((1ll<<(t-tc+1))-1ll))<<tc) % M;
    if(ans >= M) ans -= M;
    // printBit(x);
    // printf("solve(, %lld) = %lld\n", x, ans);
    return ans;
}

int main() {
    C_init();

    int n, m;readInt(n, m);
    std::vector<int64> cnt(64);
    for(int i=0;i<n;++i) {
        int x;readInt(x);
        ++cnt[x];
    }
    for(;m;--m) {
        int64 op, val;readInt(op, val);
        // printf("%lld %lld\n", op, val);
        if(op == 1) {
            ++cnt[val];
        } else if(op == 2){
            --cnt[val];
        } else {
            printf("%lld\n", solve(cnt, val));
        }
    }

    return 0;
}