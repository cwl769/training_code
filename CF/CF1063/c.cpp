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

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<std::vector<int> > map(3);
        map[1].resize(n+1);
        map[2].resize(n+1);
        for(int i=1;i<=2;++i)
        for(int j=1;j<=n;++j)
            readInt(map[i][j]);
        std::vector<int> premax(n+1), premin(n+1), sufmax(n+2), sufmin(n+2);
        premin[0] = INT_MAX;
        sufmin[n+1] = INT_MAX;
        for(int i=1;i<=n;++i) {
            premin[i] = std::min(premin[i-1], map[1][i]);
            premax[i] = std::max(premax[i-1], map[1][i]);
        }
        for(int i=n;i>=1;--i) {
            sufmin[i] = std::min(sufmin[i+1], map[2][i]);
            sufmax[i] = std::max(sufmax[i+1], map[2][i]);
        }
        // printf("premin:");
        // for(int i=1;i<=n;++i) {
        //     printf("%d ", premin[i]);
        // }
        // printf("\n");
        // printf("premax:");
        // for(int i=1;i<=n;++i) {
        //     printf("%d ", premax[i]);
        // }
        // printf("\n");
        // printf("sufmin:");
        // for(int i=1;i<=n;++i) {
        //     printf("%d ", sufmin[i]);
        // }
        // printf("\n");
        // printf("sufmax:");
        // for(int i=1;i<=n;++i) {
        //     printf("%d ", sufmax[i]);
        // }
        // printf("\n");
        std::vector<std::pair<int, int> > query;
        
        for(int i=1;i<=n;++i) {
            int l, r;
            l = std::min(premin[i], sufmin[i]);
            r = std::max(premax[i], sufmax[i]);
            query.push_back({r, l});
        }
        std::sort(query.begin(), query.end());
        // for(auto x:query) {
        //     printf("{%d %d}", x.first, x.second);
        // }
        // printf("\n");
        auto it = query.begin();
        int64 ans = 0;
        for(int r=1,mxl=0;r<=n*2;++r) {
            // printf("r=%d\n", r);
            while(it!=query.end()&&it->first==r) {
                mxl = std::max(mxl, it->second);
                ++it;
            }
            // printf("r=%d\n", r);
            ans += mxl;
        }
        // int64 ans = 1ll * l * (2ll*n-r+1ll);
        printf("%lld\n", ans);
    }

    return 0;
}