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

int log2(int64 x) {
    int ans = 0;
    for(int t=32;t>=1;t>>=1) {
        if((1ll << (ans + t)) <= x)
            ans += t;
    }
    return ans;
}

int64 lowbit(int64 x) {
    return x&(-x);
}

bool check(const std::vector<int64>& vec) {
    int n = vec.size();
    int64 cnt = 0;
    for(int i=0;i<n-1;++i) {
        int64 sum = vec[i] + vec[i+1];
        if(lowbit(sum)!=sum)return false;
        cnt += log2(sum);
    }
    int64 sum = vec[n-1] + vec[0];
    if(lowbit(sum)!=sum)return false;
    cnt += log2(sum);
    return true;
}

int64 gcd(int64 a, int64 b) {
    if(b==0)return a;
    return gcd(b, a%b);
}

int main() {
    int p = 129;
    for(int n=1;n<=5;n+=2) {
        std::vector<int64> vec(n, 1);
        while(vec.back() <= p) {
            bool ans = check(vec);
            if(ans) {
                int64 g = 0;
                for(int i=0;i<n;++i)
                    g = gcd(g, vec[i]);
                if(g==1) {
                    for(auto x:vec)
                        printf("%lld ", x);
                    printf("\n");
                    fflush(stdout);

                }
            }
            ++vec[0];
            for(int i=0;i<n&&vec[i]>p;++i) {
                if(i!=n-1) {
                    vec[i] = 1;
                    ++vec[i+1];
                }
            }
        }
    }

    return 0;
}