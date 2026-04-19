#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
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
        int n, k;readInt(n, k);
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        std::vector<int> cnt(n+1);
        std::vector<std::pair<int, int> > qs;
        for(int i=1;i<=n;++i) {
            qs.push_back({1, 1});
            qs.push_back({a[i]/4+1, -1});
            int tmp = sqrt(a[i]);
            // printf("a[%d]=%d add [%d, %d]\n", i, a[i], 1, a[i]/4);
            for(int d=1;d<=tmp;++d) {
                if(a[i]%d==0) {
                    // printf("a[%d]=%d add %d\n", i, a[i], d);
                    if(d>a[i]/4)
                        ++cnt[d];
                    if(a[i]/d!=d && a[i]/d>a[i]/4)
                        ++cnt[a[i]/d];
                }
            }
        }
        std::sort(qs.begin(), qs.end());
        // for(auto x:qs) {
        //     printf("{%d, %d}\n", x.first, x.second);
        // }
        unsigned int it=0;
        int ans = 0;int tmpcnt = 0;
        for(int d=1;d<=n;++d) {
            while(it<qs.size() && qs[it].first <= d) {tmpcnt+=qs[it].second;++it;}
            // printf("%d ", cnt[d]+tmpcnt);
            if(n-cnt[d]-tmpcnt<=k)
                ans = d;
        }
        // printf("\n");
        printf("%d\n", ans);
    }

    return 0;
}