#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

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
    int64 n, c;int64 m;readInt(n, m, c);
    std::map<int64, int64> cnt;
    for(int i=1;i<=n;++i) {
        int64 x;readInt(x);
        ++cnt[x];
    }
    if(cnt.find(m)==cnt.end())
        cnt[m] = 0;
    int64 ans = 0;
    auto it = cnt.begin();
    int64 cur = 0;
    int64 last = 0;
    for(auto x:cnt) {
        for(;cur < c;++it) {
            if(it==cnt.end())
                it = cnt.begin();
            cur += it->second;
        }
        // printf("x=%lld add %lld\n", x.first, 1ll * (x.first - last) * cur);
        ans += 1ll * (x.first - last) * cur;
        last = x.first;
        cur -= x.second;
    }
    printf("%lld\n", ans);

    return 0;
}