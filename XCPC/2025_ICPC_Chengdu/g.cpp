#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>

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
        int64 n, k, m;readInt(n, k, m);
        if(m==n) {
            printf("%lld\n", n);
            continue;
        }
        if(m>n-(((n / k - 1ll) / 2ll)*2ll)-1ll) {
            printf("%lld\n", m+1+(n-m-1)/2);
        } else {
            printf("%lld\n", (n / k - 1ll) / 2ll + 1ll + m);
        }
    }

    return 0;
}