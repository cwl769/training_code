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

int dis(int a, int b, const int n) {
    int tmp = std::abs(a - b);
    return std::min(tmp, n - tmp);
}

int prev(int x, int n) {
    return (x==0)?(n-1):x-1;
}
int next(int x, int n) {
    return (x==n-1)?0:x+1;
}

void solve() {
    int n, x1, x2, k;
    readInt(n, x1, x2, k);
    --x1;
    --x2;
    if(n==2 || n==3) {
        printf("1\n");
        return;
    }
    int d = dis(x1, x2, n);
    // d = std::min(d, n/2-1);
    int tmp = 0;
    if(d > n/2-1) {
        d = n/2-1;
        ++tmp;
    }
    if(k == 0)
        printf("%d\n", dis(x1, x2, n));
    else
        printf("%d\n", tmp + k + d);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}