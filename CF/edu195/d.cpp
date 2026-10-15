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

struct DSU {
    int *fa;
    DSU(int n) {
        int N = n + 10;
        fa = (int*)malloc(N * sizeof(int));
        for (int i = 0; i < N; ++i)
            fa[i] = i;
    }
    ~DSU() {
        free(fa);
    }
    int get(int x) {
        if(fa[x] == x)
            return x;
        return fa[x] = get(fa[x]);
    }
    void merge(int x, int y) {
        x = get(x);
        y = get(y);
        if(x == y)return;
        fa[x] = y;
    }
};

int solve() {
    int n, m;readInt(n, m);
    DSU dsu(n);
    veci dgr(n + 2);
    for (int i = 1; i <= m; ++i) {
        int x, y;readInt(x, y);
        dsu.merge(x, y);
        ++dgr[x];
        ++dgr[y];
    }
    std::vector<veci> sg(n + 2);
    for (int i = 1; i <= n; ++i) {
        sg[dsu.get(i)].emplace_back(i);
    }
    int conncnt = 0;
    for (int i = 1; i <= n; ++i) {
        if(sg[i].empty())
            continue;
        if(sg[i].size() == 1u)
            return 0;
        ++conncnt;
    }
    if(conncnt > 1)
        return 3;
    int mrcnt = 0;
    for (int i = 1; i <= n; ++i) {
        if(dgr[i] >= 2)
            ++mrcnt;
        if(mrcnt >= 2)
            return 3;
    }
    return 2;
}

int main() {
    int T;readInt(T);
    while(T--){
        int ans = solve();
        if(ans > 2)
            printf("Many\n");
        else if(ans == 0)
            printf("Brain Melt\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}