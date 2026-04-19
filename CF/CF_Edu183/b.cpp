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

char str[200010];
char ans[200010];

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n, k;readInt(n, k);
        scanf("%s", str+1);
        int cnt2 = 0;
        for(int i=1;i<=k;++i)
            if(str[i]=='2')
                ++cnt2;
        for(int i=1;i<=n+1;++i)
            ans[i] = '\0';
        int a = 1, b = n;
        for(int i=1;i<=k;++i) {
            if(str[i] == '0') {
                ans[a] = '-';
                ++a;
            }
            if(str[i] == '1') {
                ans[b] = '-';
                --b;
            }
        }
        if(b - a + 1 <= cnt2) {
            for(int i=a;i<=b;++i)
                ans[i] = '-';
        } else {
            for(int i=a;i<a+cnt2;++i) {
                ans[i] = '?';
            }
            for(int i=b;i>b-cnt2;--i) {
                ans[i] = '?';
            }
        }
        for(int i=a+cnt2;i<=b-cnt2;++i)
            ans[i] = '+';
        printf("%s\n", ans+1);
    }

    return 0;
}