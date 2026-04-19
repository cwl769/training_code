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
        int n;readInt(n);
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        int x;readInt(x);
        bool yes = false;
        if(x==a[1])
            yes = true;
        for(int i=1;i<n;++i) {
            int p = std::min(a[i], a[i+1]);
            int q = std::max(a[i], a[i+1]);
            if(p<=x && x<=q)
                yes = true;
        }
        if(yes)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}