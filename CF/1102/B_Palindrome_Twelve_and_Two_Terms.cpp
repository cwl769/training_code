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

bool palin(i64 x) {
    i64 tmp = 0;
    i64 bkp = x;
    for(;x;x/=10) {
        tmp = tmp * 10ll + (x % 10);
    }
    return tmp == bkp;
}

const i64 val[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 22, 11};

void solve() {
    i64 n;readInt(n);
    for(i64 r=0;r<12;++r) {
        i64 x = val[r];
        if(x > n)continue;
        i64 y = n - x;
        if(y%12 == 0) {
            printf("%lld %lld\n", x, y);
            return;
        }
    }
    printf("-1\n");
}

int main() {


    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}