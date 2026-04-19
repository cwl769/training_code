#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

typedef long long int64;
typedef std::vector<int> vector;

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

int func(int x) {
    int tmp = sqrt(x);
    int ans = 0;
    for(int d=1;d<=tmp;++d) {
        if(x % d == 0) {
            ++ans;
            if(d * d != x) {
                ++ans;
            }
        }
    }
    return ans;
}

int main() {
    int T;readInt(T);
    while(T--) {
        int x, y;readInt(x, y);
        if( x == y ) {
            printf("1\n");
            for(int i=1;i<=x;++i)
                printf("1 ");
            for(int i=1;i<=y;++i)
                printf("-1 ");
            printf("\n");
        } else if(x > y) {
            int sum = x - y;
            printf("%d\n", func(sum));
            
            for(int i=1;i<=y;++i)
                printf("-1 ");
            for(int i=1;i<=x;++i)
                printf("1 ");
            printf("\n");
        } else {
            int sum = x - y;
            printf("%d\n", func(-sum));
            
            for(int i=1;i<=x;++i)
                printf("1 ");
            for(int i=1;i<=y;++i)
                printf("-1 ");
            printf("\n");
        }
    }

    return 0;
}