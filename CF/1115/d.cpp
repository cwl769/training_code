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

void solve() {
    int n;
    readInt(n);
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    veci64 b(n + 2);
    b[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        b[i] = a[i] - a[i-1];
    }
    veci ch(n + 2);
    for (int i = 2; i < n; ++i) {
        if ((a[i - 1] & 1) == (a[i + 1] & 1))
            ch[i] = 1;
    }

    int last = 1;
    for (int i = 2; i < n; ++i) {
        if (ch[i] == 0) {
            last = i;
            continue;
        }
        if (ch[i + 1])
            continue;
        int l = last + 1;
        int r = i + 1;
        std::sort(b.begin() + l, b.begin() + r + 1);
    }

    for (int i = 2; i <= n; ++i) {
        a[i] = a[i-1] + b[i];
    }
    for (int i = 1; i <= n; ++i)
        printf("%lld ", a[i]);
    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
