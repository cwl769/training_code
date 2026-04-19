#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

typedef long long int64;

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

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;int64 x;readInt(n, x);
        std::vector<int64> a(n), b(n), c(n);
        for(int i=0;i<n;++i)
            readInt(a[i], b[i], c[i]);
        int64 base = 0;
        for(int i=0;i<n;++i) {
            base += a[i] * (b[i] - 1);
        }
        int64 mx = 0;
        for(int i=0;i<n;++i) {
            mx = std::max(mx, a[i] * b[i] - c[i]);
        }
        if(base >= x) {
            printf("0\n");
        } else if(mx == 0) {
            printf("-1\n");
        } else {
            printf("%lld\n", (x-base-1ll)/mx + 1);
        }
    }

    return 0;
}