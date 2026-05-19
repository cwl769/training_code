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

const int inf = 0x3f3f3f3f;

struct Pos {
    int x[2];
};

struct kdtree {
    struct Node {
        int val, mn, cut;
        int l[2], r[2];
        Pos pos;
        Node *son[2];
        Node():val(inf),mn(inf),cut(),l{0,0},r{0,0},pos{0,0},son{NULL,NULL}{}
        int query(int xl, int xr, int yl, int yr) {
            if(xl<=l[0]&&r[0]<=xr && yl<=l[1]&&r[1]<=yr)
                return this->mn;
            int ans = inf;
            if(xl<=pos.x[0]&&pos.x[0]<=xr && yl<=pos.x[1]&&pos.x[1]<=yr)
                ans = std::min(ans, this->val);
            if(cut == 0) {
                if(xl<=pos.x[0] && son[0]) {
                    ans = std::min(ans, son[0]->query(xl, xr, yl, yr));
                }
                if(xr>=pos.x[0] && son[1]) {
                    ans = std::min(ans, son[1]->query(xl, xr, yl, yr));
                }
            } else {
                if(yl<=pos.x[1] && son[0]) {
                    ans = std::min(ans, son[0]->query(xl, xr, yl, yr));
                }
                if(yr>=pos.x[1] && son[1]) {
                    ans = std::min(ans, son[1]->query(xl, xr, yl, yr));
                }
            }
            return ans;
        }
        void print() {
            printf("-------[%p]-------\n", this);
            printf("mn = %d\n", mn);
            printf("cur = %d\n", cut);
            printf("[%d, %d] [%d, %d]\n", l[0], r[0], l[1], r[1]);
            printf("{%d, %d}\n", pos.x[0], pos.x[1]);
            printf("(%16p) (%16p)\n", son[0], son[1]);
            printf("--------------\n");
            if(son[0])
                son[0]->print();
            if(son[1])
                son[1]->print();
        }
    };
    std::vector< std::pair<Pos, int> > pos;
    Node *root;
    kdtree():pos(),root(NULL) {}
    void change(int x, int y, int v) {
        pos.push_back({(Pos){x, y}, v});
    }
    typedef std::vector<std::pair<Pos, int> >::iterator itr;
    typedef std::pair<Pos, int> pr_t;
    Node* maketree(itr a, itr b, int sort_on = 0) {
        if(a == b)
            return NULL;
        int len = b - a;
        itr mid = a + (len-1)/2;
        std::nth_element(a, mid, b, [sort_on](pr_t a, pr_t b)->bool {
            return a.first.x[sort_on] < b.first.x[sort_on];
        });
        Node *cur = new Node;
        cur->val = cur->mn = mid->second;
        cur->cut = sort_on;
        cur->pos = mid->first;
        cur->l[0] = cur->r[0] = cur->pos.x[0];
        cur->l[1] = cur->r[1] = cur->pos.x[1];
        if(b-a==1){
            return cur;
        }
        cur->son[0] = maketree(a, mid, sort_on^1);
        cur->son[1] = maketree(mid+1, b, sort_on^1);
        if(cur->son[0]) {
            cur->mn = std::min(cur->mn, cur->son[0]->mn);
            cur->l[0] = std::min(cur->l[0], cur->son[0]->l[0]);
            cur->l[1] = std::min(cur->l[1], cur->son[0]->l[1]);
            cur->r[0] = std::max(cur->r[0], cur->son[0]->r[0]);
            cur->r[1] = std::max(cur->r[1], cur->son[0]->r[1]);
        }
        if(cur->son[1]) {
            cur->mn = std::min(cur->mn, cur->son[1]->mn);
            cur->l[0] = std::min(cur->l[0], cur->son[1]->l[0]);
            cur->l[1] = std::min(cur->l[1], cur->son[1]->l[1]);
            cur->r[0] = std::max(cur->r[0], cur->son[1]->r[0]);
            cur->r[1] = std::max(cur->r[1], cur->son[1]->r[1]);
        }
        return cur;
    }
    void maketree() {
        root = maketree(pos.begin(), pos.end());
    }
    int query(int xl, int xr, int yl, int yr) {
        if(xl>xr || yl>yr)return inf;
        return root->query(xl, xr, yl, yr);
    }
};

void solve() {
    int n;readInt(n);
    veci p(n+1), c(n+1);
    for(int i=1;i<=n;++i)
        readInt(p[i]);
    for(int i=1;i<=n;++i)
        readInt(c[i]);
    kdtree tr0, trp, trc, trpc;
    for(int i=1;i<=n;++i) {
        tr0.change(p[i], c[i], 0);
        trp.change(p[i], c[i], p[i]);
        trc.change(p[i], c[i], c[i]);
        trpc.change(p[i], c[i], p[i] + c[i]);
    }
    tr0.maketree();
    trp.maketree();
    trc.maketree();
    trpc.maketree();
    // trpc.root->print();
    // printf("custom query answer %d\n", trpc.query(0, 8, 0, 8));
    int m;readInt(m);
    veci vtp(m+1), vtc(m+1), vd(m+1);
    for(int i=1;i<=m;++i)
        readInt(vtp[i]);
    for(int i=1;i<=m;++i)
        readInt(vtc[i]);
    for(int i=1;i<=m;++i)
        readInt(vd[i]);
    int bnd = 2097151;
    for(int i=1;i<=m;++i) {
        int tp = vtp[i];
        int tc = vtc[i];
        int d = vd[i];
        int ans = inf;
        ans = std::min(ans, 
            tr0.query(0, tp-1, 0, tc-1) + 0
        );
        ans = std::min(ans, 
            trc.query(0, tp-1, tc, tc+d-1) + 0
        );
        ans = std::min(ans, 
            tr0.query(0, tp-1, tc+d, bnd) + tc + d
        );
        ans = std::min(ans, 
            trp.query(tp, tp+d-1, 0, tc-1) + 0
        );
        ans = std::min(ans, 
            trpc.query(tp, tp+d-1, tc, tc+d-1) + 0
        );
        ans = std::min(ans, 
            trp.query(tp, tp+d-1, tc+d, bnd) + tc + d
        );
        ans = std::min(ans, 
            tr0.query(tp+d, bnd, 0, tc-1) + tp + d
        );
        ans = std::min(ans, 
            trc.query(tp+d, bnd, tc, tc+d-1) + tp + d
        );
        ans = std::min(ans, 
            tr0.query(tp+d, bnd, tc+d, bnd) + tp + d + tc + d
        );
        printf("%d\n", ans);
    }
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}