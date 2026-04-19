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
        int64 a, b;readInt(a, b);
        int n=1;
        for(;;++n) {
            int64 len0 = n / 2;
            int64 len1 = (n+1) / 2;
            int64 c0 = ((1ll<<(2ll*len0)) - 1ll) * 2ll / 3ll;
            int64 c1 = ((1ll<<(2ll*len1)) - 1ll) / 3ll;
            if(!(c0 <= a && c1 <= b) && !(c0 <= b && c1 <= a))
                break;
        }
        printf("%d\n", n - 1);
    }

    return 0;
}