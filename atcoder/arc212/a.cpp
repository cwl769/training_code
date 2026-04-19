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

const int64 M = 998244353;

int main() {
    int64 k;readInt(k);
    int64 ans = 0;
    for(int64 a=2;a<=k;++a)
    for(int64 b=a;b<=k;++b) {
        int64 c = k - a - b;
        if(c<b)break;
        if(a == b && b == c) {
            int64 tmp = 0;
            tmp = 1ll * (a - 1ll) * (b - 1ll) * (c - 1ll);
            ans = (ans + tmp * (a + b) % M) % M;
        } else if(a == b || b == c || a == c) {
            int64 tmp = 0;
            tmp = 3ll * (a - 1ll) * (b - 1ll) * (c - 1ll);
            ans = (ans + tmp * (a + b) % M) % M;
        } else {
            int64 tmp = 0;
            tmp = 6ll * (a - 1ll) * (b - 1ll) * (c - 1ll);
            ans = (ans + tmp * (a + b) % M) % M;
        }
    }
    printf("%lld\n", ans);

    return 0;
}