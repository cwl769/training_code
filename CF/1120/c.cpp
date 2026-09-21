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

struct Fenwick {
  int* c;
  int N;
  Fenwick(int n) : N(n) {
    c = (int*)calloc(n + 10, sizeof(int));
  }
  virtual ~Fenwick() { free(c); }
  void add(int x, int v) {
    ++x;
    for (; x <= N; x += (x & (-x))) c[x] += v;
  }
  int query(int x) {
    ++x;
    int ans = 0;
    for (; x; x -= (x & (-x))) ans += c[x];
    return ans;
  }
};

constexpr i64 MOD = 1000000007;

void solve() {
    int n;readInt(n);
    veci a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    Fenwick tree(n + 10);
    for (int x = 1; x <= n; ++x) {
        i64 l = x * a[x];
        i64 r = std::min(n - 1, x * a[x] + x - 1);
        if(l > r)
            continue;
        tree.add(l, 1);
        tree.add(r + 1, -1);
    }
    std::vector<int> avi;
    for (int i = 0; i < n; ++i) {
        if(tree.query(i) == 0)
            avi.emplace_back(i);
    }

    // printf("avi: ");
    // for (auto x : avi)
    //     printf("%d ", x);
    // printf("\n");

    std::vector<int> lmx(n + 2, 0);
    int allmx = 0;
    for (int x = 1; x <= n; ++x) {
        for (int l = 0; l < x * a[x]; l += x) {
            int r = l + x - 1;
            r = std::min(r, n - 1);
            if(l > r)
                continue;
            int ll = std::lower_bound(avi.begin(), avi.end(), l) - avi.begin();
            int rr = std::upper_bound(avi.begin(), avi.end(), r) - avi.begin() - 1;
            ++ll;++rr;
            // printf("[%d, %d] [%d, %d]\n", l, r, ll, rr);
            lmx[rr] = std::max(lmx[rr], ll);
            allmx = std::max(allmx, ll);
        }
    }


    std::vector<i64> dps(n + 2), dp(n + 2);
    dp[0] = 1;
    dps[0] = 1;
    for (int i = 1; i <= (int)avi.size(); ++i) {
        lmx[i] = std::max(lmx[i - 1], lmx[i]);
        if(lmx[i - 1] == 0)
            dp[i] = dps[i - 1];
        else
            dp[i] = (dps[i - 1] - dps[lmx[i - 1] - 1] + MOD) % MOD;
        dps[i] = (dps[i - 1] + dp[i]) % MOD;
    }

    // for (int i = 0; i <= (int)avi.size(); ++i)
    //     printf("%lld ", dp[i]);
    // printf("\n");
    // for (int i = 0; i <= (int)avi.size(); ++i)
    //     printf("%lld ", dps[i]);
    // printf("\n");

    i64 ans = 0;
    for (int i = allmx; i <= (int)avi.size(); ++i) {
        ans = (ans + dp[i]) % MOD;
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