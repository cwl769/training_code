#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

void solve() {
    int x;
    scanf("%d", &x);
    int len = 0;
    for (int t = x; t; t /= 10)
        ++len;
    int ans = 1;
    for (int i = 0; i < len; ++i)
        ans = ans * 10;
    if (ans != 1)
        ++ans;
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }

    return 0;
}
