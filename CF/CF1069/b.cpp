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
        int n, l, r;readInt(n, l, r);
        std::vector<int> s(n+1);
        for(int i=0;i<=n;++i)
            s[i] = i+1;
        s[r] = s[l-1];
        for(int i=1;i<=n;++i) {
            printf("%d ", s[i]^s[i-1]);
        }
        printf("\n");
    }

    return 0;
}