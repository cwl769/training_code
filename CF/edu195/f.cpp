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
    int *size;
    DSU(int n) {
        int N = n + 10;
        fa = (int*)malloc(N * sizeof(int));
        size = (int*)malloc(N * sizeof(int));
        for (int i = 0; i < N; ++i)
            fa[i] = i;
        for (int i = 0; i < N; ++i)
            size[i] = 1;
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
        if(size[x] <= size[y]) {
            fa[x] = y;
            size[y] += size[x];
        } else {
            fa[y] = x;
            size[x] += size[y];
        }
    }
};

void solve() {
    int n, k;readInt(n, k);
    veci p(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(p[i]);
    DSU dsu(n + 2);
    for (int i = 1; i <= n; ++i) {
        dsu.merge(i, p[i]);
    }
    veci vec;
    for (int i = 1; i <= n; ++i) {
        if(i != dsu.get(i))
            continue;
        vec.emplace_back(dsu.size[i]);
    }
    int tmp = 0;
    std::sort(vec.begin(), vec.end(), std::greater<int>() );
    for (int i = 0; i < std::min(k, (int)vec.size()); ++i) {
        tmp += vec[i] - 1;
    }
    if(tmp > k) 
        printf("Bob\b");
    else
        printf("Alice\n");
}

int main() {
    int T;readInt(T);
    while(T--)
        solve();

    return 0;
}