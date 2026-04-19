#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

typedef long long int64;
typedef std::vector<int> vector;

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

struct Data {
    int val;
    int l, r;
};

int main() {
    int T;readInt(T);
    while(T--) {
        int n, k;readInt(n, k);
        std::vector<int> a(n+2);
        for(int i=1;i<=n;++i) {
            readInt(a[i]);
        }
        vector p(k+2);
        p[0] = 0;
        p[k+1] = n + 1;
        for(int i=1;i<=k;++i)
            readInt(p[i]);
        int col = a[p[1]];
        a[0] = col;
        a[n+1] = col;
        vector b(n+1);
        for(int i=0;i<=n;++i)
            if(a[i] != a[i+1])
                b[i] = 1;
        int sum = 0;
        for(int i=0;i<=n;++i)
            sum += b[i];
        int mx = 0;
        for(int t=0;t<=k;++t) {
            int l = p[t];
            int r = p[t+1] - 1;
            int cnt = 0;
            for(int i=l;i<=r;++i) {
                cnt += b[i];
            }
            mx = std::max(mx, cnt);
        }
        if(mx > sum / 2) {
            printf("%d\n", mx);
        } else {
            printf("%d\n", sum / 2);
        }
    }

    return 0;
}