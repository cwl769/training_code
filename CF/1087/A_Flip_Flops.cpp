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
    for(;T;--T) {
        int64 n, c, k;readInt(n, c, k);
        std::vector<int64> a(n);
        for(int i=0;i<n;++i)
            readInt(a[i]);
        std::sort(a.begin(), a.end());
        for(int i=0;i<n;++i) {
            if(a[i] > c)break;
            int64 delta = std::min(k, c - a[i]);
            k -= delta;
            c += a[i] + delta;
        }
        printf("%lld\n", c);
    }

    return 0;
}