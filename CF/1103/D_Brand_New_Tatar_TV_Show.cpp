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
    int n, k;readInt(n, k);
    veci a(n+2);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    std::sort(a.begin()+1, a.begin()+n+1);
    std::vector<veci> game(n+2);
    int tot = 1;
    game[tot].emplace_back(a[1]);
    for(int i=2;i<=n;++i) {
        if(a[i] - a[i-1] > k) {
            ++tot;
        }
        game[tot].emplace_back(a[i]);
    }
    for(int i=1;i<=tot;++i) {
        int mx = 0;
        for(auto x:game[i])
            mx = std::max(x, mx);
        int cntmx = 0;
        for(auto x:game[i]) {
            if(x == mx)
                ++cntmx;
        }
        if(cntmx & 1) {
            if(cntmx != (int)game[i].size()) {
                printf("YES\n");
                return;
            }
        } else {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}