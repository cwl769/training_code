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
typedef std::vector<int> vector;

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
    while(T--) {
        int n, k;readInt(n, k);
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        std::vector<int> p(k);
        for(int i=0;i<k;++i)
            readInt(p[i]);
        
        int cntl = 0, cntr = 0;
        for(int i=p[0]-1;i>=1;--i) {
            if(a[i] != a[i+1])
                ++cntl;
        }
        for(int i=p[0]+1;i<=n;++i) {
            if(a[i] != a[i-1])
                ++cntr;
        }
        int ans = std::max(cntl, cntr);
        if(ans & 1) ++ans;
        printf("%d\n", ans);
    }

    return 0;
}