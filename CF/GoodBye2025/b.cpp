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
        scanf("%s", str+1);
        int n = strlen(str+1);
        int ans = 0;
        if(str[1]=='u') {
            ++ans;
            str[1] = 's';
        }
        if(str[n]=='u') {
            ++ans;
            str[n] = 's';
        }
        int tmp = 0;
        for(int i=1;i<=n;++i) {
            if(str[i] == 'u') {
                ++tmp;
            } else {
                ans += tmp / 2;
                tmp = 0;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}