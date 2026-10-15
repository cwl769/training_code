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

struct BIT {
  i64* c;
  i64 N;
  BIT(i64 n) : N(n + 10) {
    c = (i64*)calloc(N + 1, sizeof(i64));
  }
  virtual ~BIT() { free(c); }
  void add(i64 x, i64 v) {
    for (; x <= N; x += (x & (-x))) c[x] += v;
  }
  i64 query(i64 x) {
    i64 ans = 0;
    for (; x; x -= (x & (-x))) ans += c[x];
    return ans;
  }
};

char str[300010];

void solve() {
    int n;readInt(n);
    scanf("%s", str + 1);
    std::vector<veci> pos(10);
    for (int i = 1; i <= n; ++i) {
        pos[str[i] - '0'].emplace_back(i);
    }
    for (int v = 0; v < 10; ++v)
        pos[v].emplace_back(n + 1);
    auto findnxt = [&pos] (int from, int val) -> int {
        return *std::lower_bound(pos[val].begin(), pos[val].end(), from);
    };
    BIT kk(n + 2), bb(n + 2);

    auto add = [&kk, &bb] (int l, int r, i64 x, i64 y) -> void {
        kk.add(l, x);
        kk.add(r + 1, -x);
        bb.add(l, y);
        bb.add(r + 1, -y);
    };

    for (int st = 1; st <= n; ++st) {
        int pos = st;
        pos = findnxt(pos, 2);
        if(pos > n)continue;
        pos = findnxt(pos, 0);
        if(pos > n)continue;
        pos = findnxt(pos, 2);
        if(pos > n)continue;
        int pos202 = pos;
        pos = findnxt(pos, 5);
        if(pos > n)continue;
        int l = pos;
        int r = findnxt(pos202, 6);
        if(r < l)continue;
        --r;
        // printf("[%d] %d, %d\n", st, l, r);
        add(st, l - 1, 0, r - l + 1);
        add(l, r, -1, r + 1);
    }
    for (int i = 1; i <= n; ++i) {
        i64 k = kk.query(i);
        i64 b = bb.query(i);
        i64 tmp = k * i + b;
        i64 ans = 1ll * i * (n - i + 1ll) - tmp;
        printf("%lld ", ans);
    }
    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--)
        solve();

    return 0;
}