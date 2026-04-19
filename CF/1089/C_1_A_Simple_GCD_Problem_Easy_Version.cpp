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
        std::vector<int> a(n+2);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        
        int ans = 0;
        for(int i=1;i<=n;++i) {
            std::vector<std::pair<int, int> > prt;
            part(a[i], prt);
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
                if(mxextra < t) {
                    ++ans;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}