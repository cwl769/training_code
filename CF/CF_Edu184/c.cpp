#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>

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
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        std::vector<int64> s(n+1);
        s[0] = 0;
        for(int i=1;i<=n;++i)
            s[i] = s[i-1] + a[i];
        std::priority_queue<int64> heap;
        int64 ans = 0;
        for(int i=1;i<=n;++i) {
            ans = std::max(ans, 2ll*i - (int64)a[i]);
            if(!heap.empty())
                ans = std::max(ans, 1ll*i*i + 1ll*i - s[i] + heap.top());
            heap.push(1ll*i-1ll*i*i+s[i-1]);
        }
        printf("%lld\n", ans+s[n]);
    }

    return 0;
}