#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
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


struct Node {
    int sum;
    Node *son[2];
    Node():sum(),son{NULL, NULL} {}
    void create(int l, int r) {
        if(l==r) {
            return;
        }
        int mid = ((l+r)>>1);
        son[0] = new Node;
        son[1] = new Node;
        son[0]->create(l, mid);
        son[1]->create(mid+1, r);
    }
    void update() {
        sum = 0;
        if(son[0]!=NULL)
            sum += son[0]->sum;
        if(son[1]!=NULL)
            sum += son[1]->sum;
    }
    Node* add(int l, int r, int p, int x) {
        if(l==r) {
            Node *cur = new Node(*this);
            ++cur->sum;
            return cur;
        }
        int mid = ((l+r)>>1);
        Node *cur = new Node(*this);
        if(p<=mid)
            cur->son[0] = son[0]->add(l, mid, p, x);
        else
            cur->son[1] = son[1]->add(mid+1, r, p, x);
        cur->update();
        return cur;
    }
    std::pair<int, std::pair<int, int> > query(int l, int r, int rk) {
        if(l==r) return {l, {rk, sum}};
        int mid = ((l+r)>>1);
        if(son[0]!=NULL&&rk < son[0]->sum)
            return son[0]->query(l, mid, rk);
        else
            return son[1]->query(mid+1, r, rk - ((son[0]==NULL)?0:son[0]->sum));
    }
};

struct Segtree {
    std::vector<Node*> nds;
    int L, R;
    Segtree(int l, int r):L(l),R(r) {
        nds.push_back(new Node);
        nds[0]->create(L, R);
    }
    void add(int p, int x) {
        Node *last_root = nds.back();
        nds.push_back(last_root->add(L, R, p, x));
    }
    std::pair<int, std::pair<int, int> > query(int version, int rk) {
        return nds[version]->query(L, R, rk);
    }
};

struct BIT {
    int *c;
    int N;
    BIT(int n):N(n) {
        c = (int*)calloc(n+1, sizeof(int));
    }
    virtual ~BIT() {
        free(c);
    }
    void add(int x, int v) {
        for(;x<=N;x+=(x&(-x)))
            c[x] += v;
    }
    int query(int x) {
        int ans = 0;
        for(;x;x-=(x&(-x)))
            ans += c[x];
        return ans;
    }
};

int main() {
    int n, q;readInt(n, q);
    std::vector<int> a(n+1);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    Segtree stree(1, n);
    std::vector<std::vector<int> > val2idx(n+1);
    for(int i=n;i>=1;--i) {
        stree.add(a[i], 1);
    }
    for(int i=1;i<=n;++i)
        val2idx[a[i]].push_back(i);
    BIT bit(n);
    for(int i=1;i<=n;++i)
        bit.add(a[i], 1);
    int samev = -1, samel = -1, samer = -1;
    for(int x=1;x<=n;++x) {
        if(bit.query(x) - bit.query(x-1)>1) {
            samev = x;
            break;
        }
    }
    for(int i=1;i<=n;++i) {
        if(a[i] == samev) {
            if(samel == -1)
                samel = i;
            else {
                samer = i;
                break;
            }
        }
    }
    std::map<int64, int> sp[2];
    int64 cnt[2] = {0, 0};
    for(int i=1;i<=n;++i) {
        bit.add(a[i], -1);
        cnt[0] += bit.query(a[i]-1);
        cnt[1] += (n-i)-bit.query(a[i]);
        if(sp[0].find(cnt[0])==sp[0].end()) {
            sp[0][cnt[0]] = i;
        }
        if(sp[1].find(cnt[1])==sp[1].end()) {
            sp[1][cnt[1]] = i;
        }
        // printf("[%d] cnt[0] = %d\n", i, cnt[0]);
        // printf("[%d] cnt[1] = %d\n", i, cnt[1]);
    }
    sp[0][0] = 0;
    sp[1][0] = 0;
    // for(auto x:sp[0]) {
    //     printf("{%d, %d}", x.first, x.second);
    // }
    // printf("\n");
    // for(auto x:sp[1]) {
    //     printf("{%d, %d}", x.first, x.second);
    // }
    // printf("\n");

    int64 tot = 1ll * n * (n - 1) / 2;
    for(;q;--q) {
        int64 rk;readInt(rk);
        if(rk-1<cnt[0]) {
            // printf("case 1\n");
            auto it = sp[0].upper_bound(rk-1);
            int l = it->second;
            printf("%d ", l);
            --it;
            auto tmp = stree.query(n-l, (rk-1) - it->first);
            printf("%d\n", *(std::upper_bound(val2idx[tmp.first].begin(), val2idx[tmp.first].end(), l)+tmp.second.second-1-tmp.second.first));
        } else if(tot - rk < cnt[1]) {
            // printf("case 2\n");
            auto it = sp[1].upper_bound(tot-rk);
            int l = it->second;
            printf("%d ", l);
            --it;
            auto tmp = stree.query(n-l, n-l-1-((tot-rk)-it->first));
            printf("%d\n", *(std::upper_bound(val2idx[tmp.first].begin(), val2idx[tmp.first].end(), l)+tmp.second.first));
        } else {
            // printf("case 3\n");
            printf("%d %d\n", samel, samer);
        }
    }
    

    return 0;
}