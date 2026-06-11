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

char str[100];
bool valid[10];
int mn, mx;

void dfs(int dep, i64 b, const i64 a, const int len, bool bg, bool sm, i64 &ans) {
    if(dep == len) {
        ans = std::min(ans, std::abs(b - a));
        return;
    }
    if(bg || sm) {
        if(bg) {
            dfs(dep+1, b*10ll+mn, a, len, bg, sm, ans);
        } else {
            dfs(dep+1, b*10ll+mx, a, len, bg, sm, ans);
        }
        return;
    }
    if(valid[str[dep]-'0']) {
        dfs(dep+1, b*10ll+(str[dep]-'0'), a, len, bg, sm, ans);
    }
    for(int j=str[dep]-'0'+1;j<10;++j) {
        if(valid[j]) {
            dfs(dep+1, b*10ll+j, a, len, 1, sm, ans);
            break;
        }
    }
    for(int j=str[dep]-'0'-1;j>-1;--j) {
        if(valid[j]) {
            dfs(dep+1, b*10ll+j, a, len, bg, 1, ans);
            break;
        }
    }
}

void solve() {
    i64 a = 0, n;
    scanf("%s", str);
    readInt(n);
    for(int i=0;;++i) {
        if(str[i] == '\0')
            break;
        a = a * 10ll + (str[i] - '0');
    }
    for(int i=0;i<10;++i)
        valid[i] = 0;
    for(int i=1;i<=n;++i) {
        int x;readInt(x);
        valid[x] = 1;
    }
    mn = 10, mx = -1;
    for(int i=0;i<10;++i) {
        if(valid[i]){
            mn = std::min(i, mn);
            mx = std::max(i, mx);
        }
    }

    i64 ans = LLONG_MAX;
    int len = strlen(str);
    dfs(0, 0, a, len, 0, 0, ans);
    
    __int128_t tmpbg = mn;
    for(int i=0;i<len;++i)
        tmpbg = tmpbg * 10ll + mn;
    ans = std::min((__int128_t)ans, tmpbg - a);
    i64 tmpsm = 0;
    for(int i=1;i<len;++i)
        tmpsm = tmpsm * 10ll + mx;
    if(len > 1)
        ans = std::min(ans, a - tmpsm);
    printf("%lld\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}