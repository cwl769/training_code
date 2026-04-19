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
    int n;readInt(n);
    veci a(n+1);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    std::sort(a.begin() + 1, a.end(), std::greater<int> ());
    bool noans = false;
    for(int i=2;i<=n;++i) {
        if(a[i] == a[i-1]) {
            noans = true;
            break;
        }
    }
    if(noans) {
        printf("-1\n");
    } else {
        for(int i=1;i<=n;++i)
            printf("%d ", a[i]);
        printf("\n");
    }
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}