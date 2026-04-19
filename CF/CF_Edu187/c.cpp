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

bool check(int64 x, const std::map<int, int64, std::greater<int> >& ps) {
    int64 rest = 0;
    int last = -1;
    for(auto pr:ps) {
        int64 need = pr.second;
        if(rest) {
            need += (rest << (last - pr.first));
        }
        if(need > x) {
            rest = need - x;
        } else {
            rest = 0;
        }

        last = pr.first;
    }
    if(rest)return false;
    return true;
}

int main() {
    int T;readInt(T);
    while(T--) {
        int64 s, m;readInt(s, m);
        std::map<int, int64, std::greater<int> > ps;
        for(int i=0;m;m>>=1,++i) {
            if(m&1)
                ps.insert({i, 0});
        }
        int64 ans = 0;
        for(int i=0;s;s>>=1,++i) {
            if(s&1) {
                auto it = ps.lower_bound(i);
                if(it == ps.end()){
                    ans = -1;
                    break;
                } else {
                    it->second += (1ll<<(i - it->first));
                }
            }
        }
        if(ans == -1)
            printf("-1\n");
        else {
            int64 l = 1, r = 1e18;
            for(;l<r;) {
                int64 mid = ((l+r)>>1ll);
                if(check(mid, ps))
                    r = mid;
                else
                    l = mid + 1;
            }
            printf("%lld\n", l);
        }
    }

    return 0;
}