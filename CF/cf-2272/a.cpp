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
#include <queue>
#include <stack>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

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
    veci a(n + 2);
    for (int i = 1; i <= n; ++i) {
        readInt(a[i]);
    }
    k = n - k + 1;
    veci cnt(n + 2), pos(n + 2);
    for (int i = 1; i <= k; ++i)
        ++cnt[a[i]];
    for (int i = 1; i <= k; ++i)
        pos[a[i]] = i;
    int mex = 0;
    while(cnt[mex]) ++mex;
    int found = 0;
    for (int i = 1 + k; i <= n; ++i) {
        if(a[i] == mex){
            found = i;
            break;
        }
    }
    if(!found) {
        printf("-1\n");
        return;
    }
    for (int v = 0; v <= n; ++v) {
        if(cnt[v] >= 2) {
            printf("%d %d\n", found, pos[v]);
            return;
        }
    }
    for (int v = n; v >= mex; --v) {
        if(cnt[v]) {
            printf("%d %d\n", found, pos[v]);
            return;
        }
    }
    printf("-1\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}