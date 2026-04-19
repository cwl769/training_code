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

int gcd(int a, int b) {
    if(b == 0)return a;
    return gcd(b, a%b);
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int a, b;readInt(a, b);
        if(a > b)std::swap(a, b);
        int g = gcd(a, b);
        int lcm = a * b / g;
        if(a == b)
            printf("0\n");
        else if(b == lcm)
            printf("1\n");
        else 
            printf("2\n");
    }

    return 0;
}