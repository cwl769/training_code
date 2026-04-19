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
        std::sort(a.begin()+1, a.end());
        bool win = true;
        for(int i=2;i<n;i+=2) {
            if(a[i]!=a[i+1]) {
                win = false;
                break;
            }
        }
        if(win)printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}