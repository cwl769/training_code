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
        int n;readInt(n);
        std::vector<int64> a(n+1), b(n+1), fmn(n+1), fmx(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        for(int i=1;i<=n;++i)
            readInt(b[i]);
        for(int i=1;i<=n;++i) {
            fmn[i] = std::min(fmn[i-1]-a[i], b[i]-fmx[i-1]);
            fmx[i] = std::max(fmx[i-1]-a[i], b[i]-fmn[i-1]);
        }
        // for(int i=1;i<=n;++i)
        //     printf("%lld ", fmn[i]);
        // printf("\n");
        // for(int i=1;i<=n;++i)
        //     printf("%lld ", fmx[i]);
        // printf("\n");
        printf("%lld\n", fmx[n]);
    }

    return 0;
}