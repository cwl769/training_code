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

int64 bit[200010];
int lowbit(int x){return (x)&(-x);}
void add(int x, int64 v) {
    for(;x<200010;x+=lowbit(x))
        bit[x] += v;
}
int64 query(int x) {
    int64 ans = 0;
    for(;x;x-=lowbit(x))
        ans += bit[x];
    return ans;
}

int main() {
    int n, q;readInt(n, q);
    std::vector<int> a(n+1);
    for(int i=1;i<=n;++i) {
        readInt(a[i]);
        add(i, a[i]);
    }
    int dt = 0;
    for(;q;--q) {
        int op;readInt(op);
        if(op==1) {
            int c;readInt(c);
            dt += c;
            dt %= n;
        } else {
            int l, r;readInt(l, r);
            if(l + dt > n) {
                int64 ans = query((r+dt)%n) - query((l+dt-1)%n);
                printf("%lld\n", ans);
            } else if(r + dt > n) {
                int64 ans = query(n) - query(l+dt-1) + query((r+dt)%n);
                printf("%lld\n", ans);
            } else {
                int64 ans = query(r+dt) - query(l+dt-1);
                printf("%lld\n", ans);
            }
        }
    }

    return 0;
}