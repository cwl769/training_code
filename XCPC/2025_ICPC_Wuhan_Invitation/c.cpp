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

int main() {
    int T;readInt(T);
    while(T--) {
        int n, m;readInt(n, m);
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        std::map<int, int> rr, rl, ll;
        for(int i=1;i<=n;++i) {
            // printf("{%d, %d}\n", i, a[i]);
            int p = (i + a[i]) % (n * 2 - 1);
            if(i <= p && p <= n * 2 - 1 - i) {
                int q = ((2 * n - i) + a[i]) % (n * 2 - 1);
                if(i <= q && q <= n * 2 - 1 - i) {
                    // printf("case 1\n");
                    ll[a[i] / (n * 2 - 1)] += 1;
                } else {
                    // printf("case 2\n");
                    rl[a[i] / (n * 2 - 1)] += 1;
                }
            } else {
                    // printf("case 3\n");
                rr[a[i] / (n * 2 - 1)] += 1;
            }
        }
        std::vector<int> ans(m);
        // printf("rr\n");
        for(auto pr:rr) {
            int d = pr.first + 1;
            int v = pr.second;
            // printf("%d %d\n", d, v);
            for(int i=0;i<m;i+=d)
                ans[i] += v;
        }
        // printf("ll\n");
        for(auto pr:ll) {
            int d = pr.first + 1;
            int v = pr.second;
            // printf("%d %d\n", d, v);
            ans[0] += v;
            for(int i=d-1;i<m;i+=d) {
                ans[i] += v;
            }
        }
        // printf("rl\n");
        for(auto pr:rl) {
            int d = pr.first + pr.first + 1;
            int td = pr.first;
            int v = pr.second;
            // printf("%d %d\n", d, v);
            for(int i=0;i<m;i+=d) {
                ans[i] += v;
                if(i + td < m)
                    ans[i + td] += v;
            }
        }
        for(auto v:ans)
            printf("%d ", v);
        printf("\n");
    }

    return 0;
}