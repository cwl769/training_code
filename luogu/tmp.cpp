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

struct Segtree_inner {
    struct Node {
        int sum;
        Node *son[2];
        Node():sum(),son{NULL, NULL}{}
        void pushup() {
            sum = 0;
            if(son[0]!=NULL)
                sum += son[0]->sum;
            if(son[1]!=NULL)
                sum += son[1]->sum;
        }
        void add(int l, int r, int x) {
            if(l == r) {
                this->sum ++;
                return ;
            }
            int mid = ((l+r) >> 1);
            if(x<=mid) {
                if(son[0] == NULL)
                    son[0] = new Node();
                son[0]->add(l, mid, x);
            } else {
                if(son[1] == NULL)
                    son[1] = new Node();
                son[1]->add(mid+1, r, x);
            }
            pushup();
        }
        int query(int l, int r, int ql, int qr) {
            if(ql<=l&&r<=qr) {
                return this->sum;
            }
            int mid = ((l+r)>>1);
            int ans = 0;
            if(ql<=mid) {
                if(son[0] != NULL) {
                    ans += son[0]->query(l, mid, ql, qr);
                }
            }
            if(qr>mid) {
                if(son[1] != NULL) {
                    ans += son[1]->query(mid+1, r, ql, qr);
                }
            }
            return ans;
        }
    };
    Node *root;
    static int L, R;
    Segtree_inner() {
        root = new Node;
    }
    void add(int x) {
        root->add(L, R, x);
    }
    int query(int l, int r) {
        return root->query(L, R, l, r);
    }
};
int Segtree_inner::L;
int Segtree_inner::R;

struct Segtree {
    struct Node {
        Segtree_inner tree;
        Node *son[2];
        void add(int l, int r, int x, int y) {
            tree.add(y);
            if(l == r) {
                return;
            }
            int mid = ((l+r)>>1);
            if(x<=mid) {
                if(son[0] == NULL)
                    son[0] = new Node;
                son[0]->add(l, mid, x, y);
            } else {
                if(son[1] == NULL)
                    son[1] = new Node;
                son[1]->add(mid+1, r, x, y);
            }
        }
        int query(int l, int r, int xl, int xr, int yl, int yr) {
            if(xl<=l&&r<=xr) {
                return tree.query(yl, yr);
            }
            int mid = ((l+r)>>1);
            int ans = 0;
            if(xl<=mid) {
                if(son[0]!=NULL)
                    ans += son[0]->query(l, mid, xl, xr, yl, yr);
            }
            if(xr > mid) {
                if(son[1]!=NULL)
                    ans += son[1]->query(mid+1, r, xl, xr, yl, yr);
            }
            return ans;
        }
    };
    Node *root;
    int L, R;
    Segtree(int l, int r){
        root = new Node;
        L = l, R = r;
    }
    void add(int x, int y) {
        root->add(L, R, x, y);
    }
    int query(int xl, int xr, int yl, int yr) {
        return root->query(L, R, xl, xr, yl, yr);
    }
};

void solve1() {
    int n, d, m;
    readInt(n, d, m);
    std::vector<int> a(m+1);
    std::vector<int> p(n+1);
    for(int i=1;i<=n;++i) {
        int x;readInt(x);
        ++a[x];
        p[i] = x;
    }
    for(int i=1;i<=m;++i)
        a[i] += a[i-1];
    int64 ans = 0;
    for(int i=1;i<=n;++i) {
        int l = std::max(1, p[i] - d);
        int r = std::min(m, p[i] + d);
        ans += a[r] - a[l-1];
    }
    ans -= n;
    ans >>= 1;
    printf("%lld\n", ans);
}

void solve2() {
    int n, d, m;
    readInt(n, d, m);
    std::vector<std::pair<int, int> > p(n+1);
    for(int i=1;i<=n;++i) {
        int x, y;readInt(x, y);
        p[i] = {x+y, x-y};
    }
    Segtree_inner::L = 1-m;
    Segtree_inner::R = m-1;
    Segtree tree(2, m*2);
    for(int i=1;i<=n;++i) {
        tree.add(p[i].first, p[i].second);
    }
    int64 ans = 0;
    for(int i=1;i<=n;++i) {
        int x = p[i].first;
        int y = p[i].second;
        ans += tree.query(std::max(2, x-d), std::min(m*2, x+d), std::max(1-m, y-d), std::min(m-1, y+d));
    }
    ans -= n;
    ans >>= 1;
    printf("%lld\n", ans);
}

typedef void (*func)();
func solve[4] = {NULL, solve1, solve2, NULL};

int main() {
    int b;readInt(b);
    solve[b]();

    return 0;
}