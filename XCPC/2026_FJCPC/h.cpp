#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

int acm(int n, int m) {
    int rest = n % 3;
    int ans = 0;
    if(rest == 0) {
        ans = m / 3;
    } else if(rest == 1) {
        if(n >= 4) {
            if(m == 0) ans = 0;
            else if(m < 4) ans = 1;
            else {
                ans = 2;
                m -= 4;
                ans += m / 3;
            }
        } else {
            if(m) ans = 1;
            else ans = 0;
        }
    } else if(rest == 2) {
        if(m >= 2) {
            m -= 2;
            ++ans;
        }
        ans += m / 3;
    }
    return ans;
} 

int gplt(int n, int m) {
    return std::min((n - 1) / 10 + 1, m / 6);
}

void solve() {
    int n, m;scanf("%d%d", &n, &m);
    printf("%d %d\n", acm(n, m), gplt(n, m));
}

int main() {
    int T;scanf("%d", &T);
    while(T--)solve();
    return 0;
}