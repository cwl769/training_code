#include <cstdio>
#include <cstdlib>
#include <cstring>
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

int cnt[110];

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        memset(cnt, 0x00, sizeof(cnt));
        for(int i=1;i<=n;++i) {
            int x;readInt(x);
            ++cnt[x];
        }
        bool f = true;
        for(int i=2;i<=100;++i) {
            if(cnt[i] > 1) {
                printf("YES\n");
                f = false;
                break;
            }
        }
        if(f)
            printf("NO\n");
    }

    return 0;
}