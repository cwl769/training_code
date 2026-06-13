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

const i64 MOD = 1000000007;

std::vector<int> prime;
bool vis[500010];
int mnp[500010];

void Euler() {
    vis[0] = vis[1] = 1;
    for(int x=2;x<500010;++x) {
        if(!vis[x]) {
            prime.emplace_back(x);
            mnp[x] = x;
        }
        for(auto p:prime) {
            int t = p * x;
            if(t >= 500010)
                break;
            vis[t] = 1;
            mnp[t] = p;
            if(x%p == 0)
                break;
        }
    }
}

void solve() {
    int n, x;readInt(n, x);
    std::vector<int> a(n+2);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    // std::vector<int> cur;
    std::map<int, int> map;
    for(int i=1;i<=n;++i) {
        int x = a[i];
        while(x > 1) {
            ++map[mnp[x]];
            x /= mnp[x];
        }
    }
    // std::sort(cur.begin(), cur.end());
    // cur.resize(std::unique(cur.begin(), cur.end()) - cur.begin());
    i64 ans = 1ll;
    for(auto [p, cnt]:map) {
        ans = ans * (cnt + 1ll) % MOD;
    }
    printf("%lld\n", ans);
}

int main() {
    Euler();
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}