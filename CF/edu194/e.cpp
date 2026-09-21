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

char str[300010];

void solve() {
    int n, Q;
    readInt(n, Q);
    scanf("%s", str + 1);
    veci s0(n + 2), s1(n + 2), sd(n + 2), d(n + 2);
    for (int i = 2; i <= n; ++i)
        if(str[i] != str[i - 1])
            d[i] = 1;
    for (int i = 1; i <= n; ++i) {
        s0[i] = s0[i - 1];
        if(str[i] == '0')
            ++s0[i];
    }
    for (int i = 1; i <= n; ++i) {
        s1[i] = s1[i - 1];
        if(str[i] == '1')
            ++s1[i];
    }
    for (int i = 1; i <= n; ++i) {
        sd[i] = sd[i - 1] + d[i];
    }
    while(Q--) {
        int l, r;
        readInt(l, r);
        int c0 = 0, c1 = 0, cd = 0;
        c0 = s0[r] - s0[l - 1];
        c1 = s1[r] - s1[l - 1];
        cd = sd[r] - sd[l];
        if(str[l] != str[r])
            ++cd;
        cd >>= 1;
        c0 -= cd;
        c1 -= cd;
        // printf("%d %d %d\n", c0, c1, cd);

        int ans = 0;
        // if(cd >= c0 && cd >= c1) {
        //     ans = (cd - c0) + (cd - c1);
        // } else if(c0 >= cd && c0 >= c1) {
            
        // } else if(c1 >= cd && c1 >= c0) {
            
        // }
        if(cd >= c0 && cd >= c1) {
            ans = (cd - c0) + (cd - c1);
        } else {
            l = cd; r = std::max(c0, c1);
            while(l < r) {
                int mid = ((l + r + 1) >> 1);
                int tmp = std::max(0, c0 - mid) + std::max(0, c1 - mid);
                if(tmp >= mid - cd)
                    l = mid;
                else
                    r = mid - 1;
            }
            int tar = l;
            int dd = tar - cd;
            int ee = std::max(0, c0 - tar) + std::max(0, c1 - tar);

            int fin;
            if(ee == dd)
                fin = tar;
            else
                fin = tar + 1;
            // printf("%d %d\n", tar, fin);
            dd = fin - cd;
            ee = std::max(0, c0 - fin) + std::max(0, c1 - fin);
            
            if(c0 < fin)
                ans += fin - c0;
            if(c1 < fin)
                ans += fin - c1;
            if(cd < fin)
                ans += (fin - cd) + (fin - cd);
            ans -= std::min(ee, dd);
        }
        printf("%d\n", ans);
    }
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}