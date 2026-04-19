#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cstdint>
#include <algorithm>
#include <vector>

typedef long long int64;

int64 pow[17] = {1};
int64 cnt[17];
int64 cs[17];
int64 ls[17];
int64 s[10] = {0, 1, 3, 6, 10, 15, 21, 28, 36, 45};

int main() {
    for(int64 i=1,t=10;i<17;++i,t*=10) {
        cnt[i] = t - 1ll - cs[i-1];
        cs[i] = t - 1;
        ls[i] = ls[i-1] + cnt[i] * (int64)i;
        pow[i] = pow[i-1] * 10ll;
    }
    // for(int i=1;i<17;++i) {
    //     printf("%20lld %20lld [%2d]%20lld\n", cnt[i], cs[i], i, ls[i]);
    // }
    int T;scanf("%d", &T);
    for(;T;--T) {
        int64 k;scanf("%lld", &k);
        int64 i = std::upper_bound(ls, ls+17, k) - ls;
        --i;
        // printf("i=%lld\n", i);
        int64 h, r;
        h = pow[i] - 1ll + (k-ls[i]) / (i+1ll);
        r = (k - ls[i]) % (i+1ll);
        int64 hh = h;
        // printf("h=%lld\n", h);
        // printf("r=%lld\n", r);
        int64 ans = 0ll;
        for(int64 b=1,r=0;h;h/=10ll,b*=10ll) {
            ans += b * (45ll * (h/10ll));
            int rrr = h%10;
            if(rrr) {
                ans += b * s[rrr-1] + ((r + 1ll) * (int64)rrr);
            }
            r += b * rrr;
        }
        if(r) {
            int64 t = hh + 1;
            std::vector<int> vec;
            for(;t;t/=10)vec.push_back(t%10);
            for(int i=vec.size()-1;r;--i,--r) {
                ans += vec[i];
            }
        }
        printf("%lld\n", ans);
    }


    return 0;
}