#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

void solve() {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x % y == 0)
        printf("YES\n");
    else
        printf("NO\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }

    return 0;
}
