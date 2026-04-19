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

int main() {
    int T;readInt(T);
    while(T--) {
        int n;readInt(n);
        std::vector<char> str(n+2);
        scanf("%s", str.begin() + 1);
        std::vector<bool> vis(n+2);
        int p = 1;
        vis[p] = 1;
        for(int i=1;i<=n;++i) {
            if(str[p] == 'L') {
                --p;
            } else {
                ++p;
            }
            vis[p] = 1;
        }
        int cnt = 0;
        for(int i=1;i<=n;++i)
            if(vis[i])
                ++cnt;
        printf("%d\n", cnt);
    }

    return 0;
}