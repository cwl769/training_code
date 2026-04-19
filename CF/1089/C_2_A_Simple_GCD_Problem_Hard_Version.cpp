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

std::vector<int> prime;
const int prime_limit = 1e5;
bool prime_vis[prime_limit];

void Euler() {
    prime_vis[0] = prime_vis[1] = 1;
    for(int x=2;x<prime_limit;++x) {
        if(!prime_vis[x]) {
            prime.push_back(x);
        }
        for(auto p:prime) {
            int t = p * x;
            if(t>=prime_limit)
                break;
            prime_vis[t] = 1;
            if(x % p == 0)
                break;
        }
    }
}

void part(int x, std::vector<std::pair<int, int> >& ans) {
    int tmp = sqrt(x);
    for(auto p:prime) {
        if(p>tmp) break;
        if(x % p == 0) {
            ans.push_back({p, 0});
            while(x % p == 0) {
                ans.back().second ++;
                x /= p;
            }
        }
    }
    if(x > 1) {
        ans.push_back({x, 1});
    }
}

int get(int x, int p) {
    int ans = 0;
    while(x % p == 0) {
        ++ans;
        x /= p;
    }
    return ans;
}

int main() {
    Euler();
    int T;readInt(T);
    while(T--) {
        int n;readInt(n);
        std::vector<int> a(n+2), b(n+2);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        for(int i=1;i<=n;++i)
            readInt(b[i]);
        
        std::vector<bool> ans1(n+2);
        for(int i=1;i<=n;++i) {
            std::vector<std::pair<int, int> > prt;
            int tmp = a[i];
            // printf("[%d]tmp=%d\n", i, tmp);
            part(tmp, prt);
            for(auto pr:prt) {
                int p = pr.first;
                int t = pr.second;
                int mxextra = 0;
                if(i > 1) {
                    mxextra = std::max(mxextra, get(a[i-1], p));
                }
                if(i < n) {
                    mxextra = std::max(mxextra, get(a[i+1], p));
                }
                int delta = t - mxextra;
                for(int j=0;j<delta;++j)
                    tmp /= p;
            }
            if(tmp > b[i]) {
                //nothing
            } else {
                if(tmp < a[i]) {
                    a[i] = tmp;
                    ans1[i] = 1;
                }
            }
        }
        int cntans1 = 0;
        for(int i=1;i<=n;++i)
            if(ans1[i])
                ++cntans1;
        // for(int i=1;i<=n;++i)
        //     if(ans1[i])
        //         printf("%d ", i);
        // printf("\n");
        std::vector<int> dp[2];
        dp[0].resize(31);
        dp[1].resize(31);
        for(int t=0;t<30;++t) {
            int p = prime[t];
            if(1ll * p * a[1] <= b[1] && !ans1[1] && get(a[1], p) >= get(a[2], p))
                dp[1][t] = cntans1 + 1;
            else
                dp[1][t] = cntans1;
        }
        dp[1][30] = cntans1;
        for(int i=2;i<=n;++i) {
            vector &cur = dp[i&1];
            vector &prev = dp[(i&1)^1];
            // printf("----%d----\n", i);
            cur = prev;
            // printf("----%d----\n", i);
            for(int t=0;t<30;++t) {
                cur[30] = std::max(cur[30], prev[t]);
            }
            if(ans1[i])continue;
            for(int t=0;t<30;++t) {
                int p = prime[t];
                if(1ll * p * a[i] > b[i])
                    break;
                int get1 = get(a[i], p);
                if(get1 < get(a[i-1], p))
                    continue;
                if(i < n && get1 < get(a[i+1], p))
                    continue;
                // printf("----%d----\n", i);
                for(int lt=0;lt<30;++lt) {
                    int lp = prime[lt];
                    if(t == lt)continue;
                    cur[t] = std::max(cur[t], prev[lt] + 1);
                }
                cur[t] = std::max(cur[t], prev[30] + 1);
            }
            
        }
        int ans = 0;
        for(int t=0;t<=30;++t)
            ans = std::max(ans, dp[n&1][t]);
        printf("%d\n", ans);
    }

    return 0;
}