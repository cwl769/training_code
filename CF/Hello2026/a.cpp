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
        int n;readInt(n);
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        int l0 = n + 1, r0 = 0;
        for(int i=1;i<=n;++i) {
            if(a[i] == 0) {
                l0 = std::min(l0, i);
                r0 = std::max(r0, i);
            }
        }
        // printf("%d %d\n", l0, r0);
        if(l0 > r0) {
            printf("Alice\n");
        } else {
            if((l0 == 1) && (r0 == n))
                printf("Bob\n");
            else
                printf("Alice\n");
        }
    }

    return 0;
}