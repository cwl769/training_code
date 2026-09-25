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

char str[200010];

void solve() {
    int n;
    readInt(n);
    scanf("%s", str + 1);
    if(str[1] == '1') {
        int ans = 0;
        for (int i = 2; i <= n; ++i)
            if(str[i] == '0')
                ++ans;
        printf("%d\n", ans);
    } else {
        veci sc[2];
        sc[0].resize(n + 2);
        sc[1].resize(n + 2);
        for (int i = 1; i <= n; ++i) {
            sc[0][i] = sc[0][i - 1];
            sc[1][i] = sc[1][i - 1];
            sc[str[i] - '0'][i]++;
        }
        int ans = n;
        for (int i = 1;i <= n; ++i) {
            int tmp = sc[1][i] + sc[0][n] - sc[0][i];
            ans = std::min(ans, tmp);
        }
        printf("%d\n", ans);
    }
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}