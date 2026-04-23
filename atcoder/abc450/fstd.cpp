#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

#define debug(...) fprintf(stderr, __VA_ARGS__)

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

void solve() {
    itn n, m;readInt(n, m);
    --n;
    veci64 dps(n+1);
    std::vector<veci> ls(n+1);
    std::vector<std::pair<int, int> > a;
    for(int i=1;i<=m;++i) {
        int x, y;readInt(x, y);
        --y;
        a.push_back({x, y});
    }
    int tar = (1<<m);
    int ans = 0;
    std::vector<bool> vis(100);
    for(int s=0;s<tar;++s) {
        for(int i=1;i<=n;++i)
            vis[i] = 0;
        for(int t=0;t<m;++t)
            if((s>>t)&1) {
                for(int i=a[t].first;i<=a[t].second;++i)
                    vis[i] = 1;
            }
        bool all1 = true;
        for(int i=1;i<=n;++i) {
            if(!vis[i]) {
                all1 = false;
                break;
            }
        }
        if(all1)++ans;
    }
    printf("%d\n", ans);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}