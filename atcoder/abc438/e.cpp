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

typedef std::vector<std::vector<int> > Graph;
int64 a[200010];
bool ring[200010];
bool vis[200010];

int find_ring(int x) {
    if(vis[x])return x;
    vis[x] = 1;
    int st = find_ring(a[x]);
    if(st > 0) ring[x] = 1;
    if(st == x) {
        vis[x] = 0;
        return -st;
    } else {
        vis[x] = 0;
        return st;
    }
}

int main() {
    int n, q;readInt(n, q);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    Graph g(n+1);
    for(int i=1;i<=n;++i) {
        g[a[i]].push_back(i);
    }
    int ret = find_ring(1);
    printf("%d\n", -ret);
    for(int i=1;i<=n;++i)
        if(ring[i])
            printf("ring %d\n", i);

    return 0;
}