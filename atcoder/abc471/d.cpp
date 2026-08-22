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
    int Q;i64 v;
    readInt(Q, v);
    std::multiset<i64> bat;
    while(Q--) {
        int tp;readInt(tp);
        if(tp == 1) {
            i64 ts, w;
            readInt(ts, w);
            bat.emplace(w - ts);
        } else {
            i64 t;readInt(t);
            if(bat.empty())
                printf("-1\n");
            else {
                i64 ans = *bat.rbegin();
                bat.erase(bat.find(ans));
                printf("%lld\n", std::min(v, ans + t));
            }
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