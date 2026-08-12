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
    int N, *c;
    Fenwick(int n) {
        N = n + 10;
        c = (int*)calloc(N, sizeof(int));
    }
    ~Fenwick() { free(c); }
    void add(int x, int v) {
        if (x <= 0)
            return;
        for (; x < N; x += (x & (-x)))
            c[x] += v;
    }
    int get(int x) {
        int ans = 0;
        for (; x; x -= (x & (-x)))
            ans += c[x];
        return ans;
    }
};

void solve() {
    int n;
    readInt(n);
    veci s(n + 2);
    veci c(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(s[i], c[i]);
    std::map<int, int> disc;
    for (int i = 1; i <= n; ++i)
        disc[s[i]] = 0;
    for (int i = 1; i <= n; ++i)
        disc[c[i]] = 0;
    int tot = 0;
    for (auto &[x, v] : disc) {
        v = ++tot;
    }
    for (int i = 1; i <= n; ++i) {
        s[i] = disc[s[i]];
        c[i] = disc[c[i]];
    }

    Fenwick tree(n * 2);
    for (int i = 1; i <= n; ++i)
        tree.add(s[i], 1);
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] < c[i]) {
            ans += tree.get(c[i] - 1) - tree.get(s[i] - 1);
            --ans;
        }
    }
    printf("%lld\n", ans);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
    //     solve();
    // }
    solve();

    return 0;
}
