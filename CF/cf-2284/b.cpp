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

bool check(int n, int k, veci& a) {
    i64 sum = a[1];
    int cnt = 1;
    for (int i = 2; i <= n; ++i) {
        if(1ll * a[i] * (i - 1ll) >= sum)
            ++cnt;

        sum += a[i];
    }
    return cnt == k;
}

void solve() {
    int n, k;readInt(n, k);
    veci a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    std::sort(a.begin() + 1, a.begin() + n + 1, std::greater<int>());
    std::reverse(a.begin() + 1, a.begin() + k + 1);

    if(!check(n, k, a)) {
        printf("NO\n");

        return;
    }

    printf("YES\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}