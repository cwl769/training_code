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

struct Fenwick {
    int *c;
    int N;
    Fenwick(int n) {
        N = n + 10;
        c = (int*)calloc(N, sizeof(int));
    }
    ~Fenwick() {
        free(c);
    }
    void add(int x, int v) {
        for(;x<N;x+=(x&(-x)))
            c[x] += v;
    }
    int sum(int x) {
        int ans = 0;
        for(;x;x-=(x&(-x)))
            ans += c[x];
        return ans;
    }
    int find(int rk) {
        int l = 1, r = N;
        for(;l<r;) {
            int mid = ((l+r)>>1);
            if(sum(mid)>=rk)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

int dp[5010][5010];

void solve() {
    int n;readInt(n);
    veci a(n+1);
    std::map<int, int> map;
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    for(int i=1;i<=n;++i)
        map[a[i]] = 1;
    int tot = 0;
    for(auto &pr:map) {
        ++tot;
        pr.second = tot;
    }
    for(int i=1;i<=n;++i)
        a[i] = map[a[i]];
    
    for(int i=0;i<=n;++i)
    for(int j=0;j<=n;++j)
        dp[i][j] = INT_MIN;
    for(int m=1;m<=n;++m)
        dp[0][m] = 0;
    // printf("-------\n");
    for(int i=1;i<=n;++i) {
        Fenwick tree(n+1);
        for(int j=i-1;j>=0;j-=2) {
            // printf("{%d %d}\n", i, j);
            tree.add(a[j+1], 1);
            if(j+2<=i)
                tree.add(a[j+2], 1);
            int m = tree.find((i-j+1)/2);
            dp[i][m] = std::max(dp[i][m], dp[j][m] + 1);
        }
    }
    int ans = 1;
    for(int m=1;m<=n;++m)
        ans = std::max(ans, dp[n][m]);
    printf("%d\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}