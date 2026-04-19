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
        int n, m;readInt(n, m);
        std::vector<std::pair<int64, int> > a(n);
        for(int i=0;i<n;++i)
            readInt(a[i].first);
        for(int i=0;i<n;++i)
            a[i].second = i + 1;
        std::sort(a.begin(), a.end());
        if(m > n / 2) {
            printf("-1\n");
            continue;
        }
        if(m == 0) {
            int64 s = 0;
            for(int i=0;i<n-1;++i)
                s += a[i].first;
            if(s<a[n-1].first) {
                printf("-1\n");
                continue;
            }
            s = 0;
            int t = n-3;
            for(;t>=0;--t) {
                s += a[t].first;
                if(a[n-1].first - s <= a[n-2].first)break;
            }
            printf("%d\n", n-1);
            for(int i=0;i<t-1;++i)
                printf("%d %d\n", a[i].second, a[i+1].second);
            if(t>0)
                printf("%d %d\n", a[t-1].second, a[n-2].second);
            for(int i=t;i<=n-2;++i)
                printf("%d %d\n", a[i].second, a[n-1].second);
            continue;
        }
        printf("%d\n", n-m*2 + m);
        for(int i=0;i<n-m*2;++i) {
            printf("%d %d\n", a[i].second, a[i+1].second);
        }
        for(int i=1;i<=m;++i) {
            printf("%d %d\n", a[n-i].second, a[n-i-m].second);
        }
    }

    return 0;
}