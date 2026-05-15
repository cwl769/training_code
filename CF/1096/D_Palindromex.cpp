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

int mex(const veci& a, int l, int r) {
    std::set<int> set;
    for(int i=l;i<=r;++i) {
        set.insert(a[i]);
    }
    for(int ans=0;;++ans) {
        auto it = set.find(ans);
        if(it == set.end())
            return ans;
    }
}

bool check(veci& a, int l, int r) {
    int i = l, j = r;
    for(;i<=r;++i,--j) {
        if(a[i]!=a[j])
            return false;
    }
    return true;
}

void extend(veci& a, int& l, int& r, const int len) {
    while(l-1>0 && r+1<=len && a[l-1] == a[r+1]) {
        --l;++r;
    }
}

void solve() {
    int n;readInt(n);
    int len = n * 2;
    veci a(len+1);
    for(int i=1;i<=len;++i)
        readInt(a[i]);
    int c0 = 0, c1 = 0;
    for(int i=1;i<=len;++i) {
        if(a[i] == 0) {
            if(c0) {
                c1 = i;
            } else {
                c0 = i;
            }
        }
    }
    int ans = 0;
    int l = c0, r = c0;
    extend(a, l, r, len);
    ans = std::max(ans, mex(a, l, r));
    l = c1, r = c1;
    extend(a, l, r, len);
    ans = std::max(ans, mex(a, l, r));
    if(check(a, c0, c1)) {
        l = c0, r = c1;
        extend(a, l, r, len);
        ans = std::max(ans, mex(a, l, r));
    }
    printf("%d\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}