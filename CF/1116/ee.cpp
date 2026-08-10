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

int cal(int n, int x, veci c) {
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = (ans + c[i] * (i - x + n) % n) % n;
    return ans;
}

char map[810][810];

void solve1() {
    int n;readInt(n);
    for (int i = 0; i < n; ++i)
        scanf("%s", map[i]);
    int x, y;
    readInt(x, y);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (map[i][j] == '#')
                map[i][j] = 1;
            else
                map[i][j] = 0;
        }
    
    --x, --y;
    int sx = 0, sy = 0;
    veci cx(n), cy(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (map[i][j]) {
                ++cx[i];
                ++cy[j];
            }
        }
    sx = cal(n, x, cx);
    sy = cal(n, y, cy);
    int dx = (n - sx) % n;
    int dy = (n - sy) % n;
    // printf("debug: %d %d %d %d\n", sx, sy, dx, dy);
    if (dx == 0 && dy == 0) {
        printf("1 1 1 1\n");
        return;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (map[i][j]) {
                if (!map[(i + dx) % n][(j + dy) % n]) {
                    printf("%d %d %d %d\n", i + 1, j + 1, (i + dx) % n + 1, (j + dy) % n + 1);
                    return;
                }
            }
}

void solve2() {
    int n;readInt(n);
    for (int i = 0; i < n; ++i)
        scanf("%s", map[i]);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (map[i][j] == '#')
                map[i][j] = 1;
            else
                map[i][j] = 0;
        }
    
    veci cx(n), cy(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (map[i][j]) {
                ++cx[i];
                ++cy[j];
            }
        }
    int x = 0, y = 0;
    while (cal(n, x, cx))
        ++x;
    while (cal(n, y, cy))
        ++y;
    printf("%d %d\n", x + 1, y + 1);
}

char which_round[10];
int main() {
    scanf("%s", which_round);
    int T;readInt(T);
    while(T--) {
        if (which_round[0] == 'f') {
            solve1();
        } else {
            solve2();
        }
    }

    return 0;
}
