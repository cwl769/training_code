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

const int64 M = 998244353;

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i) {
            readInt(a[i]);
        }
        std::vector<int> ctmp(n+1);
        for(int i=1;i<=n;++i) {
            ++ctmp[a[i]];
        }
        std::vector<int> cnt;
        for(int i=1;i<=n;++i) {
            if(ctmp[i])
                cnt.push_back(ctmp[i]);
        }
        std::sort(cnt.begin(), cnt.end());
        std::vector<int64> dp(n+1);
        dp[0] = 1;
        int64 ans = 0;
        int mxc = cnt.back();
        for(int i=0;i<(int)cnt.size();++i) {
            int t = mxc - cnt[i];
            for(int j=t;j<=n;++j)
                ans = (ans + (dp[j]*cnt[i])%M) % M;
            
            for(int j=n;j>=cnt[i];--j) {
                dp[j] = (dp[j] + (dp[j-cnt[i]] * cnt[i]) % M) % M;
            }
        }
        
        printf("%lld\n", ans);
    }

    return 0;
}