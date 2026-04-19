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

int64 lowbit(int64 x) {
    return x&(-x);
}

void solve(int64 k, int64 x, bool flag) {
    if(lowbit(x) == x) {
        for(int64 t=(1ll<<k);t!=x;t>>=1ll) {
            if(flag)printf("2 ");
            else printf("1 ");
        }
        return;
    }
    for(int64 t=lowbit(x-lowbit(x));(t>>1ll)!=lowbit(x);t>>=1ll) {
        if(flag)printf("2 ");
        else printf("1 ");
    }
    if(flag)printf("1 ");
    else printf("2 ");
    solve(k, x - lowbit(x), flag);
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int64 k;int64 x;
        readInt(k, x);
        bool flag = false;
        if(x > 1ll<<k) {
            x = (1ll<<(k+1ll)) - x;
            flag = true;
        }
        int ansN = k;
        for(int64 t=lowbit(x);t>1ll;t>>=1ll) {
            --ansN;
        }
        printf("%d\n", ansN);
        solve(k, x, flag);
        printf("\n");
    }

    return 0;
}