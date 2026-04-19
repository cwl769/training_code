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
    int n, k;int64 x;readInt(n, k, x);
    std::vector<int64> a(n);
    for(int i=0;i<n;++i)
        readInt(a[i]);
    std::sort(a.begin(), a.end(), std::greater<int64>());
    int ans = n-k;
    int64 tmp = 0;
    for(int i=n-k;i<n;++i) {
        tmp += a[i];
        ++ans;
        if(tmp >= x)
            break;
    }
    if(tmp < x)
        printf("-1\n");
    else
        printf("%d\n", ans);

    return 0;
}