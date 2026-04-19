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
        int n;readInt(n);
        std::vector<int64> a(n+2);
        std::vector<int64> remain(n+2);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        for(int i=2;i<=n;i+=2)
            remain[i] = a[i-1] + a[i+1] - a[i];
        int64 ans = 0;
        for(int i=1;i<=n;i+=2) {
            if(remain[i-1]>0 && remain[i+1]>0) {
                int64 t = std::min(remain[i-1], remain[i+1]);
                t = std::min(t, a[i]);
                ans += t;
                a[i] -= t;
                remain[i-1] -= t;
                remain[i+1] -= t;

            }
        }
        for(int i=1;i<=n;i+=2) {
            if(remain[i-1]>0) {
                int64 t = std::min(a[i], remain[i-1]);
                ans += t;
                a[i] -= t;
                remain[i-1] -= t;
                remain[i+1] -= t;
            }
            if(remain[i+1]>0) {
                int64 t = std::min(a[i], remain[i+1]);
                ans += t;
                a[i] -= t;
                remain[i-1] -= t;
                remain[i+1] -= t;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}