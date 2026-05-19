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

auto lower(const veci& vec, int x) {
    return std::lower_bound(vec.begin(), vec.end(), x);
}

auto upper(const veci& vec, int x) {
    return std::upper_bound(vec.begin(), vec.end(), x);
}

void solve() {
    itn n;readInt(n);
    veci a(n+2), b(n+2);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    for(int i=1;i<=n;++i)
        readInt(b[i]);
    std::vector<veci> sp(n+2), pa(n+2), pb(n+2);
    for(int v=0;v<=n;++v) {
        sp[v].push_back(0);
    }
    for(int i=1;i<=n;++i) {
        pa[a[i]].push_back(i);
        pb[b[i]].push_back(i);
        if(a[i]==b[i]) {
            sp[a[i]].push_back(i);
        }
    }
    for(int v=0;v<=n;++v) {
        sp[v].push_back(n+1);
    }
    i64 ans = 0;
    veci cur(n+2), r(n+2, n+1);
    for(int p=1;p<=n;++p) {
        sp[0][cur[0]] = p;

        int nc = 0;

        //update cur;
        for(int x=1;x<=n;++x) {
            int ori = sp[x][cur[x]];
            bool notchange = true;
            while(sp[x][cur[x]]<sp[x-1][cur[x-1]]) {
                notchange = false;
                ++cur[x];
            }
            if(ori==0&&sp[x][cur[x]]==n+1)
                notchange = true;

            nc = x;
            if(notchange) {
                break;
            }
        }
        
        //update r
        for(int x=nc;x>=1;--x) {
            int lx = n+1;
            int posxx = sp[x-1][cur[x-1]];
            int posx = sp[x][cur[x]];
            if(lower(pa[x], posxx) != lower(pa[x], posx)) {
                lx = std::min(lx, *lower(pa[x], posxx));
            }
            if(lower(pb[x], posxx) != lower(pb[x], posx)) {
                lx = std::min(lx, *lower(pb[x], posxx));
            }
            r[x] = std::min(r[x+1], lx);
        }
        ans += r[1] - p;
    }
    printf("%lld\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}