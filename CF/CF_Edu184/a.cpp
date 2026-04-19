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
        int n, a;
        readInt(n, a);
        std::vector<int> v(n+1);
        for(int i=1;i<=n;++i)
            readInt(v[i]);
        int sm=0, bg=0;
        for(int i=1;i<=n;++i) {
            if(v[i]<a)++sm;
            if(v[i]>a)++bg;
        }
        if(sm>=bg) printf("%d\n", a-1);
        else printf("%d\n", a+1);
    }

    return 0;
}