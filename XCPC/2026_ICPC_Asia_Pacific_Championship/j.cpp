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

typedef std::vector<int> vector;

void del(int x, int y, int64 &ans, const int n, const vector& pb) {
    if(x > y) std::swap(x, y);
    ans -= pb[x] - pb[x-1] + ((pb[x-1] < pb[x])?0:n);
    ans -= pb[y] - pb[y-1] + ((pb[y-1] < pb[y])?0:n);
    if(x+1!=y) {
        ans -= pb[x+1] - pb[x] + ((pb[x] < pb[x+1])?0:n);
    }
    if(y!=n) {
        ans -= pb[y+1] - pb[y] + ((pb[y] < pb[y+1])?0:n);
    }
}

void add(int x, int y, int64 &ans, const int n, const vector& pb) {
    if(x > y) std::swap(x, y);
    ans += pb[x] - pb[x-1] + ((pb[x-1] < pb[x])?0:n);
    ans += pb[y] - pb[y-1] + ((pb[y-1] < pb[y])?0:n);
    if(x+1!=y) {
        ans += pb[x+1] - pb[x] + ((pb[x] < pb[x+1])?0:n);
    }
    if(y!=n) {
        ans += pb[y+1] - pb[y] + ((pb[y] < pb[y+1])?0:n);
    }
}

int main() {
    int n, d;readInt(n, d);
    std::vector<int> a(n+1), b(n+1);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    for(int i=1;i<=n;++i)
        readInt(b[i]);
    std::vector<int> p(n+1);
    for(int i=1;i<=n;++i) {
        p[a[i]] = i;
    }
    std::vector<int> pb(n+1), pb_inv(n+1);
    for(int i=1;i<=n;++i)
        pb[i] = p[b[i]];
    for(int i=1;i<=n;++i)
        pb_inv[pb[i]] = i;
    int64 ans = 0;
    for(int i=1;i<=n;++i) {
        // if(pb[i-1] < pb[i]) {
        //     ans += pb[i] - pb[i-1];
        // } else {
        //     ans += pb[i] - pb[i-1] + n;
        // }
        ans += pb[i] - pb[i-1] + ((pb[i-1] < pb[i])?0:n);
    }
    // for(int i=1;i<=n;++i)
    //     printf("%d ", pb[i]);
    // printf("\n");
    // for(int i=1;i<=n;++i)
    //     printf("%d ", pb_inv[i]);
    // printf("\n");
    printf("%lld\n", ans - n);
    for(int i=2;i<=d;++i) {
        int c, x, y;readInt(c, x, y);
        if(c == 1) {
            del(pb_inv[x], pb_inv[y], ans, n, pb);
            pb[pb_inv[x]] = y;
            pb[pb_inv[y]] = x;
            std::swap(pb_inv[x], pb_inv[y]);
            add(pb_inv[x], pb_inv[y], ans, n, pb);
        } else {
            del(x, y, ans, n, pb);
            pb_inv[pb[x]] = y;
            pb_inv[pb[y]] = x;
            std::swap(pb[x], pb[y]);
            add(x, y, ans, n, pb);
        }
        // for(int i=1;i<=n;++i)
        //     printf("%d ", pb[i]);
        // printf("\n");
        // for(int i=1;i<=n;++i)
        //     printf("%d ", pb_inv[i]);
        // printf("\n");
        printf("%lld\n", ans - n);
    }

    return 0;
}