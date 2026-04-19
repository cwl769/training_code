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

int cal(int n, std::vector<int>& a, std::vector<int>& b) {
    int ans = 0;
    for(int i=0;i<n;++i) {
        bool legal = true;
        for(int d=0;d<n;++d) {
            if(a[d] >= b[(i + d) % n]) {
                legal = false;
                break;
            }
        }
        if(legal) ++ ans;
    }
    return ans;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<int> a(n), b(n), c(n);
        for(int i=0;i<n;++i)
            readInt(a[i]);
        for(int i=0;i<n;++i)
            readInt(b[i]);
        for(int i=0;i<n;++i)
            readInt(c[i]);
        printf("%lld\n", 1ll * n * cal(n, a, b) * cal(n, b, c));
    }

    return 0;
}