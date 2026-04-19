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
        std::vector<int64> x(n+2);
        x[0] = -2e10;
        x[n+1] = 3e10;
        for(int i=1;i<=n;++i) {
            readInt(x[i]);
        }
        int64 low = 0, up = x[2] - x[1];
        int64 ans = 0;
        for(int t=2;t<=n;++t) {
            int64 tmpl = x[t] - x[t-1], tmpr = x[t+1] - x[t];
            int64 curlow = 0, curup = tmpr;

            // printf("[%d] %lld %lld\n", t, low, up);
            int64 nlow = tmpl - up;
            int64 nup = tmpl - low;
            low = std::max(curlow, nlow);
            up = std::min(curup, nup);

            // printf("%lld %lld\n", low, up);

            if(low>=up) {
                low = 0;
                up = std::min(tmpl, tmpr);
            } else {
                ++ans;
                // printf("add ans at %d\n", t);
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}