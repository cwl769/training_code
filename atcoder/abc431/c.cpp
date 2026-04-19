#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <functional>

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
    int n, m, k;readInt(n, m, k);
    std::vector<int> a(n), b(m);
    for(int i=0;i<n;++i) {
        readInt(a[i]);
    }
    for(int i=0;i<m;++i) {
        readInt(b[i]);
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    std::sort(b.begin(), b.end(), std::greater<int>());
    // for(auto x:a)
    //     printf("%d ");
    // printf("\n");
    // for(auto x:b)
    //     printf("%d ");
    // printf("\n");
    int ans = 0;
    int p = 0;
    // printf("---------\n");
    for(auto x:b) {
        while(p<n&&a[p]>x)++p;
        if(p<a.size()) {
            // printf("x=%d p=%d a[p]=%d\n", x, p, a[p]);
            ++ans;
            ++p;
        }
    }
    if(ans >= k)printf("Yes\n");
    else printf("No\n");

    return 0;
}