#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>

typedef long long int64;
typedef unsigned long long uint64;

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

int64 floor(int64 a, int64 b) {//[a/b]
    if(a%b==0)return a/b;
    if((a>0&&b>0)||(a<0&&b<0)) {
        return a/b;
    }
    return a/b - 1;
}

typedef int64 Int0;

Int0 Euclid(int64 a, int64 b, int64 c, int64 n) { //sigma(i=0->n) floor((ai+b)/c)
    int64 a_c = floor(a, c);
    int64 b_c = floor(b, c);
    if(n==0) {
        return b_c;
    }
    Int0 ans = 0;
    ans = a_c;
    ans *= n * (n+1ll) / 2ll;
    ans += b_c * (n+1ll);
    a = (a%c+c)%c;
    b = (b%c+c)%c;
    a_c = floor(a, c);
    b_c = floor(b, c);
    if(a==0) {
        return ans + b_c * (n+1ll);
    }
    ans += n * floor((a*n+b), c);
    ans -= Euclid(c, c-b-1ll, a, floor((a*n+b), c)-1ll);
    return ans;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
       int64 f, x, g, y, n, m;readInt(f, x, g, y, n, m);
       int64 ans = 0;
       ans += n; 
       ans += Euclid(f, x, m, n-1);
       ans -= Euclid(g, y, m, n-1);
       ans += Euclid(g-f, y-x-1, m, n-1);
       printf("%lld\n", ans);
    //    printf("%lld\n", Euclid(g-f, y-x-1, m, n-1));
    }

    return 0;
}