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

int count(int x) {
    int ans = 0;
    for(;x;x>>=1) {
        if(x&1)++ans;
    }
    return ans;
}

bool check(int s, int n, std::vector<int>& a) {
    for(int i=1;i<=n;++i)
    for(int j=i+1;j<=n;++j) {
        if(((s>>(i-1))&1) || ((s>>(j-1))&1))
            continue;
        if(a[i] + 1 == a[j])
            return false;
    }
    return true;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        int cov = (1<<n);
        int ans = INT_MAX;
        for(int s=0;s<cov;++s) {
            if(check(s, n, a)) {
                ans = std::min(ans, count(s));
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}