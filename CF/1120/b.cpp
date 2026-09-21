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

int map[1010][1010];

void solve() {
    int n, k;
    readInt(n, k);
    if(k < n || k >=n * 2) {
        printf("-1\n");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            map[i][j] = 0;
    }
    
    int rst = k - n;
    for (int i = 1; i <= n; ++i) {
        if(i > 1 && rst > 0) {
            --rst;
            map[i][1] = i;
        } else {
            map[i][i] = i;
        }
    }
    int cur = n + 1;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
        if(map[i][j] == 0) {
            map[i][j] = cur;
            ++cur;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            printf("%d ", map[i][j]);
        printf("\n");
    }
    
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}