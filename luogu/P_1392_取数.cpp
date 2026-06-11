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

struct CMP {
    bool operator () (const std::pair<i64, veci>& a, const std::pair<i64, veci>& b) const {
        return a.first < b.first;
    }
};

void solve() {
    int n, m, k;
    readInt(n, m, k);
    std::vector<veci64> a(n);
    for(int i=0;i<n;++i) {
        a[i].resize(m);
        for(int j=0;j<m;++j)
            readInt(a[i][j]);
        std::sort(a[i].begin(), a[i].end());
    }
    std::multiset< std::pair<i64, veci> , CMP > set;
    i64 minsum = 0;
    for(int i=0;i<n;++i)
        minsum += a[i][0];
    set.emplace(minsum, veci(n, 0));
    while(k--) {
        auto sum = set.begin()->first;
        auto vec = set.begin()->second;
        set.erase(set.begin());
        printf("%lld ", sum);
        for(int i=0;i<n;++i) {
            if(vec[i] == m-1)continue;
            ++vec[i];
            set.emplace(sum + a[i][vec[i]] - a[i][vec[i]-1], vec);
            --vec[i];
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