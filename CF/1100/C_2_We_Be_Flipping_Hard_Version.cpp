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

void flip(int n, veci& ans, const veci64& a) {
    int last = 0;
    for(int i=1;i<=n;++i) {
        if(a[i] < 0)
            last = i;
        else {
            if(a[i+1] < 0 || i == n) {
                ans.push_back(i);
                if(last)
                    ans.push_back(last);
            }
        }
    }
}

void solve() {
    int n;readInt(n);
    veci64 a(n+2);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    i64 ans = 0, ansi = 0;
    for(int i=1;i<=n;++i)
        ans += a[i];
    veci64 sa(n+2);
    for(int i=1;i<=n;++i)
        sa[i] = sa[i-1] + std::abs(a[i]);
    veci64 s(n+2);
    for(int i=1;i<=n;++i)
        s[i] = s[i-1] + a[i];
    // printf("ans %lld\n", ans);
    // for(int i=1;i<=n;++i)
    //     printf("%lld ",s[i]);
    // printf("\n");
    // for(int i=1;i<=n;++i)
    //     printf("%lld ",sa[i]);
    // printf("\n");
    for(int i=1;i<=n;++i) {
        if(a[i] > 0) {
            i64 tmp = sa[i-1] + s[n] - s[i] - a[i];
            // printf("[%d]%lld\n", i, tmp);
            if(tmp > ans) {
                ans = tmp;
                ansi = i;
            }
        } else {

        }
    }
    if(ansi == 0) {
        printf("0\n\n");
    } else {
        veci ansv;
        flip(ansi-1, ansv, a);
        ansv.push_back(ansi);
        printf("%d\n", (int)ansv.size());
        for(auto x:ansv) 
            printf("%d ", x);
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