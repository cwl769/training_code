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
    int n, m;readInt(n, m);
    int k;readInt(k);
    std::vector< std::vector<int> > map;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            int x;readInt(x);
            map[x].push_back(i);
        }
    }
    std::vector<int> ans(n+1);
    for(int t=1;t<=k;++t) {
        int b;readInt(b);
        for(auto x:map[b])
            ++ans[x];
    }
    int tms = 0;
    for(int i=1;i<=n;++i)
        tms = std::max(tms, ans[i]);
    printf("%d\n", tms);

    return 0;
}