#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <algorithm>
#include <set>
#include <map>

int a[200010];

int main() {
    int n;scanf("%d", &n);
    for(int i=1;i<=n;++i)
        scanf("%d", a+i);
    std::map<int, int> set;
    long long int ans = 0;
    for(int i=1;i<=n;++i) {
        auto it = set.find(i-a[i]);
        if(it!=set.end()) {
            ans += it->second;
        }
        it = set.find(i+a[i]);
        if(it==set.end()) {
            set.insert({i+a[i], 1});
        } else {
            ++it->second;
        }
    }
    printf("%lld", ans);
    return 0;
}