#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

struct Range {
    i64 l, r;
};

bool cmp(const Range& a, const Range& b) {
    return a.l < b.l;
}

i64 getcnt(const std::set<std::pair<i64, i64> >& setrg, i64 ql, i64 qr) {
    auto itl = setrg.lower_bound({ql, 0});
    if(itl != setrg.begin())
        --itl;
    i64 ans = 0;
    for(auto it = itl; it != setrg.end(); ++it) {
        i64 l = it->first;
        i64 r = it->second;
        if(l > qr)
            break;
        l = std::max(l, ql);
        r = std::min(r, qr);
        if(l <= r)
            ans += r - l + 1;
    }
    return ans;
}

int main() {
    i64 n;int m;scanf("%lld%d", &n, &m);
    std::vector<Range> range(m);
    for (int i = 0; i < m; ++i)
        scanf("%lld%lld", &range[i].l, &range[i].r);
        
    if(n == 1) {
        if(m) {
            printf("1\n");
        } else {
            printf("0\n");
        }
        return 0;
    }
    
    std::set<std::pair<i64, i64> > setrg;
    std::sort(range.begin(), range.end(), cmp);
    i64 curl = LLONG_MIN, curr = LLONG_MIN;
    for (auto rg : range) {
        i64 l = rg.l;
        i64 r = rg.r;
        if(l - 1 > curr) {
            if(curl != LLONG_MIN) {
                setrg.insert({curl, curr});
            }
            curl = l;
            curr = r;
        } else {
            curr = std::max(curr, r);
        }
    }
    setrg.insert({curl, curr});
    
    std::map<i64, i64> set;
    //(val, cnt)
    
    for(i64 l = 1, r; l <= n; l = r + 1) {
        r = (n / (n / l));
        i64 val = (n) / l;
        i64 cnt = getcnt(setrg, l, r);
        if(cnt)set.insert({val, cnt});
        // printf("add %lld %lld\n", val, cnt);
    }
    
    i64 ans = 0;
    while(set.size() && (set.size() >= 2 || set.begin()->second > 1)) {
        i64 val = set.begin()->first;
        i64 cnt = set.begin()->second;
        set.erase(set.begin());
        if(cnt == 0) {
            continue;
        } else if(cnt == 1) {
            i64 val2 = set.begin()->first;
            i64 cnt2 = set.begin()->second;
            set.erase(set.begin());
            if(cnt2 > 1)set.insert({val2, cnt2 - 1});
            ans += val + val2;
            // set.insert({val + val2, 1});
            set[val + val2] += 1;
        } else if(cnt & 1) {
            ans += val * (cnt - 1);
            // set.insert({val, 1});
            // set.insert({val * 2, cnt / 2});
            set[val] += 1;
            set[val * 2] += cnt / 2;
        } else {
            ans += val * cnt;
            // set.insert({val * 2, cnt / 2});
            set[val * 2] += cnt / 2;
        }
        // printf("%lld %lld ans:%lld\n", val, cnt, ans);
        // for(auto [val, cnt] : set) {
        //     printf("{%lld, %lld} ", val, cnt);
        // }
        // printf("\n");
    }
    printf("%lld\n", ans);
    
    return 0;
}