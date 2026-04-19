#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <cassert>
#include <map>
#include <set>

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

bool query(int i, int x) {
    printf("? %d %d\n", i, x);
    fflush(stdout);
    int tmp;readInt(tmp);
    assert(tmp!=-1);
    return tmp;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::map<int, bool> map;
        for(int i=1;i<=n;++i)
            map[i] = 0;
        int ans = 0;
        for(int i=0;i<=16;++i) {
            int cov = (1<<i);
            if(cov>n)continue;
            int shd[2] = {0, 0};
            for(int x=1;x<=n;++x) {
                if(((x^ans)&(cov-1))==0) {
                    ++shd[(x>>i)&1];
                }
            }
            // printf("%d shd %d %d\n", i, shd[0], shd[1]);
            int cnt[2] = {0, 0};
            for(auto &x:map) {
                int tmp = x.first;
                if(x.first==n)break;
                x.second = query(x.first, cov);
                ++cnt[x.second];
            }
            // printf("%d cnt %d %d\n", i, cnt[0], cnt[1]);
            
            std::set<int> set;
            if(cnt[0] < shd[0]) {
                for(auto x:map) {
                    if(x.second&&x.first!=n)
                        set.insert(x.first);
                }
            } else {
                for(auto x:map) {
                    if(!x.second&&x.first!=n)
                        set.insert(x.first);
                }
                ans |= cov;
            }
            for(auto x:set) {
                map.erase(x);
            }
        }
        printf("! %d\n", ans);
        fflush(stdout);
    }

    return 0;
}