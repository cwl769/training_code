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

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

#define debug(...) fprintf(stderr, __VA_ARGS__)

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

int n, d;
veci64 s;
i64 sum(int l, int r) {
    l %= n;
    r %= n;
    if(l <= 0) l += n;
    if(r <= 0) r += n;
    if(l <= r) return s[r] - s[l-1];
    else return s[n] - s[l-1] + s[r];
}

void solve() {
    readInt(n, d);
    veci64 a(n+2);
    for(int i=1;i<=n;++i)
	readInt(a[i]);
    s.resize(n+2);
    s[n+1] = s[0] = 0;
    for(int i=1;i<=n;++i)
	s[i] = s[i-1] + a[i];
    i64 ans = 0;
    for(int i=1;i<=n;++i) {
	i64 tmp = 2ll * d * a[i];
	tmp -= sum(i-d, i-1);
	tmp -= sum(i+1, i+d);
	if(tmp > 0)
	    ans += tmp;
    }
    printf("%lld\n", ans);
    
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
