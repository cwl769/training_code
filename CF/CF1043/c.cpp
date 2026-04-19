#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>

typedef long long int64;

int64 pow3[21];
int64 c[20];

int main() {
    pow3[0] = 1;
    for(int x=1;x<21;++x) {
        pow3[x] = pow3[x-1] * 3ll;
    }
    c[0] = 3;
    for(int x=1;x<20;++x) {
        c[x] = pow3[x+1] + pow3[x-1] * (int64)x;
    }
    int T;scanf("%d", &T);
    for(;T;--T) {
        int k;
        int64 n;scanf("%lld%d", &n, &k);
        int64 ans = 0;
        
        std::vector<int64> vec;
        for(;n;n/=3) {
            vec.push_back(n%3ll);
            k -= (n%3ll);
        }
        if(k < 0) {
            printf("-1\n");
            continue;
        }

        k /= 2;
        for(int x=vec.size()-1;x;--x) {
            if(!k)break;
            int64 t = std::min(vec[x], (int64)k);
            vec[x] -= t;
            vec[x-1] += t * 3ll;
            k -= t;
        }
        // for(auto x:vec) {
        //     printf("%lld ", x);
        // }
        // printf("\n");
        
        for(int x=vec.size()-1;x>=0;--x) {
            ans += c[x] * (int64)vec[x];
        }

        printf("%lld\n", ans);
    }


    return 0;
}