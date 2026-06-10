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

char sa[100010], sb[100010];

i64 pow2[40];

void solve() {
    i64 cx[3] = {0, 0, 0};
    i64 cy[3] = {0, 0, 0};
    int n, k;readInt(n, k);
    scanf("%s%s", sa, sb);
    for(int i=0;i<n;++i) {
        if(sa[i] == '0' && sb[i] == '0') {
            ++cx[0];
            ++cx[1];
            ++cx[2];
        }
        if(sa[i] == '0' && sb[i] == '1') {
            ++cy[0];
            ++cx[1];
            ++cy[2];
        }
        if(sa[i] == '1' && sb[i] == '0') {
            if(k&1) {
                ++cx[0];
                ++cy[1];
                ++cy[2];
            } else {
                ++cy[0];
                ++cy[1];
                ++cx[2];
            }
        }
        if(sa[i] == '1' && sb[i] == '1') {
            if(k&1) {
                ++cy[0];
                ++cy[1];
                ++cx[2];
            } else {
                ++cx[0];
                ++cy[1];
                ++cy[2];
            }
        }
    }
    i64 ans = 0;
    // printf("[%d]%d %d\n", cx[0] * cy[0], cx[0], cy[0]);
    // printf("[%d]%d %d\n", cx[1] * cy[1], cx[1], cy[1]);
    // printf("[%d]%d %d\n", cx[2] * cy[2], cx[2], cy[2]);
    ans += cx[0] * cy[0] * ((k&1)?(pow2[k]/3ll+1):(pow2[k]/3ll));
    ans += cx[1] * cy[1] * (pow2[k]/3ll+1ll);
    ans += cx[2] * cy[2] * (pow2[k]/3ll+1ll);
    printf("%lld\n", ans);
}

int main() {
    pow2[0] = 1;
    for(int i=1;i<40;++i)
        pow2[i] = (pow2[i-1]<<1);
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}