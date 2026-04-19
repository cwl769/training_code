#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>

template<typename T> 
void readInt(T& x) {
    x = 0;
    char c = getchar();
    while(c<'0'||c>'9')c=getchar();
    for(;'0'<=c&&c<='9';c=getchar()) {
        x = x * (T)10 + (c - '0');
    }
}
template<typename T, typename ...ARGS>
void readInt(T& x, ARGS&... args) {
    readInt(x);
    readInt(args...);
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<int> fa(n+1);
        for(int i=2;i<=n;++i)
            readInt(fa[i]);
        std::vector<std::vector<int> > son(n+1);
        for(int i=2;i<=n;++i)
            son[fa[i]].push_back(i);
        std::vector<int> rest(n+1);
        int ans = 0;
        for(int x=n;x>=1;--x) {
            int sum = 0, mx = 0;
            for(auto s:son[x]) {
                sum += rest[s];
                mx = std::max(mx, rest[s]);
            }
            if(mx <= sum - mx) {
                ans += sum / 2;
                rest[x] = 1 + (sum / 2) * 2;
                // printf("[%d]%d %d\n", x, sum / 2, 1 + (sum / 2) * 2);
            }
            else {
                ans += sum - mx;
                rest[x] = 1 + mx - (sum - mx) * 2;
            }
        }
        printf("%d\n", ans);
    }


    return 0;
}