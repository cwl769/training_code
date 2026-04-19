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

const int64 M = 998244353;
char str[100];

int pos(int x) {
    x = (x&(-x));
    int cnt = 0;
    for(;x;x>>=1)++cnt;
    return cnt - 1;
}

int lowbit(int x){return x&(-x);}

int main() {
    int n;readInt(n);
    scanf("%s", str);
    int lim = (1<<n);
    std::vector<int64> f(lim);
    f[0] = 1;
    for(int s=1;s<lim;++s) {
        char c = '\0';
        for(int tmp=s;tmp;tmp-=lowbit(tmp)) {
            char tc = str[pos(tmp)];
            // putchar(tc);
            if(tc!=c) {
                f[s] = (f[s] + f[s^lowbit(tmp)]) % M;
            }
            c = tc;
        }
        // printf("\n");
    }
    // for(int i=0;i<lim;++i)
    //     printf("f[%d]=%lld\n", i, f[i]);
    printf("%lld\n", f[lim-1]);

    return 0;
}