#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <algorithm>
#include <vector>

struct data {
    int l, r;
    int id;
};
bool cmp(data a, data b) {
    if(a.l==b.l) return a.r > b.r;
    return a.l < b.l;
}

int main() {
    int T;scanf("%d", &T);
    for(;T;--T) {
        std::vector<data> vec;
        int n;scanf("%d", &n);
        for(int i=1;i<=n;++i) {
            int x, y;scanf("%d%d", &x, &y);
            vec.push_back({x, y, i});
        }
        std::sort(vec.begin(), vec.end(), cmp);
        int ans = 0;
        std::vector<int> ind;
        int lastl = 0;
        int nr = 0;
        for(auto it=vec.begin();it!=vec.end();++it) {
            if(it->l == lastl)continue;

            if(it->r > nr) {
                nr = it->r;
                ++ans;
                ind.push_back(it->id);
            }

            lastl = it->l;
        }
        printf("%d\n", ans);
        for(auto it:ind) {
            printf("%d ", it);
        }
        printf("\n");
    }
    return 0;
}