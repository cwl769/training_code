#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

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

char str[200010];

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        scanf("%s", str+1);
        int mx = 0;
        for(int i=1,tmp=0;i<=n;++i) {
            if(str[i]=='0') {
                ++tmp;
            } else {
                mx = std::max(mx, tmp);
                tmp = 0;
            }
            if(i==n) {
                mx = std::max(mx, tmp);
            }
        }

        if(str[1]=='0' && str[n]=='0') {
            int cnt = 0;
            for(int i=1;str[i]=='0';++i)
                ++cnt;
            for(int i=n;str[i]=='0';--i)
                ++cnt;
            mx = std::max(mx, cnt);
        }

        printf("%d\n", mx);
    }

    return 0;
}