#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
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

void solve() {
    int n;readInt(n);
    std::vector<int> a(n+1);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    int evencnt = 0;
    for(int i=1;i<=n;++i)
        if(!(a[i]&1))
            ++evencnt;
    if(evencnt > 1) {
        int cnt = 0;
        for(int i=1;i<=n;++i) {
            if(!(a[i]&1)) {
                printf("%d ", a[i]);
                ++cnt;
                if(cnt==2)
                    break;
            }
        }
        printf("\n");
        return;
    }
    std::set<int> set;
    for(int i=1;i<=n;++i) {
        int t = sqrt(a[i]);
        int y = a[i];
        for(int j=1;j<i;++j) {
            if(a[j] > t)
                break;
            int x = a[j];
            if(x&1) {
                if(((y/x)&1)==(y&1)) {
                    printf("%d %d\n", x, y);
                    return;
                }
            }
        }
        for(int k=((y&1)?1:2);k<=t;k+=2) {
            int l = y/(k+1)+1;
            int r = y/k;
            if(l>r)
                continue;
            auto beg = set.lower_bound(l);
            auto end = set.upper_bound(r);
            for(auto it=beg;it!=end;++it) {
                if((*it)&1) {
                    printf("%d %d\n", *it, y);
                    return;
                }
            }
        }
        set.insert(a[i]);
    }
    printf("-1\n");
    return;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        solve();
    }

    return 0;
}