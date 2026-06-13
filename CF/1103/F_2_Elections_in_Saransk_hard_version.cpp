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

i64 pow(i64 a, i64 b) {
    i64 ans = 1;
    for(;b;b>>=1) {
        if(b&1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
    }
    return ans;
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

    for(;x>1;) {
        int p = mnp[x];
        int cnt = 0;
        while(x > 1 && mnp[x] == p) {
            ++cnt;
            x /= p;
        }
        ans = ans * pow(map[p] + 1ll, MOD-2) % MOD;
        // printf("handle %d %d\n", p, cnt);

        std::vector<int> c;
        int mxc = 0;
        for(int i=1;i<=n;++i) {
            int val = a[i];
            int tmp = 0;
            while(val%p==0) {
                ++tmp;
                val /= p;
            }
            if(tmp)
                c.push_back(tmp);
            mxc = std::max(mxc, tmp);
        }
        std::vector<veci> dp[2];
        dp[0].resize(mxc+1);
        for(int i=0;i<=mxc;++i)
            dp[0][i].resize(mxc+cnt+1);
        dp[1].resize(mxc+1);
        for(int i=0;i<=mxc;++i)
            dp[1][i].resize(mxc+cnt+1);
        // dp[1][0][0] = 1;
        for(int m=0;m<=mxc;++m) {
            dp[1][m][0] = 1;
        }
        for(int i=0;i<(int)c.size();++i) {
            int ci = c[i];
            for(int m=0;m<=mxc;++m)
            for(int j=0;j<=mxc+cnt;++j)
                dp[i&1][m][j] = 0;
            for(int m=0;m<=mxc;++m) {
                for(int t=0;t<=m&&t<=ci;++t) {
                    for(int j=t;j<=mxc+cnt;++j) {
                        dp[i&1][m][j] = (dp[i&1][m][j] + dp[(i&1)^1][m][j-t]);
                        if(dp[i&1][m][j] >= MOD)
                            dp[i&1][m][j] -= MOD;
                    }
                }
            }
            // for(int m=0;m<=mxc;++m) {
            //     for(int j=0;j<=mxc+cnt;++j)
            //         printf("%d ", dp[i&1][m][j]);
            //     printf("\n");
            // }
            // printf("-----------\n");
        }
        i64 tmp = 0;
        std::vector<veci> &f = dp[(c.size()-1)&1];
        for(int m=1;m<=mxc;++m) {
            i64 ttt = f[m][m+cnt] - f[m-1][m+cnt];
            if(ttt < 0)
                ttt += MOD;
            tmp += ttt;
            if(tmp >= MOD)
                tmp -= MOD;
        }
        ans = ans * tmp % MOD;
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