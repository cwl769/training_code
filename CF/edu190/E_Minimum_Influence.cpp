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

int p[200010], c[200010];
int prep[2000010], sufp[2000010];
int prec[2000010], sufc[2000010];

int tp[400010], tc[400010], d[400010];


const int inf = 0x3f3f3f3f;

int cal(int t, int d, int val) {
    if(val == inf)return inf;
    if(val < t)
        return 0;
    else if(val >= t+d)
        return t + d;
    else
        return val;
}

void solve() {
    itn n;readInt(n);
    for(int i=1;i<=n;++i) {
        readInt(p[i]);
    }
    for(int i=1;i<=n;++i) {
        readInt(c[i]);
    }
    memset(prep, 0x3f, sizeof(prep));
    memset(prec, 0x3f, sizeof(prec));
    memset(sufp, 0x3f, sizeof(sufp));
    memset(sufc, 0x3f, sizeof(sufc));
    for(int i=1;i<=n;++i) {
        prep[c[i]] = std::min(prep[c[i]], p[i]);
        sufp[c[i]] = std::min(sufp[c[i]], p[i]);
        prec[p[i]] = std::min(prec[p[i]], c[i]);
        sufc[p[i]] = std::min(sufc[p[i]], c[i]);
    }
    for(int i=1;i<2000010;++i) prep[i] = std::min(prep[i], prep[i-1]);
    for(int i=1;i<2000010;++i) prec[i] = std::min(prec[i], prec[i-1]);
    for(int i=2000008;i>=0;--i) sufp[i] = std::min(sufp[i], sufp[i+1]);
    for(int i=2000008;i>=0;--i) sufc[i] = std::min(sufc[i], sufc[i+1]);

    int minpc = inf;
    for(int i=1;i<=n;++i) {
        minpc = std::min(minpc, p[i] + c[i]);
    }
    
    int m;readInt(m);
    for(int i=1;i<=m;++i)readInt(tp[i]);
    for(int i=1;i<=m;++i)readInt(tc[i]);
    for(int i=1;i<=m;++i)readInt(d[i]);

    for(int i=1;i<=m;++i) {
        int ans = minpc;
        // printf("%d ", ans);
        if(tc[i])ans = std::min(ans, cal(tp[i], d[i], prep[tc[i]-1]));
        // printf("%d ", ans);
        if(tp[i])ans = std::min(ans, cal(tc[i], d[i], prec[tp[i]-1]));
        // printf("%d ", ans);
        ans = std::min(ans, cal(tp[i], d[i], sufp[tc[i]+d[i]]) + tc[i] + d[i]);
        // printf("%d ", ans);
        ans = std::min(ans, cal(tc[i], d[i], sufc[tp[i]+d[i]]) + tp[i] + d[i]);
        printf("%d\n", ans);
    }
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}