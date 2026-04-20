#include <cstdio>
#include <set>
#include <climits>
#include <algorithm>
#include <vector>

typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

int main() {
    int n;scanf("%d", &n);
    veci t(n+1);
    for(int i=1;i<=n;++i) {
        scanf("%d", &t[i]);
    }
    veci64 a(n+1);
    for(int i=1;i<=n;++i) {
        scanf("%lld", &a[i]);
    }
    for(int i=1;i<=n;++i) {
        a[i] *= 2ll;
    }
    veci dir(n+1);
    std::vector<veci> fwd(n+1);
    for(int i=1;i<=n;++i) {
        if(a[t[i]] < a[i])
            dir[i] = -1;
        else 
            dir[i] = 1;
    }
    for(int i=1;i<=n;++i) {
        fwd[t[i]].push_back(i);
    }
    std::set<std::pair<i64, int> > set;
    for(int i=1;i<=n;++i) {
        if(dir[i] == dir[t[i]]) {
            set.insert({LLONG_MAX, i});
        } else {
            set.insert({(a[t[i]] - a[i]) * dir[i] / 2ll, i});
        }
    }
    std::vector<i64> ans(n+1, -1);
    while(set.size()) {
        int cur = set.begin()->second;
        int time = set.begin()->first;
        ans[cur] = time;
        set.erase(set.begin());

        for(auto y:fwd[cur]) {
            if(ans[y] != -1)
                continue;
            if(dir[y] == dir[cur]) {
                set.erase({LLONG_MAX, y});
                set.insert({time + (a[t[y]] - a[y]) * dir[y], y});
            } else {
                i64 prv = (a[t[y]] - a[y]) * dir[y] / 2ll;
                i64 now = prv + prv - time;
                set.erase({prv, y});
                set.insert({now, y});
            }
        }
    }
    for(int i=1;i<=n;++i)
        printf("%lld ", ans[i]);
    printf("\n");

    return 0;
}