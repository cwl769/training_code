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
typedef std::pair<int, int> Pii;
typedef std::pair<int, i64> Pii64;
typedef std::pair<i64, int> Pi64i;
typedef std::pair<i64, i64> Pi64i64;

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

struct Fenwick {
    int *c;
    int N;
    Fenwick(int n) {
        N = n + 10;
        c = (int*)calloc(N, sizeof(int));
    }
    ~Fenwick() {
        free(c);
    }
    void add(int x, int v) {
        for(;x<N;x+=(x&(-x)))
            c[x] += v;
    }
    int get(int x) {
        int ans = 0;
        for(;x;x-=(x&(-x))) {
            ans += c[x];
        }
        return ans;
    }
};

void solve() {
    int n;readInt(n);
    veci a(n+1);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    
    i64 ans = 0;
    Fenwick tree(n+1);
    for(int i=1;i<=n;++i)
        tree.add(i, 1);
    std::vector<std::pair<int, int> > chg;
    for(int i=1;i<=n;++i) {
        chg.push_back({a[i], i});
    }
    std::sort(chg.begin(), chg.end(), [](Pii a, Pii b)->bool {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });
    i64 mx = 0;
    for(i64 h=1,sum=0,it=0;h<=n;++h) {
        while(it<(i64)chg.size() && chg[it].first+1 == h) {
            int i = chg[it].second;
            sum += tree.get(i - 1);
            int ori = n - i;
            int now = tree.get(n) - tree.get(i);
            sum -= ori - now;
            tree.add(i, -1);
            ++it;
        }
        if(it<(i64)chg.size() && chg[it].first == h) {
            int i = chg[it].second;
            int ori = n - i;
            int now = tree.get(n) - tree.get(i);
            mx = std::max(mx, (i64)tree.get(i - 1) - ori + now);
        }
        // printf("[%lld]%lld\n", h, sum);
        ans += sum;
    }

    // printf("%lld %lld\n", ans, mx);

    ans += mx;

    printf("%lld\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}