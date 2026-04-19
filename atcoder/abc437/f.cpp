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

typedef bool (*mm_func)(int64, int64);

struct Segtree_max {
    struct Node {
        int64 val;
        Node *son[2];
        Node():val(),son{NULL, NULL} {}
        void update() {
            val = LLONG_MIN;
            if(son[0] != NULL) {
                val = std::max(val, son[0]->val);
            }
            if(son[1] != NULL) {
                val = std::max(val, son[1]->val);
            }
        }
        void change(int l, int r, int x, int v) {
            if(l == r) {
                val = v;
                return;
            }
            int mid = ((l+r)>>1);
            if(x<=mid) {
                if(son[0]==NULL)
                    son[0] = new Node;
                son[0]->change(l, mid, x, v);
            } else {
                if(son[1]==NULL)
                    son[1] = new Node;
                son[1]->change(mid+1, r, x, v);
            }
            this->update();
        }

        int64 query(int l, int r, int ql, int qr) {
            if(ql<=l && r<=qr) {
                return this->val;
            }
            int mid = ((l+r)>>1);
            int64 ans = INT_MIN;
            if(ql<=mid)
                ans = std::max(ans, son[0]->query(l, mid, ql, qr));
            if(qr>mid)
                ans = std::max(ans, son[1]->query(mid+1, r, ql, qr));
            return ans;
        }
    };
    Node *root;
    int L, R;
    Segtree_max(int l, int r) {
        L = l, R = r;
        root = new Node;
    }
    void change(int x, int v) {
        root->change(L, R, x, v);
    }
    int64 query(int l, int r) {
        return root->query(L, R, l, r);
    }
};
struct Segtree_min {
    struct Node {
        int64 val;
        Node *son[2];
        Node():val(),son{NULL, NULL} {}
        void update() {
            val = LLONG_MAX;
            if(son[0] != NULL) {
                val = std::min(val, son[0]->val);
            }
            if(son[1] != NULL) {
                val = std::min(val, son[1]->val);
            }
        }
        void change(int l, int r, int x, int v) {
            if(l == r) {
                val = v;
                return;
            }
            int mid = ((l+r)>>1);
            if(x<=mid) {
                if(son[0]==NULL)
                    son[0] = new Node;
                son[0]->change(l, mid, x, v);
            } else {
                if(son[1]==NULL)
                    son[1] = new Node;
                son[1]->change(mid+1, r, x, v);
            }
            this->update();
        }

        int64 query(int l, int r, int ql, int qr) {
            if(ql<=l && r<=qr) {
                return this->val;
            }
            int mid = ((l+r)>>1);
            int64 ans = LLONG_MAX;
            if(ql<=mid)
                ans = std::min(ans, son[0]->query(l, mid, ql, qr));
            if(qr>mid)
                ans = std::min(ans, son[1]->query(mid+1, r, ql, qr));
            return ans;
        }
    };
    Node *root;
    int L, R;
    Segtree_min(int l, int r) {
        L = l, R = r;
        root = new Node;
    }
    void change(int x, int v) {
        root->change(L, R, x, v);
    }
    int64 query(int l, int r) {
        return root->query(L, R, l, r);
    }
};

int main() {
    int n, q;readInt(n, q);
    Segtree_max pl_mx(1, n), mi_mx(1, n);
    Segtree_min pl_mn(1, n), mi_mn(1, n);
    for(int i=1;i<=n;++i) {
        int64 x, y;readInt(x, y);
        pl_mx.change(i, x+y);
        pl_mn.change(i, x+y);
        mi_mx.change(i, x-y);
        mi_mn.change(i, x-y);
    }
    for(;q;--q) {
        int op;readInt(op);
        if(op == 1) {
            int p;
            int64 x, y;readInt(p, x, y);
            pl_mx.change(p, x+y);
            pl_mn.change(p, x+y);
            mi_mx.change(p, x-y);
            mi_mn.change(p, x-y);
        } else {
            int64 l, r, x, y;readInt(l, r, x, y);
            int64 ans = 0;
            int64 plmn = pl_mn.query(l, r);
            int64 plmx = pl_mx.query(l, r);
            int64 mimn = mi_mn.query(l, r);
            int64 mimx = mi_mx.query(l, r);
            int64 pl = x + y;
            int64 mi = x - y;
            ans = std::max(std::max(plmx-pl, pl-plmn), std::max(mimx-mi, mi-mimn));
            printf("%lld\n", ans);
        }     
    }

    return 0;
}