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

const i64 MOD = 998244353;

void solve() {
    int n;
    readInt(n);
    std::vector<std::pair<int, int> > meet;
    veci cnt(n * 2 + 2);
    for (int i = 1; i <= n; ++i) {
        int s, t;
        readInt(s, t);
        ++cnt[s];
        --cnt[t + 1];
        meet.emplace_back(s, t);
    }
    for (int i = 1; i <= n * 2; ++i) {
        cnt[i] += cnt[i - 1];
        if (cnt[i] > 2) {
            printf("0\n");
            return;
        }
    }
    std::sort(meet.begin(), meet.end());
    int anspow = n;
    int last = 0;
    for (auto [s, t] : meet) {
        if (s <= last) {
            --anspow;
        }
        last = std::max(last, t);
    }
    i64 ans = 1;
    for (int i = 0; i < anspow; ++i) {
        ans = (ans * 2ll) % MOD;
    }
    printf("%lld\n", ans);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
    //     solve();
    // }
    solve();

    return 0;
}
