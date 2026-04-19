#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>

typedef long long int64;

int main() {
    int T;scanf("%d", &T);
    for(;T;--T) {
        int64 m;scanf("%lld", &m);
        int64 y = 1000000000000000000ll;
        std::vector<int64> ans;
        for(;y>=10;y/=10) {
            int64 d = y + 1ll;
            if(m%d == 0) {
                ans.push_back(m/d);
            }
        }
        if(!ans.empty()) {
            printf("%lld\n", (int64)ans.size());
            for(int i=0;i<ans.size();++i) {
                printf("%lld ", ans[i]);
            }
            printf("\n");
        } else {
            printf("0\n");
        }
    }


    return 0;
}