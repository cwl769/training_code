#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

#define debug(...) fprintf(stderr, __VA_ARGS__)

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

void solve() {
    int n, q;readInt(n, q);
    veci64 a(n+1);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    int cnt[2] = {0, 0};
    for(int i=1;i<=q;++i) {
        int x;readInt(x);
        ++cnt[x&1];
    }
    veci64 vec[2];
    for(int i=1;i<=n;++i)
        vec[i&1].push_back(a[i]);
    std::sort(vec[0].begin(), vec[0].end());
    std::sort(vec[1].begin(), vec[1].end());
    i64 ans = 0;
    bool pop[2] = {false, false};
    while(cnt[0] && vec[0].size() && vec[0].back()>=0) {
        pop[0] = true;
        --cnt[0];
        vec[0].pop_back();
    }
    while(cnt[1] && vec[1].size() && vec[1].back()>=0) {
        pop[1] = true;
        --cnt[1];
        vec[1].pop_back();
    }
    if(!pop[0] && cnt[0])
        vec[0].pop_back();
    if(!pop[1] && cnt[1])
        vec[1].pop_back();
    for(auto x:vec[0])
        ans += x;
    for(auto x:vec[1])
        ans += x;
    printf("%lld\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}