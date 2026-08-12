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

struct DSU {
    int *fa;
    DSU(int n) {
        fa = (int *)malloc((n + 2) * sizeof(int));
        for (int i = 0; i <= (n + 1); ++i)
            fa[i] = i;
    }
    ~DSU() { free(fa); }
    int get(int x) {
        if (fa[x] == x)
            return x;
        return fa[x] = get(fa[x]);
    }
    bool merge(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y)
            return false;
        fa[x] = y;
        return true;
    }
};

void solve() {
    int n, k;
    readInt(n, k);
    veci64 w(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(w[i]);
    std::vector<veci> id(1000001);
    for (int i = 1; i <= n; ++i)
        id[w[i]].emplace_back(i);
    DSU dsu(n);
    for (int d = k; d <= 1000000; ++d) {
        std::vector<int> vec;
        for (int x = d; x <= 1000000; x += d) {
            for (auto i : id[x])
                vec.emplace_back(i);
        }
        for (int i = 1; i < (int)vec.size(); ++i)
            dsu.merge(vec[i], vec[i-1]);
    }
    veci64 val(n + 2);
    for (int i = 1; i <= n; ++i) {
        val[dsu.get(i)] += w[i];
    }
    i64 ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = std::max(ans, val[i]);
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
