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

char s[1000010], t[1000010];

void solve() {
    int n, k;readInt(n, k);
    scanf("%s%s", s, t);
    std::vector<int> d(n);
    int p = n - 1;
    for(int i=n-1;i>=0;--i) {
        while(p>i)--p;
        while(s[p]!=t[i] && i-p<k && p>0) --p;
        if(s[p]!=t[i]) {
            printf("-1\n");
            return;
        }
        d[i] = i-p;
    }
    int ans = 0;
    for(int i=0;i<n;++i)
        ans = std::max(ans, d[i]);
    printf("%d\n", ans);
    for(int t=ans;t>0;--t) {
        for(int i=n-1;i>=0;--i) {
            if(t<=d[i]) {
                s[i-t+1] = s[i-t];
            }
        }
        printf("%s\n", s);
    }
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        solve();
    }

    return 0;
}