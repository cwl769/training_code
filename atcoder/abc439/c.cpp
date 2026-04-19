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

const int64 M = 10000010;
int cnt[M];
int ans[M];

int main() {
    for(int i=1;i<=3200;++i) {
        for(int j=i+1;j<=3200;++j) {
            int64 tmp = 1ll * i * i + 1ll * j * j;
            if(tmp < M)
                ++cnt[tmp];
        }
    }
    for(int i=1;i<M;++i)
        ans[i] = ans[i-1] + (int)(cnt[i] == 1);
    int n;readInt(n);
    printf("%d\n", ans[n]);
    for(int i=1;i<=n;++i) {
        if(cnt[i] == 1)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}