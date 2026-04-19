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

int64 query(int l, int r) {
    printf("? %d %d\n", l, r);
    fflush(stdout);
    int64 ans;readInt(ans);
    return ans;
}

int64 solve(int l, int r, int64 sum) {
    if(l == r) {
        return sum;
    }
    if(sum == 1) {
        return 1;
    }
    int tl = l, tr = r;
    while(tl < tr) {
        int mid = ((tl+tr)>>1);
        if(query(l, mid) >= sum / 2) {
            tr = mid;
        } else {
            tl = mid + 1;
        }
    }
    if(query(l, tl) == sum / 2) {
        if(tl - l + 1 >= r - tl)
            return solve(tl + 1, r, sum / 2);
        else 
            return solve(l, tl, sum / 2);
    } else {
        int64 len = r - l + 1;
        if((len&(-len)) == len) {
            return sum / len;
        }
        for(int t=32;t>0;--t) {
            if((len<<t)>sum && sum>(len<<(t-1)))
                return 1ll<<t;
        }
    }
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        int64 sum = query(1, n);
        int64 ans = solve(1, n, sum);
        printf("! %lld\n", ans);
        fflush(stdout);
    }

    return 0;
}