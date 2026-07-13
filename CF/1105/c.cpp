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

void solve() {
    int n;readInt(n);
    veci64 a(n+2);
    for(int i=1;i<=n;++i) {
	readInt(a[i]);
    }
    if(n == 1) {
	printf("0\n");
	return;
    }
    i64 xum = 0;
    for(int i=1;i<=n;++i) {
	xum ^= a[i];
    }
    if(xum == 0) {
	printf("1\n");
	return;
    }
    int ans = 0;
    for(int i=1;i<=n;++i) {
	i64 tmp = (xum ^ a[i]);
	if(tmp <= a[i]) {
	    ++ans;
	}
    }
    printf("%d\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
