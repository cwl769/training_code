#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <queue>

typedef long long int64;
typedef long long i64;
typedef unsigned long long ui64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;


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

void solve() {
    int n, k;int64 p, q;readInt(n, k, p, q);
    if(p > q)std::swap(p, q);
    veci64 a(n+1);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    veci64 s(n+1);
    for(int i=1;i<=n;++i)
        s[i] = s[i-1] + a[i] % q % p;
    veci64 t(n+1);
    for(int i=1;i<=n;++i)
        t[i] = t[i-1] + a[i] % p;
    veci64 r(n+1);
    for(int i=1;i<=n;++i)
        r[i] = r[i-1] + std::min(a[i] % p, a[i] % q % p);
    int64 mn = LLONG_MAX, mni = 0;
    for(int i=k;i<=n;++i) {
        int64 tmp = std::min(s[i] - s[i-k], t[i] - t[i-k]) - (r[i] - r[i-k]);
        if(tmp < mn) {
            mn = tmp;
            mni = i;
        }
    }
    int64 ans = 0;
    ans += mn;
    ans += r[n];
    printf("%lld\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}