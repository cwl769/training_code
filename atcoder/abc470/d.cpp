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
    int n, q;
    readInt(n, q);
    veci p(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(p[i]);

    veci pos(n + 2);
    for (int i = 1; i <= n; ++i)
        pos[p[i]] = i;

    bool revf = false;
    while (q--) {
        int tp;
        readInt(tp);
        if (tp == 1) {
            int x, y;
            readInt(x, y);
            if (revf) {
                int px = pos[x];
                int py = pos[y];
                std::swap(pos[x], pos[y]);
                std::swap(p[px], p[py]);
            } else {
                int vx = p[x];
                int vy = p[y];
                std::swap(p[x], p[y]);
                std::swap(pos[vx], pos[vy]);
            }
        } else {
            revf = !revf;
        }
    }
    if (revf) {
        for (int i = 1; i <= n; ++i)
            printf("%d ", pos[i]);
    } else {
        for (int i = 1; i <= n; ++i)
            printf("%d ", p[i]);
    }
    printf("\n");
}

int main() {
    //int T;readInt(T);
    //while(T--) {
        solve();
        //}

    return 0;
}
