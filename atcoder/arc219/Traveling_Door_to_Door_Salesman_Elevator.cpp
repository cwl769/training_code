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

struct Range {
    int l, r;
    int ml, mr;
    Range():l(INT_MAX), r(INT_MIN), ml(INT_MAX), mr(INT_MIN){}
};

void solve() {
    int h, w;readInt(h, w);
    int mid = (w + 1) / 2;
    std::map<int, Range> map;
    int n;readInt(n);
    for(int i=1;i<=n;++i) {
        int x, y;readInt(x, y);
        Range &rg = map[x];
        rg.l = std::min(rg.l, y);
        rg.r = std::max(rg.r, y);
        if(y <= mid)
            rg.mr = std::max(rg.mr, y);
        else
            rg.ml = std::min(rg.ml, y);
    }
    bool all_left = true;
    for(auto line:map) {
        Range rg = line.second;
        if(rg.r + rg.r - 2 > w - 1) {
            all_left = false;
        }
    }
    i64 ans_all_left = 0;
    if(all_left) {
        for(auto line:map) {
            ans_all_left += 2ll * line.second.r - 2ll;
        }
        printf("%lld\n", ans_all_left);
        return;
    }
    i64 sum = 0;
    i64 mn = LLONG_MAX, mn2 = LLONG_MAX;
    for(auto line:map) {
        Range rg = line.second;
        i64 cur = LLONG_MAX;
        cur = std::min(cur, 2ll*(rg.r - 1));
        cur = std::min(cur, 2ll*(w - rg.l));
        if(rg.l <= mid && rg.r > mid) {
            cur = std::min(cur, 2ll * (rg.mr - 1) + 2ll * (w - rg.ml));
        }
        if(w-1 < cur) {
            sum += cur;
        } else {
            
        }
    }
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}