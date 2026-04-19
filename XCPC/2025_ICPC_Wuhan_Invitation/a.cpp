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
typedef std::vector<int> vector;

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
    int n, q;
    readInt(n, q);
    std::vector<int> a(n+1);
    std::vector<int> lb(n+1, 0), ub(n+1, 2e9);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    while(q--) {
        int p, l, r;
        readInt(p, l, r);
        lb[p] = std::max(lb[p], l);
        ub[p] = std::min(ub[p], r);
    }
    for(int i=1;i<=n;++i) {
        if(lb[i] > ub[i]) {
            printf("-1\n");
            return;
        }
    }
    int64 ans = 0;
    for(int i=1;i<=n;++i) {
        if(a[i] < lb[i]) {
            ans += lb[i] - a[i];
        } else if(a[i] > ub[i]){
            ans += a[i] - ub[i];
        }
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