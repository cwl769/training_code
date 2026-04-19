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
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        a[0] = INT_MAX;
        int mx = 0;
        int64 ans = 0;
        for(int i=1;i<=n;++i) {
            mx = std::max(mx, a[i]);
            if((i&1)==0) {
                a[i] = mx;
            }
        }
        if(a[1]>=a[2]) {
            ++ans;
            --a[1];
        }
        for(int i=3;i<=n;i+=2) {
            if(a[i]>=a[i-1])
                ans += a[i] - a[i-1] + 1;
        }
        printf("%lld\n", ans);
    }

    return 0;
}