#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <queue>
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
char first_or_second[10];

void dij(int st, const Graph& g, const int n, std::vector<int>& dis) {
    dis.resize(0);
    dis.resize(n+1, INT_MAX);
    std::priority_queue<std::pair<int64, int>, std::vector<std::pair<int64, int> >, std::greater<std::pair<int64, int> > > heap;
    dis[st] = 0;
    std::vector<bool> vis(n+1);
    heap.push({dis[st], st});
    while(!heap.empty()) {
        int x = heap.top().second;heap.pop();
        if(vis[x])continue;
        vis[x] = 1;
        for(auto y:g[x]) {
            if(dis[x] + 1 < dis[y]) {
                dis[y] = dis[x] + 1;
                heap.push({dis[y], y});
            }
        }
    }
}

char rgb[3] = {'r', 'g', 'b'};

int main() {
    scanf("%s", first_or_second);
    if(strcmp(first_or_second, "first") == 0) {
        int T;readInt(T);
        for(;T;--T) {
            int n, m;readInt(n, m);
            Graph g(n+1);
            for(int i=1;i<=m;++i) {
                int x, y;readInt(x, y);
                g[x].push_back(y);
                g[y].push_back(x);
            }
            std::vector<int> dis;
            dij(1, g, n, dis);
            for(int i=1;i<=n;++i)
                putchar(rgb[dis[i]%3]);
            putchar('\n');
        }
    } else {
        int T;readInt(T);
        for(;T;--T) {
            int q;readInt(q);
            for(;q;--q) {
                int n;readInt(n);
                std::vector<char> str(n+2);
                scanf("%s", str.begin());
                std::vector<int> cnt(128);
                for(int i=0;i<n;++i)
                    ++cnt[str[i]];
                if(cnt['r']==n || cnt['g']==n || cnt['b']==n) {
                    printf("1\n");
                }
                else if(cnt['r']==0) {
                    for(int i=0;i<n;++i) {
                        if(str[i]=='b') {
                            printf("%d\n", i+1);
                            break;
                        }
                    }
                } else if(cnt['g']==0) {
                    for(int i=0;i<n;++i) {
                        if(str[i]=='r') {
                            printf("%d\n", i+1);
                            break;
                        }
                    }
                } else if(cnt['b']==0) {
                    for(int i=0;i<n;++i) {
                        if(str[i]=='g') {
                            printf("%d\n", i+1);
                            break;
                        }
                    }
                }
            }
        }
    }

    return 0;
}