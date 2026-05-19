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
    int n;readInt(n);
    veci64 c(n+1);
    for(int i=1;i<=n;++i)
        readInt(c[i]);
    if(n == 1 && c[1] == 2) {
        printf("0\n");
        return;
    }
    i64 cnt = 0;
    i64 ans = 0;
    i64 ins = 0;
    for(int i=1;i<=n;++i) {
        if(c[i] == 1) {
            ++cnt;
        }else {
            ans += c[i];
            if(c[i]>3ll)
                ins += (c[i] - 2ll) / 2ll;
        }
    }
    
    if(cnt==n-1) {
        ans += std::min(ans / 2ll, cnt);
        // ans += ans / 2ll;
    } else {
        ans += std::min(ins, cnt);
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