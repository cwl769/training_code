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

const i64 MOD = 998244353;

i64 qpow(i64 a, i64 b ) {
    i64 ans = 1;
    for(;b;b>>=1) {
	if(b&1){
	    ans = ans * a % MOD;
	}
	a = a * a % MOD;
    }
    return ans;
}

void solve() {
    i64 n, m, r, c;readInt(n, m, r, c);
    i64 tmp = n * (c - 1) + m * (r - 1) - (c - 1) * (r - 1);
    printf("%lld\n", qpow(2, tmp));
    
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
