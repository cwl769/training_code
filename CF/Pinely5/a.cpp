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

char str[1010];

int main() {
    int T;readInt(T);
    for(;T;--T) {
        std::vector<int64> R(1);
        int64 x, d, n;
        readInt(R[0], x, d, n);
        R.resize(n+1);
        scanf("%s", str+1);
        int64 l = R[0], r = R[0];
        int ans = 0;
        for(int i=1;i<=n;++i) {
            if(str[i]=='1') {
                r += d;
                l -= d;
                ++ans;
                continue;
            }
            if(l<x) {
                ++ans;
                r = std::min(r, x - 1);
                l = std::max(0ll, l - d);
                r = r + d;
            } else {
                continue;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}