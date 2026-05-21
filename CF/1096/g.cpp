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
        for(;x;x-=(x&(-x)))
            ans += c[x];
        return ans;
    }
};

void solve() {
    int n;readInt(n);
    veci64 a(n+1);
    veci64 s(n+1);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    for(int i=1;i<=n;++i) {
        if(i&1)
            s[i] = s[i-1] + a[i];
        else
            s[i] = s[i-1] - a[i];
    }
    std::map<i64, int> map;
    for(int i=0;i<=n;++i)
        map[s[i]] = 0;
    int tot = 0;
    for(auto &pr:map) {
        ++tot;
        pr.second = tot;
    }
    // for(int i=0;i<=n;++i)
    //     printf("%d ", map[s[i]]);
    // printf("\n");
    Fenwick odd(n+1), even(n+1);
    even.add(map[s[0]], 1);
    i64 ans = 0;
    for(int i=1;i<=n;++i) {
        if(i&1) {
            ans += even.get(map[s[i]]-1);
            // printf("[%d]add %d\n", i, even.get(map[s[i]]-1));
            odd.add(map[s[i]], 1);
        } else {
            ans += odd.get(n+1) - odd.get(map[s[i]]);
            // printf("[%d]add %d\n", i, odd.get(n+1) - odd.get(map[s[i]]));
            even.add(map[s[i]], 1);
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}