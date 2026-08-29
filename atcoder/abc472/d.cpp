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

int dx[4] = { 0, 0, 1,-1};
int dy[4] = { 1,-1, 0, 0};

void solve() {
    int n, m, k;
    readInt(n, m, k);
    std::vector<std::vector<char> > map(n + 2);
    std::vector<std::vector<int> > dis(n + 2);
    for (int i = 1; i <= n; ++i) {
        map[i].resize(m + 2);
        dis[i].resize(m + 2, 0x3f3f3f3f);
        scanf("%s", &map[i][1]);
    }
    std::vector<bool> sa(n + 2), sb(m + 2);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if(map[i][j] == '#')
                sa[i] = sb[j] = 1;
        }
    std::queue<std::pair<int, int> > q;
    for (int i = 1; i <= n; ++i) {
        if(sa[i])
            continue;
        for (int j = 1; j <= m; ++j) {
            if(sb[j])
                continue;
            q.emplace(i, j);
            dis[i][j] = 0;
        }
    }
    while(q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx < 1 || tx > n || ty < 1 || ty > m)
                continue;
            if(map[tx][ty] == '#')
                continue;
            if(dis[x][y] + 1 < dis[tx][ty]) {
                dis[tx][ty] = dis[x][y] + 1;
                q.emplace(tx, ty);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(dis[i][j] <= k)
                ++ans;
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
