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
        int n, a, b;readInt(n, a, b);
        bool rs, bs;
        rs = ((n&1) == (a&1));
        bs = ((n&1) == (b&1));
        if(!bs) {
            printf("NO\n");
        } else if (rs || a < b) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}