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

int insert(i64 x) {
    printf("I %lld\n", x);
    fflush(stdout);
    int ans;
    readInt(ans);
    return ans;
}

int query(i64 y) {
    printf("Q %lld\n", y);
    fflush(stdout);
    int ans;
    readInt(ans);
    return ans;
}

void answer(int k, i64 c) {
    printf("A %d %lld\n", k, c);
    fflush(stdout);
}

void solve() {
    int n;readInt(n);
    printf("0\n");
    fflush(stdout);
    
    int k = 0; i64 c = 0;
    i64 cov = (1ll<<n) - 1ll;
    int siz1 = insert(0);
    if(siz1 == 1) {
        k = 1;
        int last = siz1;
        for(int i=0;i<n;++i) {
            int cur = insert(1ll<<i);
            if(cur!=last) {
                c |= (1ll<<i);
            }
            last = cur;
        }
        answer(k, c);
    } else {
        i64 l = 1, r = cov+1;
        while(l < r) {
            i64 mid = ((l+r)>>1);
            if(query(mid)==0)
                r = mid;
            else
                l = mid + 1;
        }
        c = l - 1;
        if(c!=cov){
            int s2 = insert(cov);
            int tmp = query(cov);
            if(tmp)
                k = 2;
            else
                k = 3;
        } else {
            int s2 = insert(1);
            if(s2 == 3)
                k = 3;
            else
                k = 2;
        }
        answer(k, c);
    }
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}