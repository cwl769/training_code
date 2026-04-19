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

int64 gcd(int64 a, int64 b) {
    if(b == 0)return a;
    return gcd(b, a%b);
}

int64 lcm(int64 a, int64 b) {
    return a * b / gcd(a, b);
}

int main() {
    int T;readInt(T);
    while(T--) {
        int64 a, b, c, m;readInt(a, b, c, m);
        int64 aa = 0, bb = 0, cc = 0;
        aa += m / a * 6;
        bb += m / b * 6;
        cc += m / c * 6;

        int64 ab = lcm(a, b);
        int64 ac = lcm(a, c);
        int64 bc = lcm(b, c);

        aa -= m / ab * 3;
        bb -= m / ab * 3;
        aa -= m / ac * 3;
        cc -= m / ac * 3;
        bb -= m / bc * 3;
        cc -= m / bc * 3;

        int64 abc = lcm(ab, c);

        aa += m / abc * 2;
        bb += m / abc * 2;
        cc += m / abc * 2;

        printf("%lld %lld %lld\n", aa, bb, cc);
    }

    return 0;
}