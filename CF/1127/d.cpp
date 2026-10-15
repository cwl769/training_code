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
    if(n % 3 == 1) {
        printf("%d\n", 3 * n - 2);
        // printf("%d\n", n);
        for (int i = n + n - 2; i >= 2; i -= 2)
            printf("%d ", i);
        for (int i = n + n; i >= 2; i -= 2)
            printf("%d ", i);
        for (int i = n + n; i >= 4; i -= 2)
            printf("%d ", i);
        return;
    }
    printf("%d\n", 3 * n - 3);
    // printf("%d\n", n);
    for (int i = n + n - 1; i >= 3; i -= 2)
        printf("%d ", i);
    for (int i = n + n - 1; i >= 3; i -= 2)
        printf("%d ", i);
    for (int i = n + n - 1; i >= 3; i -= 2)
        printf("%d ", i);
    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}