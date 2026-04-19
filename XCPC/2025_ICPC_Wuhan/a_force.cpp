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

const int64 M = 1000000007;

int64 floor(int64 a, int64 b) {//[a/b]
    if(a%b==0)return a/b;
    if((a>0&&b>0)||(a<0&&b<0)) {
        return a/b;
    }
    return a/b - 1;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int64 f, x, g, y, n, m;readInt(f, x, g, y, n, m);
        int64 tmp = 0;
        for(int64 k=0;k<n;++k) {
            tmp += floor(k*(g-f)+(y-x-1), m);
        }
        printf("%lld\n", tmp);
    }

    return 0;
}