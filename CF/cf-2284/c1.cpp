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

bool pvis[100010];
veci prime;
veci64 tar;

void Euler() {
    pvis[0] = pvis[1] = 1;
    for (int x = 2; x < 100010; ++x) {
        if(!pvis[x]) {
            prime.emplace_back(x);
        }
        for (auto p : prime) {
            i64 tmp = p * x;
            if(tmp >= 100010)
                break;
            pvis[tmp] = 1;
            if(x % p == 0)
                break;
        }
    }
}

void solve() {
    int n;readInt(n);
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    for (int i = 1; i <= n; ++i) {
        printf("%lld ", *std::lower_bound(tar.begin(), tar.end(), a[i]));
    }
    printf("\n");
}

int main() {
    Euler();
    for (i64 p : prime) {
        for (i64 t = p; t < 100010; t *= p) {
            // printf("%lld %lld\n", p, t);
            tar.emplace_back(t);
        }
    }
    std::sort(tar.begin(), tar.end());
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}