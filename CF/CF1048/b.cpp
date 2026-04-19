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
        int n, m;readInt(n, m);
        std::vector<int64> a(n);
        for(int i=0;i<n;++i)
            readInt(a[i]);
        std::sort(a.begin(), a.end());
        int64 ans = 0;
        for(int i=n-1,cnt=0;i>=0&&cnt<m;--i,++cnt) {
            ans += a[i] * (m - cnt);
        }
        printf("%lld\n", ans);
    }

    return 0;
}