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

int64 lowbit(int64 x){return x&(-x);}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int64 l, r;readInt(l, r);
        int64 ans = std::min(lowbit(l), lowbit(r+1));
        int64 len = r - l + 1;
        if(lowbit(len) == len && len > 1) {
            int64 cov = (len<<1) - 1;
            if((l&cov)==len/2)
                ans <<= 1;
        }
        printf("%lld\n", ans - 1ll);
    }

    return 0;
}