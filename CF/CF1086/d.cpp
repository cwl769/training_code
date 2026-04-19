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

struct Dsu {
    int *fa;
    Dsu(int n) {
        fa = (int*)malloc((n+1) * sizeof(int));
        for(int i=0;i<=n;++i)
            fa[i] = i;
    }
    ~Dsu() {
        free(fa);
    }
    int get(int x) {
        if(fa[x] == x)return x;
        return fa[x] = get(fa[x]);
    }
    bool merge(int x, int y) {
        x = get(x);
        y = get(y);
        if(x==y)return false;
        // if(x < y)
        //     fa[y] = x;
        // else
        //     fa[x] = y;
        fa[x] = y;
        return true;
    }
};

char map[8010][8010];
bool vis[8010][8010];
bool disable[8010][8010];

int main() {
    int T;readInt(T);
    for(;T;--T) {
        // printf("T=%d\n", T);
        int n;readInt(n);
        for(int i=1;i<=n;++i)
            scanf("%s", map[i] + 1);
        for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            vis[i][j] = (map[i][j] == '1');
        for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            disable[i][j] = false;
        bool outputed = false;
        for(int i=1;i<=n;++i) {
            if(!vis[i][i]) {
                printf("NO\n");
                outputed = true;
                break;
            }
        }
        if(outputed) continue;
        for(int i=1;i<=n;++i) {
            for(int j=1;j<i;++j)
                if(vis[i][j] && vis[j][i]) {
                    printf("NO\n");
                    outputed = true;
                    break;
                }
            if(outputed) break;
        }
        if(outputed) continue;
        for(int a=1;a<=n;++a) {
            for(int b=1;b<=n;++b) {
                if(b == a) continue;
                if(!vis[a][b])continue;
                for(int c=1;c<=n;++c) {
                    if(c == a || c == b) continue;
                    if(vis[b][c]) {
                        if(vis[a][c]) {
                            disable[a][c] = true;
                        } else {
                            printf("NO\n");
                            outputed = true;
                            break;
                        }
                    }
                }
                if(outputed) break;
            }
            if(outputed) break;
        }
        if(outputed) continue;
        Dsu dsu(n);
        int edg_cnt = 0;
        for(int a=1;a<=n;++a) {
            for(int b=1;b<=n;++b) {
                if(b == a) continue;
                if(vis[a][b] && !disable[a][b]) {
                    ++edg_cnt;
                    if(!dsu.merge(a, b)) {
                        printf("NO\n");
                        outputed = true;
                        break;
                    }
                }
            }
            if(outputed)break;
        }
        if(outputed) continue;
        if(edg_cnt != n-1) {
            printf("NO\n");
            continue;
        }
        printf("Yes\n");
        for(int a=1;a<=n;++a) {
            for(int b=1;b<=n;++b) {
                if(b == a) continue;
                if(vis[a][b] && !disable[a][b])
                    printf("%d %d\n", a, b);
            }
        }
        
    }

    return 0;
}