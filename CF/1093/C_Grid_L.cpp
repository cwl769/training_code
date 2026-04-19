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

typedef long long int64;
typedef long long i64;
typedef unsigned long long ui64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;


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
    i64 p, q;readInt(p, q);
    i64 len = p + q + q;
    for(i64 n=1;n<=20000 && n<len;++n) {
        if((len-n) % (n*2ll+1ll) == 0) {
            i64 m = (len - n) / (n*2+1);
            if(m < n)continue;
            i64 need = m - n;
            if(need <= p) {
                printf("%d %d\n", n, m);
                return;
            }
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