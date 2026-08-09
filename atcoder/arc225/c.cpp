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
        for (int i = 0; i <= n + 1; ++i)
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

typedef std::vector<std::pair<std::pair<int, int> , int>> Edge;

void solve() {
    int n, m, k;
    readInt(n, m, k);
    Edge edg[2];
    for (int i = 1; i <= m; ++i) {
        int x, y, w;
        readInt(x, y, w);
        edg[w].emplace_back((std::pair<int, int>){x, y}, i);
    }

    DSU dsu1(n), dsu2(n);
    veci ans;
    for (auto [x, y] : edg[0]) {
        dsu1.merge(x.first, x.second);
    }
    int cur = 0;
    for (auto [x, y] : edg[1]) {
        if (dsu1.merge(x.first, x.second)) {
            ++cur;
            dsu2.merge(x.first, x.second);
            ans.emplace_back(y);
        }
    }
    if (k < cur) {
        printf("-1\n");
        return;
    }
    for (auto [x, y] : edg[1]) {
        if (cur >= k)
            break;
        if (dsu2.merge(x.first, x.second)) {
            ++cur;
            ans.emplace_back(y);
        }
    }
    if (cur < k) {
        printf("-1\n");
        return;
    }
    for (auto [x, y] : edg[0]) {
        if (dsu2.merge(x.first, x.second))
            ans.emplace_back(y);
    }
    for (auto x : ans)
        printf("%d ", x);
    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
