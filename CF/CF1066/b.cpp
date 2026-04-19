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
        int64 n, x, y;readInt(n, x, y);
        std::vector<char> str(n+2);
        scanf("%s", str.begin());
        int64 cnt4 = 0, cnt8 = 0;
        for(int i=0;i<n;++i) {
            if(str[i]=='4')
                ++cnt4;
            else
                ++cnt8;
        }
        x = std::abs(x);
        y = std::abs(y);
        int64 nd8 = std::min(x, y);
        int64 nd4 = std::abs(x - y);
        if(cnt8>=nd8) {
            if(cnt4+cnt8-nd8>=nd4)
                printf("YES\n");
            else
                printf("NO\n");
        } else {
            if(cnt4>=nd4+2ll*(nd8-cnt8))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}