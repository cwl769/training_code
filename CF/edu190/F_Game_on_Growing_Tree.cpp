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

typedef std::vector<veci> Graph;

int dp[200010], dprt[200010];

veci g[200010];

void dfs1(int x, int faa) {
    dp[x] = 1;
    
    int mx = 0, sndmx = 0, thrmx = 0;
    // std::vector<int> sonv;
    for(auto y:g[x]) {
        if(y == faa)
            continue;
        dfs1(y, x);
        // sonv.push_back(dp[y]);

        if(dp[y] > mx) {
            thrmx = sndmx;
            sndmx = mx;
            mx = dp[y];
        } else if(dp[y] > sndmx) {
            thrmx = sndmx;
            sndmx = dp[y];
        } else if(dp[y] > thrmx) {
            thrmx = dp[y];
        }
    }
    // for(auto x:sonv) {
    //     if(x > mx) {
    //         thrmx = sndmx;
    //         sndmx = mx;
    //         mx = x;
    //     } else if(x > sndmx) {
    //         thrmx = sndmx;
    //         sndmx = x;
    //     } else if(x > thrmx) {
    //         thrmx = x;
    //     }
    // }
    dp[x] += sndmx;
}

void dfs2(int x, int faa, int dpfa) {
    dprt[x] = 1;

    int mx = 0, sndmx = 0, thrmx = 0;
    // std::vector<int> sonv;
    for(auto y:g[x]) {
        if(y == faa)
            continue;
        // sonv.push_back(dp[y]);

        if(dp[y] > mx) {
            thrmx = sndmx;
            sndmx = mx;
            mx = dp[y];
        } else if(dp[y] > sndmx) {
            thrmx = sndmx;
            sndmx = dp[y];
        } else if(dp[y] > thrmx) {
            thrmx = dp[y];
        }
    }
    if(faa){
        // sonv.push_back(dpfa);
        if(dpfa > mx) {
            thrmx = sndmx;
            sndmx = mx;
            mx = dpfa;
        } else if(dpfa > sndmx) {
            thrmx = sndmx;
            sndmx = dpfa;
        } else if(dpfa > thrmx) {
            thrmx = dpfa;
        }
    }
    // for(auto val:sonv) {
    //     if(val > mx) {
    //         thrmx = sndmx;
    //         sndmx = mx;
    //         mx = val;
    //     } else if(val > sndmx) {
    //         thrmx = sndmx;
    //         sndmx = val;
    //     } else if(val > thrmx) {
    //         thrmx = val;
    //     }
    // }
    dprt[x] += sndmx;
    

    for(auto y:g[x]) {
        if(y == faa)
            continue;
        if(dp[y] == mx || dp[y] == sndmx) {
            dfs2(y, x, 1+thrmx);
        } else {
            dfs2(y, x, 1+sndmx);
        }
    }
}

int save[200010];

int check(int n) {
    if(save[n])
        return save[n];
    dfs1(1, 0);
    dfs2(1, 0, 0);
    int ans = 0;
    for(int i=1;i<=n;++i)
        ans = std::max(ans, dprt[i]);
    return save[n] = ans;
}

int v[200010];

int binary_search(int l, int r, int val) {
    // printf("binary_search(%d, %d, %d)\n", l, r, val);
    while(l < r) {
        int n = ((l+r)>>1);
        for(int i=1;i<=n;++i) {
            g[i].clear();
        }
        for(int i=2;i<=n;++i) {
            g[i].push_back(v[i]);
            g[v[i]].push_back(i);
        }
        if(check(n) >= val) {
            r = n;
        } else {
            l = n + 1;
        }
    }
    // printf("binary_search(%d, %d, %d) = %d\n", l, r, val, l);
    return l;
}

void solve() {
    int q;readInt(q);
    for(int i=2;i<=q+1;++i)
        readInt(v[i]);
    veci ansv(q+3);
    for(int x=2,l=2,r=q+2;;) {
        int fst = binary_search(l, r, x);
        if(fst > q+1)
            break;
        ansv[fst] += save[fst] - x + 1;
        x = save[fst] + 1;
        l = fst;
    }
    int ans = 1;
    for(int i=2;i<=q+1;++i) {
        ans += ansv[i];
        printf("%d ", ans);
    }
    printf("\n");
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}