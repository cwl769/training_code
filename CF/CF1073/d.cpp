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

int f[2][110][110][110];

const int64 M = 998244353;

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<char> str(n+2);
        scanf("%s", str.begin()+1);
        memset(f, 0, sizeof(f));
        int ans = 0;
        for(int i=n;i>=1;--i) {
            int mxl = n-i+1;
            for(int s=0;s<=mxl;++s)
            for(int t=0;t<=mxl;++t)
            for(int k=0;k<=mxl;++k) {
                f[i&1][s][t][k] = f[(i+1)&1][s][t][k];
            }
            if(str[i]=='(') {
                for(int s=0;s<=mxl;++s)
                for(int t=1;t<=mxl;++t)
                for(int k=1;k<=mxl;++k){
                    f[(i)&1][s][t][k] += f[(i+1)&1][s+1][t-1][k-1];
                    if(f[i&1][s][t][k] >= M)
                        f[i&1][s][t][k] -= M;
                }
            } else {
                for(int s=1;s<=mxl;++s)
                for(int t=1;t<=mxl;++t)
                for(int k=0;k<=mxl;++k){
                    f[(i)&1][s][t][0] += f[(i+1)&1][s-1][t-1][k];
                    if(f[i&1][s][t][0] >= M)
                        f[i&1][s][t][0] -= M;
                }
                f[i&1][1][1][0] += 1;
                if(f[i&1][1][1][0]>=M)
                    f[i&1][1][1][0] -= M;
            }
            // for(int s=0;s<=mxl;++s)
            // for(int t=0;t<=mxl;++t)
            // for(int k=0;k<=mxl;++k) {
            //     // printf("%d %d %d %d\n", i, s, t, k);
            //     if(f[i&1][s][t][k])
            //         printf("f[%d][%d][%d][%d] = %d\n", i, s, t, k, f[i&1][s][t][k]);
            // }
            // printf("-------------------------\n");
        }
        for(int t=6;t<=n;++t) {
            for(int k=1;k<=t/2-2;++k) {
                ans = (ans + 1ll*f[1][0][t][k] * (t-2)) % M;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}