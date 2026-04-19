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
    int n;readInt(n);
    if(n&1) {
        for(int i=0;i<n;++i) {
            printf("%d ", i);
        }
        printf("\n");
        for(int i=1;i<=n;++i) {
            printf("%d ", i%n);
        }
        printf("\n");
        for(int i=0;i<n;++i) {
            printf("%d ", (2*i+1)%n);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }

    return 0;
}