#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
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
    int n;readInt(n);
    std::vector<int64> a(n+1), b(n+1), c(n+1);
    std::vector<int64> sa(n+1), sb(n+1), sc(n+1);
    for(int i=1;i<=n;++i) {
        readInt(a[i]);
        sa[i] = sa[i-1] + a[i];
    }
    for(int i=1;i<=n;++i) {
        readInt(b[i]);
        sb[i] = sb[i-1] + b[i];
    }
    for(int i=1;i<=n;++i) {
        readInt(c[i]);
        sc[i] = sc[i-1] + c[i];
    }
    std::priority_queue<int64> heap;
    heap.push(sa[1] - sb[1]);
    int64 ans = 0;
    for(int y=2;y<n;++y) {
        ans = std::max(ans, heap.top() + sb[y] - sc[y] + sc[n]);
        heap.push(sa[y] - sb[y]);
    }
    printf("%lld\n", ans);

    return 0;
}