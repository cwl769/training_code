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

int count(int x) {
    int ans = 0;
    while(x) {
        x>>=1;
        ++ans;
    }
    return ans;
}

int main() {
    // printf("%d\n", cnt(0b100));
    // fflush(stdout);
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        if(n==0) {
            printf("YES\n");
            continue;
        }
        while(!(n&1))n>>=1;
        int cnt = count(n);
        if(cnt&1) {
            if( 1 & (n>>(cnt/2)) ) {
                printf("NO\n");
                continue;
            }
        }
        bool flag = true;
        for(int i=0;i<cnt;++i) {
            if(((n>>i)&1)!=((n>>(cnt-1-i))&1)) {
                printf("NO\n");
                flag = false;
                break;
            }
        }
        if(flag)
            printf("YES\n");
    }

    return 0;
}