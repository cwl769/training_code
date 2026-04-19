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
        int n;readInt(n);
        std::vector<int> cnt(n*2+1);
        for(int i=1;i<=n*2;++i) {
            int x;readInt(x);
            ++cnt[x];
        }
        int cnt4 = 0, cnt2 = 0, cnt1 = 0;
        for(int x=1;x<=n*2;++x) {
            if(cnt[x]==0)continue;
            if((cnt[x]&0b11)==0b00)
                ++cnt4;
            else if((cnt[x]&1)==0)
                ++cnt2;
            else
                ++cnt1;
        }
        int ans = 0;
        ans += cnt2 * 2;
        if(cnt4&1) {
            if(cnt1>=2) {
                ans += cnt4*2;
            } else {
                ans += (cnt4-1)*2;
            }
        } else {
            ans += cnt4*2;
        }
        ans += cnt1;
        printf("%d\n", ans);
    }

    return 0;
}