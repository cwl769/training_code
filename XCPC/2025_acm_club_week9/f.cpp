#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
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
        int n, k;readInt(n, k);
        int tmp = sqrt(n);
        int ans = INT_MAX;
        for(int i=1;i<=k&&i<=tmp;++i) {
            if(n%i)continue;
            if(i*i==n) {
                ans = std::min(ans, i);
            } else {
                if(n/i<=k)ans = std::min(ans, i);
                else ans = std::min(ans, n/i);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}