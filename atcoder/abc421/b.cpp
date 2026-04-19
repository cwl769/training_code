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

int64 f(int64 x) {
    int64 ans = 0;
    for(;x;x/=10) {
        ans = ans * 10 + (x % 10);
    }
    return ans;
}

int main() {
    int64 x, y;readInt(x, y);
    int64 ans;
    for(int i=3;i<=10;++i) {
        ans = f(x + y);
        x = y;
        y = ans;
    }
    printf("%lld", ans);

    return 0;
}