#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>

typedef long long i64;
typedef std::vector<int> veci;

void solve() {
    int n;scanf("%d", &n);
    veci a(n+1);
    for(int i=1;i<=n;++i) {
	scanf("%d", &a[i]);
    }
    i64 ans = 0;
    int mn = INT_MAX;
    for(int i=1;i<=n;++i) {
	mn = std::min(mn, a[i]);
        ans += mn;
    }
    printf("%lld\n", ans);
}

int main() {
    int T;scanf("%d", &T);
    while(T--) {
	solve();
    }
    
    return 0;
}
