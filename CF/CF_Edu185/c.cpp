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

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int64 n, k;readInt(n, k);
        std::vector<int64> r(n);
        std::multiset<int64> q;
        for(int i=0;i<n;++i) {
            int64 x;readInt(x);
            q.insert(x);
        }
        for(int i=0;i<n;++i) {
            readInt(r[i]);
        }
        std::sort(r.begin(), r.end(), std::greater<int64>() );
        int ans = 0;
        for(auto rj:r) {
            int64 lim = (k - rj) / (rj+1);
            auto it = q.upper_bound(lim);
            if(it!=q.begin()) {
                ++ans;
                --it;
                q.erase(it);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}