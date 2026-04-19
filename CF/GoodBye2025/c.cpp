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
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<int64> a(n+2);
        for(int i=1;i<=n;++i) {
            readInt(a[i]);
        }
        int64 d = 0;
        std::priority_queue<int64> heap, heap2;
        heap.push(0);
        heap2.push(a[1]);
        // int64 tmp = ;
        for(int i=3;i<=n+1;++i) {
            int64 top1 = heap.top();
            int64 top2 = heap2.top();
            heap.push(top2+d-d+a[i-1]);
            heap2.push(top2+d-d+a[i-1]+a[i-1]);
            d += -a[i-1];
        }
        printf("%lld\n", heap.top() + d);
    }

    return 0;
}