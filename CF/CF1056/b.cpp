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
        if(k == n * n - 1) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for(int i=1,cnt=0;i<=k;++i) {
            putchar('U');
            ++cnt;
            if(cnt == n){
                cnt -= n;
                putchar('\n');
            }
        }
        int rst = n - k / n - 1;
        if(k%n==0) {
            ++rst;
        } else if(k%n==n-1) {
            putchar('D');
            putchar('\n');
        } else {
            int t = n - (k%n);
            putchar('R');
            for(int i=2;i<=t;++i)
                putchar('L');
            putchar('\n');
        }
        for(int i=1;i<=rst;++i) {
            putchar('R');
            for(int i=2;i<=n;++i)
                putchar('L');
            putchar('\n');
        }
    }

    return 0;
}