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
        int64 n;readInt(n);
        std::vector<int64> cnt(n+1);
        std::vector<int64> a(n+1);
        int64 sum = 0;
        for(int i=1;i<=n;++i) {
            readInt(a[i]);
            ++cnt[a[i]];
            sum += a[i];
        }
        printf("%lld\n", std::min(n-cnt[0], sum-n+1));
    }

    return 0;
}