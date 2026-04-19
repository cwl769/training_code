#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>

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
        int n, q;readInt(n, q);
        std::vector<int> a(n+1);
        std::vector<int> sum(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        for(int i=1;i<=n-2;++i) {
            if(a[i]>a[i+1] && a[i+1]>a[i+2])
                sum[i] = 1;
        }
        for(int i=1;i<=n;++i)
            sum[i] += sum[i-1];
        for(;q;--q) {
            int l, r;readInt(l, r);
            if(r - l < 2)
                printf("YES\n");
            else if(sum[l-1] != sum[r-2])
                printf("NO\n");
            else
                printf("YES\n");
        }
    }

    return 0;
}