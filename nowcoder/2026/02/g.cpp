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
#include <numeric>

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

const int N = 10000010;
bool pvis[N];
i64 mnp[N];
veci64 prime;

void Euler() {
    pvis[0] = pvis[1] = 1;
    for (i64 x = 2; x < N; ++x) {
        if (!pvis[x]) {
            prime.emplace_back(x);
            mnp[x] = x;
        }
        for (auto p : prime) {
            i64 tmp = p * x;
            if (tmp >= N)
                break;
            pvis[tmp] = 1;
            mnp[tmp] = p;
            if (x % p == 0)
                break;
        }
    }
}

i64 ceil(i64 a, i64 b) {
    if(a == 0)return 0;
    return (a - 1) / b + 1;
}

i64 getbit(i64 x, i64 pos) {
    return (x>>pos) & 1;
}

i64 floor(i64 a, i64 b) { return a / b; }

i64 popcnt(i64 x) {
    i64 ans = 0;
    for (i64 i = 0; i < 60; ++i) {
        if (getbit(x, i))
            ++ans;
    }
    return ans;
}

void solve() {
    i64 l, r, n;
    readInt(l, r, n);
    veci64 ps;
    i64 tn = n;
    while (tn > 1) {
        ps.emplace_back(mnp[tn]);
        tn /= mnp[tn];
    }
    ps.resize(std::unique(ps.begin(), ps.end()) - ps.begin());
    i64 pn = ps.size();
    i64 cov = (1ll << pn);
    i64 cnt = 0;
    for (int s = 1; s < cov; ++s) {
        i64 d = 1;
        for (i64 i = 0; i < pn; ++i) {
            if (getbit(s, i)) {
                d *= ps[i];
            }
        }
        i64 val = floor(r, d) - ceil(l, d) + 1;
        //printf("[%d|%d] %lld\n", s, popcnt(s), val);
        if (popcnt(s) & 1) {
            cnt += val;
        } else {
            cnt -= val;
        }
    }
    i64 pcnt = (r - l + 1ll) - cnt;
    i64 ans = pcnt + 2ll * cnt;
    
    i64 upb = 300;
    veci64 dis(upb+2, 0x3f3f3f3f);
    dis[0] = 0;
    for (int d = 1; d <= upb; ++d) {
        int x = n - d;
        if (x < 1)
            break;
        dis[d] = std::gcd(x, n);
        for (int y = x + 1; y < n; ++y) {
            dis[d] = std::min(dis[d], dis[n-y] + std::gcd(x, y));
        }
    }
    for (int i = std::max(1ll, n - upb + 1); i <= r; ++i) {
        if (l <= i && i <= r) {
            int my = ((std::gcd(i, n) == 1) ? 1 : 2);
            ans += dis[n-i] - my;
        }
    }
    
    printf("%lld\n", ans);
}

int main() {
    Euler();
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
