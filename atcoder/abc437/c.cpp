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

struct Deer {
    int64 w, p;
};

bool cmp(const Deer& a, const Deer& b) {
    return a.p + a.w < b.p + b.w;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<Deer> d(n);
        for(int i=0;i<n;++i) {
            readInt(d[i].w, d[i].p);
        }
        std::sort(d.begin(), d.end(), cmp);
        std::vector<int64> sum(n);
        sum[0] = d[0].w;
        for(int i=1;i<n;++i) 
            sum[i] = sum[i-1] + d[i].w;
        int i=n-1;
        int64 sp = 0;
        for(;i>=0;--i) {
            if(sp >= sum[i])break;
            sp += d[i].p;
        }
        printf("%d\n", i+1);
    }

    return 0;
}