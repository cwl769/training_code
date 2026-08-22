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
    int n;
    readInt(n);
    std::map<int, int, std::greater<int>> cnt;
    for (itn i = 1; i <= n; ++i) {
        int x;
        readInt(x);
        ++cnt[x];
    }
    int mx = cnt.begin()->first;
    if (mx >= n) {
        printf("No\n");
        return;
    }
    veci a(n + 2);
    for (int i = 1; i <= mx + 1; ++i) {
        auto it = cnt.lower_bound(i - 1);
        if (it == cnt.end()) {
            printf("No\n");
            return;
        }
        a[i] = it->first;
        --(it->second);
        if (it->second == 0)
            cnt.erase(it);
    }
    for (int i = mx + 2; i <= n; ++i) {
        auto it = cnt.begin();
        a[i] = it->first;
        --(it->second);
        if (it->second == 0)
            cnt.erase(it);
    }
    printf("Yes\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}
