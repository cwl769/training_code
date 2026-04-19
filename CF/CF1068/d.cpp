#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

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
        int64 n;int k;readInt(n, k);
        if(k==0) {
            printf("0\n");
            continue;
        }
        int cnt[2] = {0, 0};
        n<<=1ll;
        std::vector<std::pair<int, int> > vec; 
        for(int i=1;i<=40;++i) {
            if((n>>i)&1ll) {
                if(((n>>(i-1))&1ll)==0) {
                    if(cnt[0]||cnt[1])
                    vec.push_back({cnt[0], cnt[1]});
                    cnt[1] = 1;
                    cnt[0] = 0;
                } else {
                    ++cnt[1];
                }
            } else {
                if(cnt[1])++cnt[0];
            }
        }
        vec.push_back({0, cnt[1]});
        // for(auto x:vec)
        //     printf("{%d %d}\n", x.first, x.second);
        // printf("\n");
        int need = 0;
        if(vec.size() != 1) {
            for(auto x:vec)
                need += x.first;
            ++need;
        }
        if(k>=need) {
            int tmp = -1;
            for(auto x:vec)
                tmp += x.second;
            printf("%d\n", k + tmp);
            continue;
        }

        std::vector< std::vector<int> > f(vec.size());
        for(int i=0;i<(int)f.size();++i)
            f[i].resize(k+1);
        f[0][0] = 0;
        f[0][1] = vec[0].second;
        for(int i=1;i<(int)f.size();++i)
        for(int t=1;t<=k;++t)
        {
            f[i][t] = f[i-1][t];
            int cost = 1;
            int val = vec[i].second;
            for(int j=i-1;j>=0;--j) {
                if(t-cost <0)break;
                f[i][t] = std::max(f[i][t], f[j][t-cost]+val);
                cost += vec[j].first;
                val += vec[j].second + vec[j].first;
            }
            if(t>=cost)
                f[i][t] = std::max(f[i][t], val);
        }
        int ans = 0;
        for(int i=0;i<=k;++i)
            ans = std::max(ans, f.back()[i] + k-i);
        // for(int i=0;i<(int)f.size();++i) {
        //     for(int j=0;j<=k;++j)
        //         printf("%2d ", f[i][j]);
        //     printf("\n");
        // }
        printf("%d\n", ans);
    }

    return 0;
}