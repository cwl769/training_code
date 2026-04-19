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
    int k;readInt(k);
    int64 ans = 0;
    int x = INT_MAX;
    for(int i=0;i<k;++i) {
        int y, l;readInt(y, l);
        if(y<=x)
            ans += l;
        else
            ans += l + 1000;
        x = y;
    }
    printf("%lld\n", ans);

    return 0;
}