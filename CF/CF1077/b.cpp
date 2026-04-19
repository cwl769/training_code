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

int ceil_2(int x) {
    return (x-1) / 3 + 1;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<char> str(n+2);
        scanf("%s", str.begin() + 1);
        int ans = 0;
        int st=1;
        while(str[st]=='0')++st;
        int ed=n;
        while(str[ed]=='0')--ed;
        if(st==n+1 || ed==0) {
            printf("%d\n", ceil_2(n));
            continue;
        }
        if(st>2)
            ans += ceil_2(st - 2);
        if(n-ed-1>0)
            ans += ceil_2(n-ed-1);

        for(int i=st,tmp=0;i<=ed;++i) {
            if(str[i]=='0') {
                ++tmp;
            } else {
                ++ans;
                // printf("tmp:%d\n", tmp);
                if(tmp>2)
                    ans += ceil_2(tmp - 2);
                tmp = 0;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}