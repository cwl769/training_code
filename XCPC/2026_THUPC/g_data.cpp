#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <random>

typedef long long int64;
std::random_device random_device;
std::mt19937 Rand(random_device());

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
    int T = 1;
    printf("%d\n", T);
    for(;T;--T) {
        int n = 7;
        printf("%d\n", n);
        for(int i=1;i<=n;++i)
            printf("%d", Rand()&1);
        printf("\n");
    }

    return 0;
}