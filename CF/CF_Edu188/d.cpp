#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <queue>

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

struct DSU {
    int *fa;
    DSU(int n) {
        fa = (int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;++i)
            fa[i] = i;
    }
    ~DSU() {
        free(fa);
    }
    int get(int x) {
        if(fa[x] == x)return x;
        return fa[x] = get(fa[x]);
    }
    void merge(int x, int y) {
        x = get(x);
        y = get(y);
        if(x == y)return ;
        fa[x] = y;
    }
};

typedef std::vector<std::vector<int> > Graph;
typedef std::vector<int> Vec;

void color(int st, Graph& g, Vec& col, DSU& dsu, Vec& cnt0, Vec& cnt1) {
    // printf("st = %d\n", st);
    int rt = dsu.get(st);
    if(cnt0[rt] == -1) return;
    std::queue< std::pair<int, int> > q;
    q.push({st, 0});
    while(q.size()) {
        int x = q.front().first;
        int cc = q.front().second;
        q.pop();
        if(col[x] != -1)continue;
        for(auto y:g[x]) {
            if(col[y] == cc) {
                cnt0[rt] = -1;
                cnt1[rt] = -1;
                return;
            }
        }
        col[x] = cc;
        if(cc)
            cnt1[rt]++;
        else
            cnt0[rt]++;
        // printf("cnt[%d][%d]+=1 at %d\n", cc, rt, x);
        for(auto y:g[x]) {
            if(col[y] == -1) {
                q.push({y, cc^1});
            }
        }
    }
}

int main() {
    int T;readInt(T);
    while(T--) {
        int n, m;readInt(n, m);
        Graph g(n+1);
        DSU dsu(n);
        for(int i=1;i<=m;++i) {
            int x, y;readInt(x, y);
            dsu.merge(x, y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        std::vector<int> col(n+1, -1);
        std::vector<int> cnt[2];
        cnt[0].resize(n+1);
        cnt[1].resize(n+1);
        for(int x=1;x<=n;++x) {
            if(col[x] == -1) {
                color(x, g, col, dsu, cnt[0], cnt[1]);
            }
        }
        int ans = 0;
        for(int x=1;x<=n;++x) {
            if(dsu.fa[x] == x && cnt[0][x] != -1) {
                ans += std::max(cnt[0][x], cnt[1][x]);
                // printf("[%d] %d %d\n", x, cnt[0][x], cnt[1][x]);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}