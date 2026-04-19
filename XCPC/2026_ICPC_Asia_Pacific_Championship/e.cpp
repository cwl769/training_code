#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
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

struct Query {
    int id;
    int l, r;
};

void add(int x, int64& pos, int64& sum, const std::vector<int64>& d) {
    sum -= pos;
    pos = std::max(pos, d[x]);
    sum += pos;
}
/**
 * calculate ceil(a / b)
 * it's guaranteed that b > 0
 */
int64 ceil(int64 a, int64 b) {
    if(a > 0) {
        return (a - 1) / b + 1;
    } else {
        return a / b;
    }
}

int main() {
    int n;int64 m;readInt(n, m);
    std::vector<int64> s(n-m+1);
    for(int i=0;i<=n-m;++i) {
        readInt(s[i]);
    }
    std::vector<int64> d(n);
    for(int i=0;i<m;++i) {
        d[i] = 0;
    }
    for(int i=m;i<n;++i) {
        d[i] = s[i-m+1] - s[i-m] + d[i-m];
    }
    int Q;readInt(Q);
    std::vector<Query> q;
    for(int i=0;i<Q;++i) {
        int l, r;readInt(l, r);
        if(r - l + 1 >= m) {
            q.push_back((Query){
                .id = i,
                .l = l - 1,
                .r = r - 1
            });
        }
    }
    int len = sqrt(n);
    std::sort(q.begin(), q.end(), [len](Query a, Query b)->bool {
        if(a.l / len == b.l / len) {
            return a.r < b.r;
        }
        return a.l / len < b.l / len;
    });
    int l = 0, r = 0;
    std::vector<int64> ans(Q, LLONG_MIN);
    std::vector<int64> mx(m, -2e14);
    int64 sum = ((int64)-2e14) * m;
    for(int i=0;i<(int)q.size();++i) {
        if(i == 0 || q[i].l / len != q[i-1].l / len) {
            l = q[i].l / len * len + len;
            r = l - 1;
            mx.clear();
            mx.resize(m, -2e14);
            sum = ((int64)-2e14) * m;
        }
        if(q[i].l / len == q[i].r / len) {
            std::vector<int64> mx(m, -2e14);
            for(int x=q[i].l;x<=q[i].r;++x) {
                int t = x % m;
                mx[t] = std::max(mx[t], d[x]);
            }
            int64 sum = 0;
            for(int i=0;i<m;++i)
                sum += mx[i];
            ans[q[i].id] = ceil(sum + s[0], m);
            continue;
        }
        while(r<q[i].r) {
            ++r;
            add(r, mx[r%m], sum, d);
        }
        int64 sumbk = sum;
        std::vector<std::pair<int, int64> > op;
        while(l>q[i].l) {
            --l;
            int t = l % m;
            op.push_back({t, mx[t]});
            add(l, mx[t], sum, d);
        }
        ans[q[i].id] = ceil(sum + s[0], m);
        for(auto it = op.rbegin(); it != op.rend(); ++it) {
            mx[it->first] = it->second;
        }
        l = q[i].l / len * len + len;
        sum = sumbk;
    }
    for(int i=0;i<Q;++i) {
        if(ans[i] == LLONG_MIN)
            printf("unbounded\n");
        else
            printf("%lld\n", ans[i]);
    }

    return 0;
}