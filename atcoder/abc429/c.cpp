#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <stdint.h>
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

int main() {
    int n;readInt(n);
    std::vector<int> a(n+1);
    std::vector<std::vector<int> > cnt(n+1);
    for(int i=1;i<=n;++i) {
        readInt(a[i]);
        cnt[a[i]].push_back(i);
    }
    int64 ans = 0;
    for(int x=1;x<=n;++x) {
        if(cnt[x].size() < 2)
            continue;
        for(uint32_t i=1;i<cnt[x].size();++i) {
            ans += 1ll * i * (n - cnt[x].size());
        }
    }
    printf("%lld\n", ans);

    return 0;
}