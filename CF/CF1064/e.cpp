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

int solve(int n, std::vector<int>& a, int c) {
    if(n==1) {
        return (c<=a[0])? 0 : (c-a[0]) ;
    }
    if(c==0)return 0;
    int i = 29;
    for(;i>=0;--i) {
        if(c>=(1<<i))
            break;
    }
    int j = 29;
    for(;j>=0;--j) {
        if(a[n-1]>=(1<<j))
            break;
    }
    for(;;)
    if(j<i) {
        int t = ((~((1<<j<<1) - 1)) & c);
    } else if(j==i) {
        if(c<=a[n-1])return 0;

    } else {
        return 0;
    }
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n, q;readInt(n, q);
        std::vector<int> a(n);
        for(int i=0;i<n;++i)
            readInt(a[i]);
        std::sort(a.begin(), a.end());
        for(;q;--q) {
            int c;readInt(c);
            int ans = solve(n, a, c);
            printf("%d\n", ans);
        }
    }

    return 0;
}