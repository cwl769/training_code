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

void solve() {
    int n, k;
    readInt(n, k);

    std::queue<int> q[2];
    if (n & 1) {
        if (k > n - 2) {
            printf("-1\n");
            return;
        }
        if (k & 1) {
            int m = n / 2;
            int t = k / 2;
            q[0].push(t + 2);
            for (int i = t + 3; i <= m+1; ++i)
                q[0].push(1);
            q[1].push(t + 1);
            for (int i = t + 2; i <= m; ++i)
                q[1].push(1);
        } else {
            int m = n / 2;
            int t = k / 2;
            q[0].push(t + 1);
            for (int i = t + 2; i <= m+1; ++i)
                q[0].push(1);
            q[1].push(t + 1);
            for (int i = t + 2; i <= m; ++i)
                q[1].push(1);
        }
    } else {
        if (k > n - 2) {
            printf("-1\n");
            return;
        }
        if (k & 1) {
            int m = n / 2;
            int t = k / 2;
            q[0].push(t + 1);
            for (int i = t + 2; i <= m; ++i)
                q[0].push(1);
            q[1].push(t + 2);
            for (int i = t + 3; i <= m; ++i)
                q[1].push(1);
        } else {
            int m = n / 2;
            int t = k / 2;
            q[0].push(t + 1);
            for (int i = t + 2; i <= m; ++i)
                q[0].push(1);
            q[1].push(t + 1);
            for (int i = t + 2; i <= m; ++i)
                q[1].push(1);
        }
    }
    for (int rnd = 0;; ++rnd) {
        int cur = (rnd & 1);
        if (q[cur].empty())
            break;
        int cnt = q[cur].front();
        q[cur].pop();
        for (int i = 0; i < cnt; ++i)
            printf("%d", cur);
    }
    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
