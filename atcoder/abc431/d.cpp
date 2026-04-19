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
    int n;readInt(n);
    std::vector<int> w(n+1), h(n+1), b(n+1);
    for(int i=1;i<=n;++i) {
        readInt(w[i], h[i], b[i]);
    }
    int m = 0;
    for(int i=1;i<=n;++i)
        m += w[i];
    m >>= 1;
    std::vector<int64> f(m+1);
    for(int i=1;i<=n;++i) {
        for(int c=m;c>=0;--c) {
            f[c] += b[i];
            if(c-w[i]>=0)
                f[c] = std::max(f[c], f[c-w[i]]+h[i]);
        }
    }
    int64 ans = 0;
    for(int c=0;c<=m;++c)
        ans = std::max(ans, f[c]);
    printf("%lld\n", ans);

    return 0;
}