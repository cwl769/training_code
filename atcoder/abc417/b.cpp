#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <algorithm>
#include <set>


std::multiset<int> a;

int main() {
    int n, m;scanf("%d%d", &n, &m);
    for(int i=1;i<=n;++i) {
        int x;scanf("%d", &x);
        a.insert(x);
    }
    for(int i=1;i<=m;++i) {
        int x;scanf("%d", &x);
        auto it = a.find(x);
        if(it!=a.end())
            a.erase(it);
    }
    for(auto it=a.begin();it!=a.end();++it) {
        printf("%d ", *it);
    }
    return 0;
}