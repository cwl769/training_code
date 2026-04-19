#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
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

const int dx[4] = { 0, 0, 1,-1};
const int dy[4] = { 1,-1, 0, 0};

bool check(const std::vector<std::vector<char> >& map, int x, int y, int cur_lvl, const int n, const int m, const std::vector<std::vector<int> >& lvl) {
    int cnt = 0;
    for(int i=0;i<4;++i) {
        if(x + dx[i] > n || x + dx[i] < 1 || y + dy[i] > m || y + dy[i] < 1)
            continue;
        if(map[x+dx[i]][y+dy[i]] == '#' && cur_lvl != lvl[x+dx[i]][y+dy[i]]) ++cnt;
    }
    if(cnt == 1)return true;
    return false;
}

int main() {
    int n, m;readInt(n, m);
    std::vector<std::vector<char> > map(n+2);
    std::vector<std::vector<int> > lvl(n+2);
    for(int i=1;i<=n;++i) {
        map[i].resize(m+2);
        lvl[i].resize(m+2);
        scanf("%s", map[i].begin() + 1);
    }
    int ans = 0;
    std::queue<std::pair<int, int> > queue;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j) {
        if(map[i][j] == '#') {
            queue.push({i, j});
            lvl[i][j] = 1;
            ++ans;
        }
    }
    while(queue.size()) {
        int x = queue.front().first;
        int y = queue.front().second;
        queue.pop();
        int cur_lvl = lvl[x][y];
        for(int i=0;i<4;++i) {
            if(x + dx[i] > n || x + dx[i] < 1 || y + dy[i] > m || y + dy[i] < 1)
                continue;
            if(map[x+dx[i]][y+dy[i]] == '#')
                continue;
            if(check(map, x+dx[i], y+dy[i], cur_lvl + 1, n, m, lvl)) {
                map[x+dx[i]][y+dy[i]] = '#';
                lvl[x+dx[i]][y+dy[i]] = cur_lvl + 1;
                queue.push({x+dx[i], y+dy[i]});
                ++ans;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}