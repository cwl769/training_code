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

char str[110];

int main() {
    int T;readInt(T);
    for(;T;--T) {
        scanf("%s", str);
        int cnt[2] = {0, 0};
        int n = strlen(str);
        for(int i=0;i<n;++i) {
            if(str[i] == 'N')++cnt[0];
            else ++cnt[1];
        }
        if(cnt[1]>1)printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}