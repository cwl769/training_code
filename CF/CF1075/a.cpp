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
        int n, h, l;
        readInt(n, h, l);
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        if(h>l)std::swap(h, l);
        int cnt0 = 0, cnt1 = 0;
        for(int i=1;i<=n;++i) {
            if(a[i] <= h)
                ++cnt0;
            else if(a[i] <= l)
                ++cnt1;
        }
        if(cnt1 > cnt0)
            printf("%d\n", cnt0);
        else {
            printf("%d\n", (cnt0 + cnt1) / 2);
        }
    }

    return 0;
}