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

bool check(const veci& b, const int n, int x, int y) {
    veci a(n+2, -1);
    a[1] = x, a[2] = y;
    for(int i=3;i<=n;++i) {
        if(a[i-1] == 0)break;
        a[i] = a[i-2] % a[i-1];
    }
    std::sort(a.begin()+1, a.begin()+n+1);
    for(int i=1;i<=n;++i){
        if(a[i] != b[i])
            return false;
    }
    return true;
}

void solve() {
    int n;readInt(n);
    veci b(n+2);
    for(int i=1;i<=n;++i) {
        readInt(b[i]);
    }
    std::sort(b.begin()+1, b.begin()+n+1);
    for(int i=1;i<=n;++i) {
        for(int j=i+1;j<=n;++j) {
            if(check(b, n, b[j], b[i])) {
                printf("%d %d\n", b[j], b[i]);
                return;
            }
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