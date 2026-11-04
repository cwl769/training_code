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

char str[10][10];

int x[256], y[256];

int dis(int x1, int y1, int x2, int y2) {
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

void solve() {
    scanf("%s", str[1] + 1);
    scanf("%s", str[2] + 1);
    for (int i = 1; i <= 2; ++i)
    for (int j = 1; j <= 2; ++j) {
        x[str[i][j]] = i;
        y[str[i][j]] = j;
    }
    if(dis(x['A'], y['A'], x['D'], y['D']) == 1)
        printf("Yes\n");
    else 

        printf("No\n");
}

int main() {
    // int T;readInt(T);
    // while(T--)
        solve();

    return 0;
}