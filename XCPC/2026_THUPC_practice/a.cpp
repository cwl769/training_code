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

char map[1010][1010];

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n, m;readInt(n, m);
        for(int i=1;i<=n;++i)
            scanf("%s", map[i] + 1);
        std::vector<bool> srow(n+1), scol(m+1);
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=m;++j) {
                srow[i] = (srow[i] ^ (map[i][j] - '0'));
                scol[j] = (scol[j] ^ (map[i][j] - '0'));
            }
        }
        int cr = 0, cc = 0;
        for(int i=1;i<=n;++i)
            if(srow[i])++cr;
        for(int j=1;j<=m;++j)
            if(scol[j])++cc;
        printf("%d\n", std::min(cr, cc) + (std::max(cr, cc) - std::min(cr, cc)));
    }

    return 0;
}