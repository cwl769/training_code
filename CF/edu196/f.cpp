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

struct Operate {
    int p, v;
};
bool operator < (const Operate& a, const Operate& b) {
    return a.p < b.p;
}

struct Range {
    int l, r;
};
bool operator < (const Range& a, const Range& b) {
    return a.r < b.r;
}

struct BIT {
  int* c;
  int N;
  BIT(int n) : N(n) {
    c = (int*)calloc(n + 1, sizeof(int));
  }
  virtual ~BIT() { free(c); }
  void add(int x, int v) {
    for (; x <= N; x += (x & (-x))) c[x] += v;
  }
  int query(int x) {
    int ans = 0;
    for (; x; x -= (x & (-x))) ans += c[x];
    return ans;
  }
};

void solve() {
    int n;readInt(n);
    veci ll(n + 2), rr(n + 2);
    for (int i = 2; i <= n; ++i)
        readInt(ll[i], rr[i]);
    std::vector<Operate> ops;
    for (int i = 2; i <= n; ++i) {
        ops.push_back({ll[i], i});
        ops.push_back({rr[i] + 1, -i});
    }
    std::sort(ops.begin(), ops.end());
    std::multiset<int> set;
    veci a(n + 2, n + 1);
    set.insert(n + 1);
    auto it = ops.begin();
    for (int i = 1; i <= n; ++i) {
        while(it != ops.end() && it->p == i) {
            if(it->v > 0) {
                set.insert(it->v);
            } else {
                set.erase(-it->v);
            }
            ++it;
        }
        a[i] = *set.begin();
    }
    std::vector<Range> rgs;
    for (int i = 2; i <= n; ++i) {
        rgs.push_back({ll[i], rr[i]});
    }
    std::sort(rgs.begin(), rgs.end());
    i64 ans = 0;
    for (auto [l, r] : rgs) {
        ans += r - l + 1;
    }
    std::vector<veci> vec(n + 2);
    for (int i = 1; i <= n; ++i)
        vec[a[i]].emplace_back(i);
    BIT tree(n + 10);
    auto itt = rgs.begin();
    for (int r = 1; r <= n; ++r) {
        for(auto x : vec[r]) {
            tree.add(x, 1);
        }
        while(itt != rgs.end() && itt->r == r) {
            int l = itt->l;
            ans -= tree.query(r) - tree.query(l - 1);
            ++itt;
        }
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