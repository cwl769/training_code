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
        int n;readInt(n);
        std::vector<std::vector<char> > map(n+2);
        for(int i=1;i<=n;++i)
            map[i].resize(n+2);
        for(int i=1;i<=n;++i)
            scanf("%s", map[i].begin()+1);
        bool ans = true;
        for(int i=1;i<=n;++i)
        for(int j=3;j<=n;++j)
            if(map[i][j]=='#'&&map[i][j-1]=='#'&&map[i][j-2]=='#') {
                ans = false;
                break;
            }
        if(!ans) {
            printf("NO\n");
            continue;
        }
        for(int i=3;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(map[i][j]=='#'&&map[i-1][j]=='#'&&map[i-2][j]=='#') {
                ans = false;
                break;
            }
        if(!ans) {
            printf("NO\n");
            continue;
        }
    }

    return 0;
}