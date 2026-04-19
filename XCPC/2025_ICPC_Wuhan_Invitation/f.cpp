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
typedef __int128 int128;
typedef std::vector<int> vector;

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

constexpr int64 MOD = 998244353;

int64 pow(int64 a, int64 b) {
    int64 ans = 1;
    for(;b;b>>=1) {
        if(b&1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
    }
    return ans;
}

void solve() {
    int n;int64 m;readInt(n, m);
    std::map<int64, int64, std::greater<int64> > map;
    for(int i=1;i<=n;++i) {
        int64 a, b;readInt(a, b);
        map[b] += a;
    }
    int64 ans = 0;
    int64 nd_a = 0, nd_b = 0;
    //we need nd_a * (2 ^ nd_b)
    int64 lst_b = map.begin()->first;
    for(auto pr:map) {
        int64 b = pr.first;
        int64 a = pr.second;
        // printf("a,b: %d %d\n", a, b);
        nd_b += lst_b - b;
        if(nd_a) {
            // printf("11111\n");
            if(nd_b >= 49 || (((int128)nd_a) << nd_b) >= (((int128)1)<<49) ) {
                printf("%lld\n", ans);
                return;
            } else {
                nd_a = (nd_a << nd_b);
                nd_b = 0;
                if(a <= nd_a) {
                    nd_a -= a;
                    a = 0;
                } else {
                    a -= nd_a;
                    nd_a = 0;
                }
            }
        }
        if(nd_a == 0 && a){
            // printf("22222\n");
            if(a%m) {
                ans = (ans + (int128)pow(2, b) * ((a / m + 1) % MOD)) % MOD;
                nd_a = m - a % m;
                nd_b = 0;
            } else {
                ans = (ans + (int128)pow(2, b) * ((a / m) % MOD)) % MOD;
                nd_a = 0, nd_b = 0;
            }
        }
        lst_b = b;
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