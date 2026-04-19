#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

typedef long long int64;
typedef std::vector<int> vector;

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

int main() {
    int T;readInt(T);
    while(T--) {
        int64 n, m, a, b;readInt(n, m, a, b);
        if(gcd(a, n) != 1) {
            printf("NO\n");
            continue;
        }
        if(gcd(b, m) != 1) {
            printf("NO\n");
            continue;
        }

        if(gcd(n, m) == 1) {
            printf("YES\n");
            continue;
        }

        if(gcd(n, m) > 2) {
            printf("NO\n");
            continue;
        }

        printf("YES\n");
    }

    return 0;
}