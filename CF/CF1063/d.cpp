#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>

typedef long long int64;

template<typename T>
void readInt(T& x) {
    static bool f;
    x = 0;f = false;
    char c = getchar();
    for(;c<'0' || c>'9';c=getchar())if(c=='-')f=!f;
    for(;'0'<=c&&c<='9';c=getchar()) {
        x = x * 10 + c - '0';
    }
    if(f)x = -x;
}
template<typename T, typename ...Args>
void readInt(T& x, Args&... args) {
    readInt(x);
    readInt(args...);
}

int query(int l, int r) {
    printf("? %d %d\n", l, r);
    fflush(stdout);
    int ans;readInt(ans);
    return ans;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n, q;readInt(n, q);
        std::vector<std::pair<int, int> > range;
        for(int i=0;i<q;++i) {
            int l, r;readInt(l, r);
            range.push_back({l, r});
        }
        std::sort(range.begin(), range.end());
        std::vector<std::pair<int, int> > good_range;
        auto it = range.begin();
        for(int l=1, cur=0;l<=n;++l) {
            int maxr = 0;
            while(it!=range.end() && it->first==l) {
                maxr = std::max(maxr, it->second);
                ++it;
            }
            if(!maxr)continue;
            if(maxr <= cur)continue;
            cur = maxr;
            good_range.push_back({l, maxr});
        }
        int tmp = query(1, n/2);
        int ans = 0;
        if(tmp) {
            //delete all l > mid;
            for(auto rg:good_range) {
                int l = rg.first, r = rg.second;
                if(l > n/2) continue;
                ans = std::max(ans, query(l, r));
            }
        } else {
            //delete all r <= mid
            for(auto rg:good_range) {
                int l = rg.first, r = rg.second;
                if(r<=n/2) continue;
                ans = std::max(ans, query(l, r));
            }
        }
        printf("! %d\n", ans);
        fflush(stdout);
    }

    return 0;
}