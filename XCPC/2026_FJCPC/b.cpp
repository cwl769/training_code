#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

int main() {
    int n, m;scanf("%d%d", &n, &m);
    veci64 rr(m + 2), cc(m + 2);
    for (int i = 1; i <= m; ++i)
        scanf("%lld%lld", &rr[i], &cc[i]);

    auto check = [n, m, &rr, &cc](i64 d)-> bool {
        i64 avi = 0;
        for (int i = 1; i <= m; ++i) {
            avi += 1ll * rr[i] * ((cc[i] - 1) / (d + 1) + 1);
        }
        return avi >= n;
    };

    i64 l = 0, r = 0x3f3f3f3f;
    while(l < r) {
        i64 mid = ((l + r + 1) >> 1);
        if(check(mid))
            l = mid;
        else 
            r = mid - 1;
    }
    printf("%lld\n", l);

    return 0;
}