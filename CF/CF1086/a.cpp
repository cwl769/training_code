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

int map[110][110];

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            readInt(map[i][j]);
        std::vector<int> cnt(n*n+1);
        for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            ++cnt[map[i][j]];
        bool ans = true;
        for(int c=1;c<=n*n;++c) {
            if(cnt[c] > n*n - n) {
                printf("NO\n");
                ans = false;
                break;
            }
        }
        if(ans)
            printf("YES\n");
    }

    return 0;
}