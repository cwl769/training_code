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

struct Pool {
    i64 prog, pity, need, luck;
    Pool() : prog(), pity(), need(), luck() {
        
    }
};

Pool p[400010];

int fa[200010];
int el[200010];

void solve() {
    int n, A, B, m, q;
    readInt(n, A, B, m, q);
    for (int i = 1; i <= n; ++i) {
        readInt(fa[i], el[i]);
    }
    for (int i = 1; i <= A; ++i) {
        readInt(p[i].need);
    }
    for (int i = 1; i <= B; ++i) {
        readInt(p[A+i].need);
    }
    for (int i = 1; i <= A; ++i) {
        readInt(p[i].luck);
    }
    for (int i = 1; i <= B; ++i) {
        readInt(p[A+i].luck);
    }
    
}

int main() {
    //int T;readInt(T);
    //while(T--) {
        solve();
    //}

    return 0;
}
