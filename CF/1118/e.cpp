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

i64 gcd(i64 a, i64 b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

i64 lcm(i64 a, i64 b) { return a * b / gcd(a, b); }

veci prime;
bool pvis[200010];
void init() {
    pvis[0] = pvis[1] = 1;
    for (int x = 2; x < 200010; ++x) {
        if (!pvis[x]) {
            prime.emplace_back(x);
        }
        for (auto p : prime) {
            int t = p * x;
            if (t >= 200010)
                break;
            pvis[t] = 1;
            if (x % p == 0)
                break;
        }
    }
}

void solve() {
    int n;readInt(n);
    veci a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    
    
}

int main() {
    init();
    veci64 sp;
    for(auto p : prime) {
        for(i64 t = p; t <= 200000; t *= p) {
            sp.emplace_back(t);
        }
    }
    std::sort(sp.begin(), sp.end());
    for(auto x : sp)
        printf("%lld\n", x);
    printf("cnt:%d\n", (int)sp.size());
    fflush(stdout);
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
