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
#include <queue>
typedef std::vector<veci> Graph;

char map[100][100];
int nd[100][100];

int cal(int st, const int n, const Graph& g, const veci &val) {
    std::vector<bool> vis(n + 2);
    std::queue<int> q;
    q.emplace(st);
    vis[st] = 1;
    while(q.size()) {
        int x = q.front();
        q.pop();
        for (auto y : g[x]) {
            if(vis[y])
                continue;
            q.emplace(y);
            vis[y] = 1;
        }
    }
    int ans = 0;
    for (int x = 1; x <= n; ++x) {
        if(vis[x])
            ans += val[x];
    }
    return ans;
}

void solve() {
    int n, m;
    readInt(n, m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", map[i] + 1);
    int tot = 0;
    Graph g(n * m + 2);
    veci val(n * m + 2);
    for (int i = n; i >= 1; --i) {
        int last = 1;
        for (int j = 1; j <= m; ++j) {
            if (map[i][j] == '#') {
                last = j + 1;
                continue;
            }
            if (j == m || map[i][j + 1] == '#') {
                ++tot;
                // printf("tot = %d| %d [%d, %d]\n", tot, i, last, j);
                std::set<int> nxt;
                for(int t = last; t <= j; ++t) {
                    if(map[i][t] == '+')
                        ++val[tot];
                    else
                        --val[tot];
                    nd[i][t] = tot;
                    if(i < n && map[i + 1][t] != '#') {
                        nxt.emplace(nd[i + 1][t]);
                    }
                }
                for(auto s : nxt) {
                    g[tot].emplace_back(s);
                    printf("%d -> %d\n", tot, s);
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            printf("%d ", nd[i][j]);
        printf("\n");
    }

    for (int i = 1; i <= tot; ++i)
        printf("%2d ", val[i]);
    printf("\n");

    // ++tot;
    // std::set<int> nxt1;
    // for (int j = 1; j <= m; ++j) {
    //     if(map[1][j] != '#')
    //         nxt1.emplace(nd[1][j]);
    // }
    // for (auto s : nxt1) {
    //     g[tot].emplace_back(s);
    // }

    veci dp[2];
    dp[0].resize(tot + 2);
    dp[1].resize(tot + 2);

    for (int x = 1; x <= tot; ++x) {
        for (auto y : g[x]) {
            dp[0][x] += std::min(dp[0][y], dp[1][y]);
        }
        dp[1][x] = cal(x, tot, g, val);
    }


    for (int i = 1; i <= tot; ++i)
        printf("%2d ", dp[0][i]);
    printf("\n");
    for (int i = 1; i <= tot; ++i)
        printf("%2d ", dp[1][i]);
    printf("\n");

    veci dgr(tot + 2);
    for (int x = 1; x <= tot; ++x) {
        for (auto y : g[x]) {
            ++dgr[y];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
        if (map[i][j] == '+')
            ++ans;
        if (map[i][j] == '-')
            --ans;
    }
    for (int x = 1; x <= tot; ++x) {
        if(dgr[x] == 0) {
            ans -= std::min(dp[0][x], dp[1][x]);
        }
    }
    printf("%d\n", ans);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}
