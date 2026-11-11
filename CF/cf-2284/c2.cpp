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
    if(b == 0)return a;
    return gcd(b, a % b);
}

bool pvis[100010];
veci prime;

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

bool isprime(i64 x) {
    i64 t = sqrt(x);
    for (i64 i = 2; i <= t; ++i)
        if(x % i == 0)
            return false;
    return true;
}

void solve() {
    i64 a, b;readInt(a, b);
    if(a == b) {
        printf("0\n");
        return;
    }
    if(gcd(a, b) == 1) {
        printf("1\n%lld\n", b - a);
        return;
    }
    
    for(i64 p = b - 1; p > a; --p) {
        if(gcd(a, p) == 1 && gcd(b, p) == 1) {
            printf("2\n%lld %lld\n", p - a, b - p);
            return;
        }
    }

    i64 n = b - a;
    veci dis(b - a + 1, 1e9);
    veci pre(b - a + 1, 0);
    dis[0] = 0;
    std::queue<int> q;
    q.emplace(0);
    while(q.size()) {
        int x = q.front(); q.pop();
        for (int y = x + 1; y <= n; ++y) {
            if(gcd(a + x, a + y) != 1) continue;
            if(dis[x] + 1 < dis[y]) {
                dis[y] = dis[x] + 1;
                pre[y] = x;
                q.emplace(y);
            }
        }
    }
    veci64 ans;
    int x = n;
    while(x) {
        ans.emplace_back(x - pre[x]);
        x = pre[x];
    }
    std::reverse(ans.begin(), ans.end());
    printf("%d\n", dis[n]);
    for (auto x : ans)
        printf("%lld ", x);
    printf("\n");
}

int main() {
    // Euler();
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}