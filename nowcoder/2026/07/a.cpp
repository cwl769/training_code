#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
typedef long long i64;
typedef std::pair<int, int> PII;
int n;
i64 a[200010];

i64 get(i64 x, i64 k) {
    if (k < 0)
        return 0;
    return ((x >> k) & 1);
}

i64 lowbit(i64 x) {
    return x & (-x);
}

i64 b[200010];

i64 getv(i64 k, i64 val) {
    i64 ans = 0;
    for(i64 i = 31; i >= 0; --i) {
        if(get(k, i) == 1)
            ans = ((ans << 1) | get(val, i));
    }
    return ans;
}

i64 setv(i64 k, i64 val, i64 cov) {
    i64 ans = (val & (~k));
    // printf("setv ans = %lld\n", ans);
    i64 cnt = 0;
    for(i64 i = 0; i <= 31; ++i) {
        if(get(k, i) == 1)
            ans = (ans | (get(cov, cnt++)<<i));
    }
    return ans;
}

i64 highbit(i64 val) {
    i64 ans = (1ll << 60);
    while(ans > val)
        ans >>= 1;
    return ans;
}

i64 popcount(i64 val) {
    i64 ans = 0;
    for(int i = 60; i >= 0; --i)
        if((val >> i) & 1)
            ++ans;
    return ans;
}

bool check(i64 k) {
    // printf("check %lld\n", k);
    b[1] = (a[1] & (~k));
    for(int i = 2; i <= n; ++i) {
        b[i] = (a[i] & (~k));
        if(b[i] >= b[i-1])
            continue;
        if((b[i] | k) < b[i-1])
            return false;
        i64 cur = 0;
        for(i64 j = 30; j >= 0; --j) {
            if(get(k, j) == 0)
                continue;
            cur <<= 1;
            if((b[i] | (1ll << j)) < b[i-1]) {
                b[i] |= (1ll << j);
                cur |= 1;
            }
        }
        b[i] = setv(k, b[i], cur + 1);
        // printf("b[%d] = %lld\n", i, b[i]);
    }
    return true;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", a + i);
    i64 ans = 0;
    for(i64 i = 31; i >= 0; --i) {
        if(check(ans + ((1<<i)-1))) {

        } else {
            ans += (1 << i);
        }
    }
    printf("%lld\n", ans);
    // check(6);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }

    return 0;
}
