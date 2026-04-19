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

int64 a[200010];

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        std::vector<int64> f[2];
        f[0].resize(n+1);f[1].resize(n+1);
        f[0][1] = a[1];
        f[1][1] = LONG_LONG_MAX;
        for(int i=2;i<=n;++i) {
            f[0][i] = std::min(f[0][i-1], f[1][i-1]) + a[i];
            f[1][i] = f[0][i-1] + std::max(0ll, a[i] - (int64)i + 1ll);
        }
        for(int i=0;i<=1;++i) {
            for(int j=1;j<=n;++j)
                printf("%2lld ", f[i][j]);
            printf("\n");
        }
        printf("%lld\n", std::min(f[0][n], f[1][n]));
        
    }

    return 0;
}