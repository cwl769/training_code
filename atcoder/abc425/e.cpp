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

int64 M;

int64 C[5010][5010];

int main() {
    int T;readInt(T, M);
    for(int i=0;i<=5000;++i)
        C[i][0] = 1;
    for(int i=1;i<=5000;++i)
    for(int j=1;j<=i;++j)
        C[i][j] = (C[i-1][j] + C[i-1][j-1]) % M;
    for(;T;--T) {
        int n;readInt(n);
        int sum = 0;
        std::vector<int> cnt(n+1);
        for(int i=1;i<=n;++i) {
            readInt(cnt[i]);
            sum += cnt[i];
        }
        int64 ans = 1;
        for(int i=1;i<=n;++i) {
            ans = (ans * C[sum][cnt[i]]) % M;
            sum -= cnt[i];
        }
        printf("%lld\n", ans);
    }

    return 0;
}