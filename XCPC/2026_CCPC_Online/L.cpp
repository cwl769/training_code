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

struct Segtree {
    struct Node {
        i64 sum;
        i64 tag;
        Node *son[2];
        Node():sum(), tag(), son{NULL, NULL}{}
        void pushup() {
            sum = 0;
            if(son[0] != NULL)
                sum += son[0]->sum;
            if(son[1] != NULL)
                sum += son[1]->sum;
        }
        void pushdown(int l, int r) {
            int mid = ((l + r) >> 1);
            if(son[0] == NULL)  son[0] = new Node;
            if(son[1] == NULL)  son[1] = new Node;
            if(tag == 0) return;
            son[0]->sum += tag * (mid - l + 1ll);
            son[1]->sum += tag * (r - mid);
            son[0]->tag += tag;
            son[1]->tag += tag;
            tag = 0;
        }
        void add(int l, int r, i64 ql, i64 qr, i64 val) {
            if(ql <= l && r <= qr) {
                sum += val * (r - l + 1ll);
                tag += val;
                return;
            }
            pushdown(l, r);
            int mid = ((l + r) >> 1);
            if(ql <= mid)
                son[0]->add(l, mid, ql, qr, val);
            if(qr > mid)
                son[1]->add(mid + 1, r, ql, qr, val);
            pushup();
        }
        i64 query(int l, int r, i64 ql, i64 qr) {
            if(ql <= l && r <= qr)
                return sum;
            pushdown(l, r);
            int mid = ((l + r) >> 1);
            i64 ans = 0;
            if(ql <= mid)
                ans += son[0]->query(l, mid, ql, qr);
            if(qr > mid)
                ans += son[1]->query(mid + 1, r, ql, qr);
            pushup();
            return ans;
        }
    };

    Node *root;
    i64 L, R;
    Segtree(int l, int r) {
        root = new Node;
        L = l; R = r;
    }
    void add(int l, int r, i64 val) {
        root->add(L, R, l, r, val);
    }
    i64 sum(int l, int r) {
        return root->query(L, R, l, r);
    }
};

struct Range {
    i64 l, r;
};

bool cmp(const Range& a, const Range& b) {
    return a.l < b.l;
}

/*
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
*/

int main() {
    i64 n;int m;scanf("%lld%d", &n, &m);
    std::vector<Range> range(m);
    for (int i = 0; i < m; ++i)
        scanf("%lld%lld", &range[i].l, &range[i].r);
        
    if(n == 1) {
        printf("%d\n", m);
        return 0;
    }
    
    /*
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
    */
    
    //discrete
    std::map<i64, i64> sp;
    sp[1] = 0;sp[n + 1] = 0;
    std::vector<std::pair<i64, i64> > mulvec;
    for(i64 l = 1, r; l <= n; l = r + 1) {
        r = (n / (n / l));
        i64 val = (n) / l;
        sp[l] = 0;
        sp[r + 1] = 0;
        mulvec.emplace_back(l, val);
    }
    for (auto [l, r] : range) {
        sp[l] = 0;
        sp[r + 1] = 0;
    }

    veci64 seq(1);
    int id_tot = 0;
    for (auto &[x, id] : sp){
        id = ++id_tot;
        seq.emplace_back(x);
    }

    std::map<i64, i64> set;
    //(val, cnt)
    //val is the number of logs, 
    //cnt is the number of programs whose logs is exactly cnt
    
    Segtree tree(1, id_tot);
    for (auto [l, r] : range) {
        l = sp[l];
        r = sp[r + 1] - 1;
        tree.add(l, r, 1);
    }

    auto mulit = mulvec.begin();
    i64 mul = 0;
    for (int id = 1; id < id_tot; ++id) {
        while(mulit != mulvec.end() && mulit->first <= seq[id]) {
            mul = mulit->second;
            ++mulit;
        }
        i64 val = mul * tree.sum(id, id);
        i64 cnt = seq[id + 1] - seq[id];
        set[val] += cnt;
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