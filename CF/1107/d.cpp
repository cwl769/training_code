#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

bool solve() {
    int n;
    scanf("%d", &n);
    veci a(n + 2), b(n + 2);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    veci64 sa(n + 2), sb(n + 2);
    for (int i = 1; i <= n; ++i)
        sa[i] = sa[i - 1] + a[i];
    for (int i = 1; i <= n; ++i)
        sb[i] = sb[i - 1] + b[i];
    for (int i = 1; i <= n; ++i) {
        if (sa[i] > sb[i])
            return false;
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        if (solve()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
