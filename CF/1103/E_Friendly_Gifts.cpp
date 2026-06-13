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

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

#define debug(...) fprintf(stderr, __VA_ARGS__)

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
    int len;
    int mn, mx;
};

bool operator < (Data a, Data b) {
    return a.len < b.len;
}

std::vector<Data> quev[6010];
bool mnt[6010][6010], mxt[6010][6010];
bool setb[6010];

void solve() {
    int n;readInt(n);
    veci a(n+2);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    int ans = 0;
    // std::vector<std::vector<Data> > quev(n+2);
    for(int i=0;i<=n+1;++i)
        quev[i].clear();
    // std::vector<std::vector<bool> > mnt(n+2), mxt(n+2);
    for(int i=1;i<=n;++i) {
        // mnt[i].resize(n+2, 0);
        // mxt[i].resize(n+2, 0);
        for(int j=0;j<=n+1;++j)
            mnt[i][j] = 0;
        for(int j=0;j<=n+1;++j)
            mxt[i][j] = 0;
    }
    for(int l=1;l<=n;++l) {
        for(auto data:quev[l-1]) {
            mnt[data.len][data.mn] = 1;
            mxt[data.len][data.mx] = 1;
        }
        // std::set<int> set;
        for(int i=1;i<=n;++i) {
            setb[i] = 0;
        }
        int min = INT_MAX;
        int max = INT_MIN;
        for(int r=l;r<=n;++r) {
            if(setb[a[r]]) {
                break;
            }
            setb[a[r]] = 1;
            min = std::min(min, a[r]);
            max = std::max(max, a[r]);
            if(r - l == max - min) {
                quev[r].emplace_back((Data){
                    .len = r - l + 1,
                    .mn = min,
                    .mx = max
                });
                int len = r - l + 1;
                if(mnt[len][max+1]) {
                    ans = std::max(ans, len);
                }
                if(mxt[len][min-1]) {
                    ans = std::max(ans, len);
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}