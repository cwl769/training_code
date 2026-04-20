#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

typedef long long i64;
typedef long long int64;
typedef std::vector<i64> veci64;

int find(veci64 &s, veci64 &a, int i) {
    int l = 0, r = i-3;
    while(l < r) {
        int mid = ((l+r+1) / 2);
        if(s[mid]<=s[i-1]-a[i]-1)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

void solve() {
    int n;scanf("%d", &n);
    std::vector<i64> a(n+1);
    for(int i=1;i<=n;++i)
        scanf("%lld", &a[i]);
    std::sort(a.begin(), a.end());
    std::vector<int> ans(n+1);
    veci64 s(n+1);
    for(int i=1;i<=n;++i)
        s[i] = s[i-1] + a[i];
    for(int i=1;i<=n;++i) {
        if(s[i-1] <= a[i]) {
            continue;
        }
        int j = find(s, a, i);
        int len = i - j;
        ans[len] = i;
        assert(len >= 3);
    }
    int cur = 0;
    for(int k=1;k<=n;++k) {
        cur = std::max(cur, ans[k]);
        if(cur == 0)
            printf("0 ");
        else {
            if(cur-k>=0)
                printf("%lld ", s[cur] - s[cur - k]);
            else
                printf("0 ");
        }
    }
    printf("\n");
}

int main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }

    return 0;
}