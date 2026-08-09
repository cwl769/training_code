#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n + 2), cnt(n + 2);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        ++cnt[a[i]];
    }
    int ans = n;
    for (int c = 1; c <= n; ++c) {
        ans = std::min(ans, n - cnt[c]);
    }
    printf("%d\n", ans);


    return 0;
}
