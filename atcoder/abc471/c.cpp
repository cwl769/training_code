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
    int n;readInt(n);
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i) {
        readInt(a[i]);
    }
    std::set<i64> set;
    for (int i = 1; i <= n; ++i) {
        set.emplace(a[i]);
    }
    i64 ans = 0;
    i64 pos = 0;
    while(set.size()) {
        auto it = set.lower_bound(pos);
        if(it == set.begin()) {
            ans += *it - pos;
            pos = *it;
        } else if(it == set.end()) {
            i64 cur = *set.rbegin();
            ans += pos - cur;
            pos = cur;
        } else {
            auto itb = it;
            --it;
            i64 pl = *it;
            i64 pr = *itb;
            if(pos - pl <= pr - pos) {
                ans += pos - pl;
                pos = pl;
            } else {
                ans += pr - pos;
                pos = pr;
            }
        }
        set.erase(pos);
    }
    printf("%lld\n", ans);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}