#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long i64;

int n;
i64 a[200010];

int get(i64 x, int k) {
    return ((x >> k) & 1);
}

bool check(int l, int r, int k) {
    if (l > r)
        return true;
    if (k < 0)
        return true;
    int last = 0;
    for (int i = l; i <= r; ++i) {
        int cur = ((a[i] >> k) & 1);
        if (cur < last)
            return false;
        last = cur;
    }
    return true;
}

i64 handle(int l, int r, int k) {
    if (k < 0)
        return 0;
    int last = l;
    bool nocur = true;
    bool nonxt = true;
    for (int i = l; i <= r; ++i) {
        if (i == r || get(a[i], k + 1) != get(a[i + 1], k + 1)) {
            //[last, i]
            int b0 = last - 1;
            int b1 = i + 1;
            for (int j = last; j <= i; ++j) {
                b0 = std::max(b0, j);
                b1 = std::min(b1, j);
            }
            if (b0 > b1) {
                nocur = false;
                break;
            }
            last = i + 1;
        }
    }
    last = l;

    if (nocur) {
        return 0 + handle(l, r, k - 1);
    }
    
    for (int i = l; i <= r; ++i) {
        if (i == r || get(a[i], k + 1) != get(a[i + 1], k + 1)) {
            //[last, i]

            int sd0 = l;
            while (sd0 <= i && get(a[sd0], k - 1) == 0)
                ++sd0;
            while (sd0 <= i && get(a[sd0], k - 1) == 1)
                ++sd0;

            for (int j = last; j < sd0; ++j)
                a[i] &= ~(1 << k);
            for (int j = sd0; j <= i; ++j)
                a[i] |= (1 << k);
            
            last = i + 1;
        }
    }

    return handle(l, r, k - 1) + (1ll << k);
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", a + i);
    i64 ans = handle(1, n, 30);
    printf("%lld\n", ans);
    
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }

    return 0;
}
