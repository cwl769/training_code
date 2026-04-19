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

int BIT[250010];
int lowbit(int x){return x&(-x);}
void add(int x, int v){
    ++x;
    for(;x<250010;x+=lowbit(x)) 
        BIT[x] += v;
}
int query(int x) {
    ++x;
    int ans = 0;
    for(;x;x-=lowbit(x))
        ans += BIT[x];
    return ans;
}

int main() {
    int l, k, n;readInt(l, k, n);
    printf("%d %d %d\n", l, k, n);
    std::vector<int> a(n+1);
    for(int i=1;i<=n;++i) {
        readInt(a[i]);
        printf("a[%d]=%d\n", i, a[i]);
        add(a[i], 1);
    }
    printf("---\n");
    // std::vector<int64> f(n+1);
    int64 ans = 0;
    for(int i=1;i<=n;++i) {
        ans = (ans + 1 + (query(a[i]-1) - query(std::max(0, a[i]-k))) / 2) % M;
        if(a[i]+k>l) {
            ans = (ans + query(a[i]+k-l-1)/2) % M;
        }
        printf("after i: ans = %lld\n", ans);
    }
    printf("%lld\n", ans);

    return 0;
}