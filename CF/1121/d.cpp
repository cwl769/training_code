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

void solve() {
    int n;readInt(n);
    if(n == 1)
        printf("1\n");
    else if(n == 2)
        printf("11\n");
    else if(n == 3)
        printf("101\n");
    else if(n == 4)
        printf("0101\n");
    else if(n == 5)
        printf("10101\n");
    else if(n == 6)
        printf("010100\n");
    else {
        veci ans(n + 2);
        ans[1] = 1;
        int t = (n + 2) / 3;
        ans[t + 1] = 1;
        if(t&1)
            ans[t + t] = 1;
        else
            ans[t + t + 1] = 1;
        for (int i = 1; i <= n; ++i)
            printf("%d", ans[i]);
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