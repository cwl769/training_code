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

int log2(int x) {
    int ans = 0;
    for(;x;x>>=1)++ans;
    return ans-1;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int a, b;readInt(a, b);
        if(a==b) {
            printf("0\n");
            continue;
        }
        if(log2(b) > log2(a)) {
            printf("-1\n");
            continue;
        }
        int t = (a^b);
        if(t&(1<<log2(a))) {
            printf("2\n");
            printf("%d %d\n", t^(1<<log2(a)), 1<<log2(a));
        } else {
            printf("1\n");
            printf("%d\n", t);
        }
    }

    return 0;
}