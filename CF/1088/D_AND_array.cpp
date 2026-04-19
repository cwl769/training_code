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

const int64 MOD = 1000000007;
const int64 inv_p = MOD - 2;

int64 qpow(int64 a, int64 b) {
    int64 ans = 1;
    for(;b;b>>=1) {
        if(b&1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
    }
    return ans;
}

int64 jc[100010];
int64 jc_inv[100010];

void init() {
    jc[0] = jc[1] = 1;
    for(int i=2;i<100010;++i)
        jc[i] = jc[i-1] * i % MOD;
    jc_inv[0] = jc_inv[1] = 1;
    for(int i=2;i<100010;++i)
        jc_inv[i] = jc_inv[i-1] * qpow(i, inv_p) % MOD;
}

int64 C(int n, int m) {
    return (jc[n] * jc_inv[m] % MOD) * jc_inv[n-m] % MOD;
}

int main() {
    init();
    int T;readInt(T);
    while(T--) {
        int n;readInt(n);
        std::vector<int64> b(n+1);
        for(int i=1;i<=n;++i)
            readInt(b[i]);
        std::vector<std::pair<int, int> > tct;
        for(int k=n;k>=1;--k) {
            for(auto pr:tct) {
                int t = pr.first;
                int ct = pr.second;
                int64 cur = (C(ct, k) << t) % MOD;
                b[k] = ((b[k] - cur) % MOD + MOD) % MOD;
            }
            for(int t=0;t<=28;++t) {
                if((1<<t)&b[k]) {
                    tct.push_back({t, k});
                }
            }
        }
        std::vector<int> a(n+1);
        for(auto pr:tct) {
            int t = pr.first;
            int ct = pr.second;
            for(int i=1;i<=ct;++i)
                a[i] |= (1<<t);
        }
        for(int i=1;i<=n;++i)
            printf("%d ", a[i]);
        printf("\n");
    }

    return 0;
}