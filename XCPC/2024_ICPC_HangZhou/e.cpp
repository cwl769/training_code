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

struct Range {
    i64 l, r;
    int id;
};

bool operator < (Range a, Range b) {
    if(a.l == b.l)return a.r < b.r;
    return a.l < b.l;
}

void solve() {
    int n;i64 f;readInt(n, f);
    std::vector<Range> vec(n+1);
    for(int i=1;i<=n;++i) {
        readInt(vec[i].l, vec[i].r);
        vec[i].id = i;
    };
    std::sort(vec.begin()+1, vec.end());
    int64 ans = 0;
    vec[0].r = LLONG_MAX;
    for(itn i=1;i<=n;++i) {
        ans += vec[i].r - vec[i].l;
        if(vec[i].l < )
    }
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}