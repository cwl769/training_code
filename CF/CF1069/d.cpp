#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>

typedef long long int64;

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

int64 f[400][400];

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n, k;readInt(n, k);
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        int mx = 0;
        memset(f, 0x80, sizeof(f));
        f[0][0] = 0;
        for(int i=1;i<=n;++i) {
            for(int m=a[i];m>mx;--m) {
                for(int s=m;s<=k;++s) {
                    for(int j=0;j<m;++j) {
                        f[m][s] = std::max(f[m][s], f[j][s-m]+1ll*(m-j)*(n-i+1));
                    }
                }
            }
            mx = std::max(mx, a[i]);

            // for(int m=0;m<=k;++m) {
            //     for(int s=0;s<=k;++s)
            //         printf("%20lld ", f[m][s]);
            //     printf("\n");
            // }
            // printf("---------------\n");
        }
        int64 ans = 0;
        for(int m=0;m<=k;++m)
        for(int s=0;s<=k;++s)
            ans = std::max(ans, f[m][s]);
        printf("%ld\n", ans);
    }

    return 0;
}