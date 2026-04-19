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

const int64 M = 1000000007;

std::vector<int64> prime;

void Euler() {
    std::vector<bool> vis(50000);
    vis[0] = vis[1] = 1;
    for(int i=2;i<50000;++i) {
        if(!vis[i]) {
            prime.push_back(i);
        }
        for(int j=0;;++j) {
            int64 t = prime[j] * i;
            if(t>=50000)
                break;
            vis[t] = 1;
            if(i%prime[j] == 0)
                break;
        }
    }
}

int main() {
    Euler();
    int T;readInt(T);
    for(;T;--T) {
        int n;int64 c;readInt(n, c);
        std::vector<char> w(n+2);
        scanf("%s", w.begin() + 1);
        if(w[1]=='0' || w[n] == '0') {
            printf("-1\n");
            continue;
        }
        std::vector<int> cnt(prime.size()), ccc(prime.size());
        int64 cpc = c;
        for(int i=0;i<(int)prime.size();++i) {
            int64 x = prime[i];
            if(x * x > c)break;
            while(cpc%x==0) {
                cpc /= x;
                ++ccc[i];
            }
        }
        if(cpc > 1) {
            if(cpc>49999) {
                prime.push_back(cpc);
                ccc.push_back(1);
                cnt.push_back(0);
            } else {
                int p = std::lower_bound(prime.begin(), prime.end(), cpc) - prime.begin();
                ++ccc[p];
            }
        }
        int64 ans = 1;
        for(int i=1;i<n;++i) {
            int64 cur;
            if(w[i]=='0') {
                cur = i-1;
            } else {
                cur = 2;
            }
            ans = (ans * cur) % M;
            int64 ccur = cur;
            for(int i=0;i<(int)prime.size();++i) {
                int64 x = prime[i];
                if(x * x > cur)break;
                while(ccur%x==0) {
                    ccur /= x;
                    ++cnt[i];
                }
            }
            if(ccur > 1) {
                int p = std::lower_bound(prime.begin(), prime.end(), ccur) - prime.begin();
                if(p < (int)prime.size() && prime[p] == ccur) {
                    ++cnt[p];
                }
            }
        }
        // for(int i=0;i<(int)prime.size();++i)
        //     if(cnt[i]!=0)
        //         printf("%lld^%d ", prime[i], cnt[i]);
        // printf("\n");
        // for(int i=0;i<(int)prime.size();++i)
        //     if(ccc[i]!=0)
        //         printf("%lld^%d ", prime[i], ccc[i]);
        // printf("\n");
        bool outed = false;
        for(int i=0;i<(int)prime.size();++i) {
            if(cnt[i] < ccc[i]) {
                printf("%lld\n", ans);
                outed = true;
                break;
            }
        }
        if(!outed)
            printf("-1\n");
        if(prime.back() != 49999) {
            prime.pop_back();
        }
    }

    return 0;
}