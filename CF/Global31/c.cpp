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
        int n, k;readInt(n, k);
        if(k&1) {
            for(int i=1;i<=k;++i)
                printf("%d ", n);
            printf("\n");
            continue;
        }
        int free = 0;
        std::vector<int> ans(k);
        for(int t=30;t>=0;--t) {
            if((n>>t)&1) {
                if(free < k) {
                    for(int i=0;i<k;++i) {
                        if(i==free)continue;
                        ans[i] |= (1<<t);
                    }
                    ++free;
                } else {
                    for(int i=1;i<k;++i) {
                        ans[i] |= (1<<t);
                    }
                }
            } else {
                int cnt = (free/2)*2;
                for(int i=0;i<cnt;++i) {
                    ans[i] |= (1<<t);
                }
            }
        }
        for(auto x:ans)
            printf("%d ", x);
        printf("\n");
    }

    return 0;
}