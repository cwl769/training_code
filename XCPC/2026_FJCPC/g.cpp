#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

i64 qpow(i64 a, i64 b, i64 mod) {
    i64 ans = 1;
    for(;b;b>>=1) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
    }
    return ans;
}

void solve() {
    i64 n, mod;scanf("%lld%lld", &n, &mod);
    i64 tmp = (n - 1) * (n - 2) / 2;
    if(!(n & 1))
        ++tmp;
    printf("%lld\n", qpow(2, tmp, mod));
}

int main() {
    int T;scanf("%d", &T);
    while(T--)solve();

    return 0;
}