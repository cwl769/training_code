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
#include <queue>
#include <stack>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

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

i64 lowbit(i64 x) {return x & (-x);}

void solve() {
    i64 x, y;
    readInt(x, y);
    i64 sum = x + y;
    i64 tmp = 0;
    for (int i = 32; i >= 0; --i) {
        if((x >> i) & 1) {
            if((sum >> i) & 1) {
                tmp |= (1ll << i);
            } else {
                tmp |= (sum & ((1ll << i) - 1));
                break;
            }
        }/* else {
            if((sum >> i) & 1) {
                
            } else {
                
            }
        }*/
    }
    printf("%lld %lld\n", sum, x - tmp);
}

int main() {
    // for(int s = 0; s < 10000; ++s) {
    //     int ans = 0;
    //     for(int x = 0; x <= s - x; ++x) {
    //         ans = std::max(ans, x ^ (s - x));
    //     }
    //     if(s != ans)
    //         printf("%d %d\n", s, ans);
    // } 
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}