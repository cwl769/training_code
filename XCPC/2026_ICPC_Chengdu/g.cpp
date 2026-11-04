#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

int a[1010][1010];
int e[1010][1010];

bool check(int n) {
    bool fit = true;
    int m = 0;
    veci deg(n + 2);
    for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
        if(e[i][j]) {
            ++m;
            ++deg[i];
            ++deg[j];
        }
    for (int i = 2; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) {
        if(!fit)break;
        int b = m - deg[i] - deg[j] + e[i][j];
        if(b != a[i][j]) {
            fit = false;
            break;
        }
    }
    return fit;
}

void solve() {
    int n;scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
        scanf("%d", &a[i][j]);
    if(n <= 5) {
        std::vector<PII> edg;
        for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            edg.emplace_back(i, j);
        int tmp = edg.size();
        int tot = (1 << tmp);
        // for (auto [x, y] : edg)
        //     printf("{%d, %d} ", x, y);
        // printf("\n");
        for (int s = 0; s < tot; ++s) {
            for (int i = 0; i < tmp; ++i) {
                e[edg[i].first][edg[i].second] = ((s >> i) & 1);
                e[edg[i].second][edg[i].first] = ((s >> i) & 1);
            }

            if(check(n)) {
                for (int i = 1; i <= n; ++i){
                    for (int j = 1; j <= n; ++j)
                        printf("%d ", e[i][j]);
                    printf("\n");
                }
                return;
            }
        }
        return;
    }
    veci r(n + 2);
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
        if(a[i][j] != -1)
            r[i] += a[i][j];
    }
    for (int d1 = 0; d1 < n; ++d1) {
        veci mh(n + 2);
        bool fit = true;
        int tmp = 0;
        for (int i = 2; i <= n; ++i) {
            if((r[i] - d1) % (n - 4) == 0) {
                mh[i] = (r[i] - d1) / (n - 4);
                e[1][i] = e[i][1] = 0;
            } else if(d1 && (r[i] - d1 + 1) % (n - 4) == 0) {
                mh[i] = (r[i] - d1 + 1) / (n - 4);
                e[1][i] = e[i][1] = 1;
                ++tmp;
            } else {
                fit = false;
                break;
            }
            if(mh[i] < 0) {
                fit = false;
                break;
            }
        }
        if(tmp != d1)fit = false;
        if(fit) {
            i64 m = 0;
            for (int i = 2; i <= n; ++i)
                m += mh[i];
            m -= d1;
            if(m % (n - 3)) continue;
            m /= (n - 3);
            for (int i = 2; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j) {
                e[i][j] = e[j][i] = a[i][j] + m - mh[i] - mh[j];
            }
            if(check(n)) {
                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j <= n; ++j)
                        printf("%d ", e[i][j]);
                    printf("\n");
                }
                return;
            }
        }
    }
}

int main() {
    int T;scanf("%d", &T);
    while(T--)
        solve();

    return 0;
}