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
    int *siz;
    DSU(int n) {
        int N = n + 10;
        fa = (int *)malloc(N * sizeof(int));
        siz = (int *)malloc(N * sizeof(int));
        for (int i = 0; i < N; ++i)
            fa[i] = i;
        for (int i = 0; i < N; ++i)
            siz[i] = 1;
    }
    ~DSU() { free(fa); }
    int get(int x) {
        if (fa[x] == x)
            return x;
        return fa[x] = get(fa[x]);
    }
    void merge(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y)
            return;
        if (x < y)
            std::swap(x, y);
        // now x > y
        fa[x] = y;
        siz[y] += siz[x];
    }
    int size(int x) {
        return siz[get(x)];
    }
};

bool fill(int st, veci &a, veci &b, std::set<int> &emp, std::set<int> &val) {
    for (int x = st;; x = a[x]) {
        if (~b[a[x]]) {
            if (b[a[x]] != a[b[x]])
                return false;
            break;
        }
        if (val.find(a[b[x]]) == val.end())
            return false;
        b[a[x]] = a[b[x]];
        emp.erase(a[x]);
        val.erase(a[b[x]]);
    }
    return true;
}

void solve() {
    int n;
    readInt(n);
    veci a(n + 2), b(n + 2);
    for (int i = 1; i <= n; ++i) {
        readInt(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        readInt(b[i]);
    }

    DSU dsu(n);
    for (int i = 1; i <= n; ++i) {
        dsu.merge(i, a[i]);
    }
    
    std::set<int> emp, val;
    for (int i = 1; i <= n; ++i) {
        if (b[i] == -1)
            emp.emplace(i);
    }
    for (int v = 1; v <= n; ++v) {
        val.emplace(v);
    }
    for (int i = 1; i <= n; ++i) {
        if (~b[i])
            val.erase(b[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (~b[i]) {
            if (!fill(i, a, b, emp, val)) {
                printf("NO\n");
                return;
            }
        }
    }

    // check if sizeof(value ring) == size of(index ring)
    for (int i = 1; i <= n; ++i) {
        if (b[i] == -1)
            continue;
        if (dsu.size(i) != dsu.size(b[i])) {
            printf("NO\n");
            return;
        }
    }

    std::multimap<int, int> map;
    for (auto v : val) {
        if (dsu.get(v) == v)
            map.emplace(dsu.size(v), v);
    }

    while (emp.size()) {
        int x = *emp.begin();
        int siz = dsu.size(x);
        auto it = map.find(siz);
        int v = it->second;
        b[x] = v;
        emp.erase(x);
        val.erase(v);
        map.erase(it);
        if (!fill(x, a, b, emp, val)) {
            printf("NO\n");
            return;
        }
    }    
    
    printf("YES\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", b[i]);
    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
