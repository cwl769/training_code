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

const int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        for(int i=0;i<sizeof(p);++i) {
            if((n-1)%p[i]) {
                printf("%d %d %d\n", p[i], n-1-p[i], 1);
                break;
            }
        }
    } 

    return 0;
}