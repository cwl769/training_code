#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>

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
        int n;readInt(n);
        std::multiset<int64> mset;
        std::set<int64> set;
        for(int i=0;i<n;++i) {
            int64 x;readInt(x);
            mset.insert(x);
            set.insert(x);
        }
        int64 ans = 0;
        int all_cnt = 0;
        for(auto x:set) {
            int64 cnt = mset.count(x);
            ans += (cnt / 2ll) * x;
            all_cnt += (cnt / 2ll) * 2ll;
            mset.erase(x);
            if(cnt&1)
                mset.insert(x);
        }
        ans <<= 1;
        // printf("sub %lld\n", ans);
        // for(auto x:mset) {
        //     printf("%lld ", x);
        // }
        // printf("\n");
        int64 chs = 0, chs_cnt = 0;
        if(mset.size() >= 2) {
            for(auto t=mset.rbegin();t!=mset.rend();++t) {
                ++t;
                if(t==mset.rend())
                    break;
                int64 nxt = *t;
                --t;
                if(*t - nxt < ans) {
                    chs = *t + nxt;
                    chs_cnt = 2;
                    break;
                }
            }
        }

        // printf("%lld %lld\n", chs, chs_cnt);

        auto it = mset.lower_bound(ans);
        mset.erase(it, mset.end());
        if(mset.size()) {
            if(*mset.rbegin() > chs) {
                chs = *mset.rbegin();
                chs_cnt = 1;
            }
        }

        // printf("%lld %lld\n", chs, chs_cnt);

        ans += chs;
        all_cnt += chs_cnt;

        if(all_cnt >= 3)
            printf("%lld\n", ans);
        else
            printf("0\n");
    }

    return 0;
}