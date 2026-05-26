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

bool check(int x, const int n, veci& a, veci& b) {
    int cnt0 = 0, cnt1 = 0;
    int last = 0, has2 = 0;
    for(int i=1;i<=n;++i) {
        int tmp = 0;
        if(a[i] < x)
            ++tmp;
        if(b[i] < x)
            ++tmp;
        if(tmp == 0) {
            ++cnt0;
            last = i, has2 = 0;
        } else {
            if(tmp == 2)
                has2 = 1;
            int nxttmp = 0;
            if(i<n && a[i+1] < x)
                ++nxttmp;
            if(i<n && b[i+1] < x)
                ++nxttmp;
            if(nxttmp == 0) {
                if(has2)
                    ++cnt1;
            }
        }
    }
    return cnt0 > cnt1;
}

void solve() {
    int n;readInt(n);
    veci a(n+2), b(n+2);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    for(int i=1;i<=n;++i)
        readInt(b[i]);
    int al = 1, ar = n * 2;
    while(al < ar) {
        int mid = ((al+ar+1)>>1);
        if(check(mid, n, a, b))
            al = mid;
        else
            ar = mid - 1;
    }
    printf("%d\n", al);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}