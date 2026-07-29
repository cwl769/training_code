#include <bits/stdc++.h>
#include <utility>
using namespace std;
typedef long long i64;
typedef std::pair<int, int> PII;
const i64 MOD = 998244353;

int p[30];
int pp[30];
bool lmap[30][30];
i64 dp[4194304];
int g[30];

int getbit(int x, int p) {
    return (x >> p) & 1;
}

int main() {
    //memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        pp[i] = p[i];
    }
    vector<PII> lm;
    for (int v = n; v >= 1; --v) {
        int pos = 1;
        while (pp[pos] != v)
            ++pos;
        for (int i = pos; i + 1 <= v; ++i) {
            std::swap(pp[i], pp[i + 1]);
            lm.emplace_back(pp[i]-1, v-1);
            lmap[pp[i]-1][v-1] = 1;
        }
    }

    int cov = (1<<n);
    dp[0] = 1;

    for (auto [x, y] : lm) {
        g[y] |= (1 << x);
    }

    for (int s = 0; s < cov; ++s) {
        for (int i = 0; i < n; ++i) {
            if (getbit(s, i))
                continue;
            if ((g[i] & s) == g[i]) {
                (dp[s^(1<<i)] += dp[s]) %= MOD;
            }
        }
    }

    if (lm.size()) {
        printf("%lld\n", dp[cov-1] * 2ll % MOD);
    } else {
        printf("%lld\n", dp[cov-1]);
    }

    return 0;
}
