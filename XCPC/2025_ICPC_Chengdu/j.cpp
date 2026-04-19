#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

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
        int n, m, k, b;readInt(n, m, k, b);
        int ans = 0, can = 0;
        for(int i=1;i<=n;++i) {
            int sum = 0;
            int delta = 0;
            for(int j=1;j<=m;++j) {
                int x;readInt(x);
                sum += x;
                if(x>=1)
                    delta += -1;
                else 
                    delta += 1;
            }
            if(sum >= k)++ans;
            else if(sum + delta >= k)++can;
        }
        printf("%d\n", ans + std::min(b, can));
    }

    return 0;
}