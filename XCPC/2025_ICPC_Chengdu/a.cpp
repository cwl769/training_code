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

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<int> a(n+1);
        int sum = 0;
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        for(int i=1;i<=n;++i)
            sum += a[i];
        if(sum==100) {
            printf("Yes\n");
            for(int i=1;i<=n;++i)
                printf("%d ", a[i]);
            printf("\n");
        } else if(sum > 100) {
            int cntno0 = 0;
            for(int i=1;i<=n;++i)
                if(a[i]!=0)
                    ++cntno0;
            if(cntno0<2*(sum-100)) {
                printf("No\n");
            } else {
                printf("Yes\n");
                int need = 2*(sum-100);
                for(int i=1;i<=n;++i) {
                    if(a[i] && need) {
                        printf("%d ", a[i]*10-5);
                        --need;
                    } else {
                        printf("%d ", a[i]*10);
                    }
                }
                printf("\n");
            }
        } else {
            if(n<=2*(100-sum)) {
                printf("No\n");
            } else {
                printf("Yes\n");
                double t = (100.0 - sum) / (double)n;
                for(int i=1;i<=n;++i) {
                    printf("%d ", (int)((a[i]+t)*1e7+0.5));
                }
                printf("\n");
            }
        }
    }

    return 0;
}