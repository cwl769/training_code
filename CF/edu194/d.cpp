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
#include <queue>
#include <stack>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

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

char str[300010];
bool can[300010][9];

bool check(int n, const veci& a, int m) {
    for (int i = 0; i <= n; ++i)
        for(int v = 0; v < 9; ++v)
            can[i][v] = 0;
    can[0][4] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int c = 0; c < 9; ++c) {
            for (int j = std::max(0, c - m); j < 9 && j <= c + m; ++j){
                if(j == c)
                    continue;
                can[i][c] |= can[i - 1][j];
            }
        }
        if(a[i] == 0) {
            can[i][0] = 0;
            can[i][1] = 0;
            can[i][2] = 0;
            can[i][3] = 0;
            can[i][5] = 0;
            can[i][6] = 0;
            can[i][7] = 0;
            can[i][8] = 0;
        } else if(a[i] > 0) {
            can[i][0] = 0;
            can[i][1] = 0;
            can[i][2] = 0;
            can[i][3] = 0;
            can[i][4] = 0;
        } else {
            can[i][4] = 0;
            can[i][5] = 0;
            can[i][6] = 0;
            can[i][7] = 0;
            can[i][8] = 0;
        }
        bool all0 = true;
        for (int c = 0; c < 9; ++c)
            if(can[i][c])
                all0 = false;
        if(all0)
            return false;
    }
    return true;
}

void solve() {
    int n;readInt(n);
    scanf("%s", str + 1);
    veci a(n + 2);
    for (int i = 1; i <= n; ++i) {
        if(str[i] == '0')
            a[i] = 0;
        else if(str[i] == '+')
            a[i] = 1;
        else if(str[i] == '-')
            a[i] = -1;
    }
    for (int i = 1; i <= n; ++i)
        if(a[i] == 0 && a[i - 1] == 0) {
            printf("-1\n");
            return;
        }
    int ans = 4;
    if(check(n, a, 3))
        ans = 3;
    if(check(n, a, 2))
        ans = 2;
    if(check(n, a, 1))
        ans = 1;
    if(check(n, a, 0))
        ans = 0;
    printf("%d\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}