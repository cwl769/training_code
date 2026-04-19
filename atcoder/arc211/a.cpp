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
    int T;readInt(T);
    for(;T;--T) {
        std::vector<int64> a(10);
        for(int i=1;i<=9;++i)readInt(a[i]);
        int64 ps = 0, psum = 0;
        for(int i=1;i<=4;++i) {
            if(a[i] && a[10 - i]){
                ++ps;
                psum += a[i] + a[10 - i];
            }
        }
        int64 sum = 0;
        for(int i=1;i<=9;++i)
            sum += a[i];
        if(ps == 1) {
            if(psum == sum) {
                printf("1\n");
                continue;
            }
        }
        if(a[5] <= 1 + sum - a[5]) {
            printf("0\n");
            continue;
        } else {
            printf("%lld\n", a[5] - (1 + sum - a[5]));
        }
    }

    return 0;
}