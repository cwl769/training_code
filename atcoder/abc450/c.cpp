#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

typedef long long int64;
typedef std::vector<int> vector;

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
        fa = (int*)malloc((n+1)*sizeof(int));
        size = (int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;++i)
            fa[i] = i;
        for(int i=0;i<=n;++i)
            size[i] = 1;
    }
    ~DSU() {
        free(fa);
        free(size);
    }
    int get(int x) {
        if(fa[x] == x)return x;
        return fa[x] = get(fa[x]);
    }
    void merge(int x, int y) {
        x = get(x);
        y = get(y);
        if(x == y)return;
        if(size[x] < size[y]) {
            fa[x] = y;
        } else {
            fa[y] = x;
        }
        return;
    }
};

#define id(i, j) ((i)*m+(j))

char map[1010][1010];

int main() {
    int n, m;readInt(n, m);
    for(int i=0;i<n;++i)
        scanf("%s", map[i]);
    DSU dsu(n*m);
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(i+1<n) {
                if(map[i][j] == '.' && map[i+1][j] == '.') {
                    dsu.merge(id(i, j), id(i+1, j));
                }
            }
            if(j+1<m) {
                if(map[i][j] == '.' && map[i][j+1] == '.') {
                    dsu.merge(id(i, j), id(i, j+1));
                }
            }
        }
    }
    std::vector<bool> dis(n*m);
    for(int i=0;i<n;++i) {
        if(map[i][0] == '.') {
            dis[dsu.get(id(i, 0))] = 1;
        }
        if(map[i][m-1] == '.') {
            dis[dsu.get(id(i, m-1))] = 1;
        }
    }
    for(int j=0;j<m;++j) {
        if(map[0][j] == '.') {
            dis[dsu.get(id(0, j))] = 1;
        }
        if(map[n-1][j] == '.') {
            dis[dsu.get(id(n-1, j))] = 1;
        }
    }
    int ans = 0;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            int tt = id(i, j);
            if(map[i][j] == '.' && dsu.fa[tt] == tt && !dis[tt]) {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}