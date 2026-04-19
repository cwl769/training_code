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

typedef long long int64;
typedef long long i64;
typedef unsigned long long ui64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;


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
    int n, m, k;readInt(n, m, k);
    int s = n * m;
    veci a(s + 1);
    for(int i=1;i<=s;++i) {
        readInt(a[i]);
    }
    std::vector<veci> p(n+1);
    for(int i=1;i<=s;++i) {
        int rowid = (a[i] - 1) / m + 1;
        p[rowid].push_back(i);
    }
    for(int i=1;i<=n;++i)
        std::sort(p[i].begin(), p[i].end());
    int ans = INT_MAX;
    for(int i=1;i<=n;++i) {
        if(k >= m) {
            ans = std::min(ans, m);
        } else {
            for(int t=0;t<k;++t)
                p[i].pop_back();
            if(*p[i].rbegin() > m)
                ans = std::min(ans, *p[i].rbegin());
            else
                ans = std::min(ans, m);
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}