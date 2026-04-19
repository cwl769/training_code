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
        int n, k;readInt(n, k);
        k %= 4;
        if(k==0) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        if(k==2) {
            for(int i=1;i<=n/2;++i) {
                int x = i * 2 - 1;
                int y = x + 1;
                if(i&1)printf("%d %d\n", y, x);
                else printf("%d %d\n", x, y);
            }
            continue;
        }
        for(int i=1;i<=n/2;++i) {
            printf("%d %d\n", i * 2 - 1, i * 2);
        }
    }

    return 0;
}