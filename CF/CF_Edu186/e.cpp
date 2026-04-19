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

struct Friend {
    int64 x, z;
};

bool operator < (const Friend& a, const Friend& b) {
    return a.x < b.x;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int64 n, m, k;readInt(n, m, k);
        std::vector<int64> box(m);
        for(int i=0;i<m;++i)
            readInt(box[i]);
        std::vector<Friend> fr;
        for(int i=1;i<=n;++i){
            int64 x, y, z;
            readInt(x, y, z);
            k -= y;
            fr.push_back((Friend){.x = x, .z = z - y});
        }
        std::sort(box.begin(), box.end());
        std::sort(fr.begin(), fr.end());
        auto itfr = fr.begin();
        std::multiset<std::pair<int64, Friend> > set;
        int64 ans = 0;
        for(auto it_box=box.begin();it_box != box.end();++it_box) {
            int64 a = *it_box;
            while(itfr != fr.end() && itfr->x <= a) {
                set.insert({itfr->z, *itfr});
                ++itfr;
            }
            if(set.size()) {
                set.erase(set.find(*set.rbegin()));
                ++ans;
            }
        }
        while(itfr != fr.end()) {
            set.insert({itfr->z, *itfr});
            ++itfr;
        }
        for(auto x:set) {
            if(k - x.first >= 0) {
                k -= x.first;
                ++ans;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}