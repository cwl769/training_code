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
    int ans;readInt(ans);
    int n;readInt(n);
    std::vector<int> w(n+1);
    for(int i=1;i<=n;++i)
        readInt(w[i]);
    std::vector<bool> vis(n+1);
    int q;readInt(q);
    for(;q;--q) {
        int x;readInt(x);
        if(vis[x]) {
            ans -= w[x];
            vis[x] = 0;
        } else {
            ans += w[x];
            vis[x] = 1;
        }
        printf("%d\n", ans);
    }

    return 0;
}