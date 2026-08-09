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
    int n, m, x, y;
    readInt(n, m, x, y);
    veci a(x + 2);
    veci b(y + 2);
    for (int i = 1; i <= x; ++i)
        readInt(a[i]);
    for (int i = 1; i <= y; ++i)
        readInt(b[i]);
    std::vector<bool> av(n + m + 2), bv(n + m + 2);
    for (int i = 1; i <= x; ++i)
        av[a[i]] = 1;
    for (int i = 1; i <= y; ++i)
        bv[b[i]] = 1;
    std::set<int, std::greater<int> > set;
    for (int i = 1; i <= x; ++i)
        set.emplace(a[i]);
    for (int i = 1; i <= y; ++i)
        set.emplace(b[i]);
    int tot = n + m - 1;
    int avi = n - 1;
    int bvi = m - 1;
    int pub = 1;
    i64 ans = 0;
    for (auto val : set) {
        if (av[val] && bv[val]) {
            ans += val;
            --tot;
        } else if (av[val]) {
            if (avi) {
                ans += val;
                --tot;
                --avi;
            } else {
                if (pub) {
                    ans += val;
                    --pub;
                    --tot;
                }
            }
        } else if (bv[val]) {
            if (bvi) {
                ans += val;
                --tot;
                --bvi;
            } else {
                if (pub) {
                    ans += val;
                    --pub;
                    --tot;
                }
            }
        } else {
        }
        if (tot == 0)
            break;
    }
    printf("%lld\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
