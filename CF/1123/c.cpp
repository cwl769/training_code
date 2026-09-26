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
#include <stack>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

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

void solve() {
    int n, x;readInt(n, x);
    veci a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    veci prime;
    int tmp = sqrt(x);
    for(int t = 2; t <= tmp; ++t) {
        if(x % t == 0) {
            prime.emplace_back(t);
            while(x % t == 0)
                x /= t;
        }
    }
    if(x != 1)
        prime.emplace_back(x);
    veci64 ans(prime.size());
    for(int j = 0; j < (int)prime.size(); ++j) {
        int p = prime[j];
        for(int i = 1; i <= n; ++i) {
            if(a[i] % p == 0) {
                ans[j] += a[i];
            }
        }
    }
    i64 fnl = 0;
    for(auto tt : ans)
        fnl = std::max(fnl, tt);
    printf("%lld\n", fnl);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}