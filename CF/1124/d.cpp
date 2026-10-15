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

bool can[16];

void solve() {
    int n, Q;readInt(n, Q);
    veci a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if(can[a[i]])
            ++ans;
    
    printf("%d ", ans);
    while(Q--) {
        int p, x;readInt(p, x);
        if(can[a[p]])
            --ans;
        a[p] = x;
        if(can[a[p]])
            ++ans;
        printf("%d ", ans);
    }
    printf("\n");
}

int main() {
    can[0] = 1;
    can[3] = 1;
    can[6] = 1;
    can[9] = 1;
    can[12] = 1;
    can[15] = 1;
    can[5] = 1;
    can[10] = 1;
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}