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

typedef long long int64;
typedef std::vector<int> vector;
typedef std::pair<int, int> PII;

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

const int64 MOD = 998244353;

int64 pow(int64 a, int64 b) {
    int64 ans = 1;
    for(;b;b>>=1) {
        if(b&1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
    }
    return ans;
}

int64 jc[200010], jc_inv[200010];

void init() {
    jc[0] = jc[1] = 1;
    jc_inv[0] = jc_inv[1] = 1;
    for(int i=2;i<200010;++i) {
        jc[i] = jc[i-1] * i % MOD;
        jc_inv[i] = jc_inv[i-1] * pow(i, MOD-2) % MOD;
    }
}

int64 C(int n, int m) {
    return (jc[n] * jc_inv[m] % MOD) * jc_inv[n-m] % MOD;
}

int64 small(std::vector<PII>& pnt, int n, int m) {
    int cnt = pnt.size();
    std::sort(pnt.begin(), pnt.end(), [](PII a, PII b)->bool {
        return a.first + a.second < b.first + b.second;
    });
    std::vector<int64> dp(cnt);
    for(int i=0;i<cnt;++i) {
        int x = pnt[i].first;
        int y = pnt[i].second;
        dp[i] = C(x-1+y-1, x-1);
        for(int j=0;j<i;++j) {
            int tx = pnt[j].first;
            int ty = pnt[j].second;
            if(tx<=x && ty<=y) {
                dp[i] = (dp[i] - dp[j] * C(x-tx+y-ty, x-tx)) % MOD;
            }
        }
        dp[i] = (dp[i] + MOD) % MOD;
    }
    int64 ans = 0;
    for(int i=0;i<cnt;++i) {
        int x = pnt[i].first;
        int y = pnt[i].second;
        ans = (ans + dp[i] * C(n-x+m-y, n-x)) % MOD;
    }
    return ans;
}

int64 big(std::vector<PII>& pnt, int n, int m) {
    // printf("big-------------\n");
    std::vector<std::vector<int64> > dp(n+1);
    for(int i=0;i<=n;++i)
        dp[i].resize(m+1);
    for(auto pr:pnt) {
        // printf("{%d, %d}\n", pr.first, pr.second);
        dp[pr.first][pr.second] = -1;
    }
    if(dp[1][1] == -1) {
        return C(n-1+m-1, n-1);
    }
    // printf("--------\n");
    dp[1][0] = 1;
    // printf("--------\n");
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j) {
        // printf("[%d %d]\n", i, j);
        fflush(stdout);
        if(dp[i][j] == -1) {
            dp[i][j] = 0;
        } else {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    return ((C(n-1+m-1, n-1) - dp[n][m]) % MOD + MOD) % MOD;
}

void solve() {
    int n, m;readInt(n, m);
    std::vector<vector> map(n+1);
    for(int i=1;i<=n;++i)
        map[i].resize(m+1);
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j) 
        readInt(map[i][j]);
    std::vector<std::vector<PII> > pnt(n*m+1);
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
        pnt[map[i][j]].push_back({i, j});
    int S = n * m;
    int T = sqrt(S);
    int64 ans = 0;
    for(int col=1;col<=S;++col) {
        int64 val;
        if(pnt[col].size() < T)
            val = small(pnt[col], n, m);
        else
            val = big(pnt[col], n, m);
        ans = (ans + val) % MOD;
    }
    printf("%lld\n", ans);
}

int main() {
    init();
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}