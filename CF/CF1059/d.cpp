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

int diff(int l, int r) {
    int a, b;
    printf("1 %d %d\n", l, r);
    fflush(stdout);
    scanf("%d", &a);
    printf("2 %d %d\n", l, r);
    fflush(stdout);
    scanf("%d", &b);
    return b - a;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        int len = diff(1, n);
        int l = 1, r = n;
        bool flag = false;
        for(;l<r;) {
            int mid = ((l+r)>>1);
            int t = diff(l, mid);
            if(t==0) {
                l = mid + 1;
            } else if(t == len) {
                r = mid;
            } else {
                printf("! %d %d\n", mid - t + 1, mid + len - t);
                fflush(stdout);
                flag = true;
                break;
            }
        }
        if(!flag) {
            printf("! %d %d\n", l, r);
            fflush(stdout);
        }
    }

    return 0;
}