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

struct Segtree {
    struct Segtree_inner {
        struct Node {
            int mn;
            Node *son[2];
            Node():mn(INT_MAX),son{NULL,NULL}{}
            void change(int l, int r, int ql, int qr, int v) {
                if(ql<=l&&r<=qr) {
                    mn = std::min(mn, v);
                    return;
                }
                int mid = ((l+r) >> 1);
                if(ql<=mid) {
                    if(son[0] == NULL)
                        son[0] = new Node;
                    son[0]->change(l, mid, ql, qr, v);
                }
                if(qr>mid) {
                    if(son[1] == NULL)
                        son[1] = new Node;
                    son[1]->change(mid+1, r, ql, qr, v);
                }
            }
            int query(int l, int r, int x) {
                if(l==r) return mn;
                int ret = mn;
                int mid = ((l+r) >> 1);
                if(x<=mid) {
                    if(son[0]!=NULL)
                        ret = std::min(ret, son[0]->query(l, mid, x));
                } else {
                    if(son[1]!=NULL)
                        ret = std::min(ret, son[1]->query(mid+1, r, x));
                }
                return ret;
            }
        };
        Node *root;
        int L, R;
        Segtree_inner(int l, int r):L(l),R(r){root = new Node;}
        void change(int l, int r, int v){
            root->change(L, R, l, r, v);
        }
        int query(int x) {
            return root->query(L, R, x);
        }
    };
    static int inL, inR;
    struct Node {
        Segtree_inner tree;
        Node *son[2];
        Node():tree(inL, inR),son{NULL, NULL}{}
        void change(int l, int r, int ql, int qr, int vl, int vr, int vv) {
            if(ql<=l&&r<=qr) {
                tree.change(vl, vr, vv);
                return;
            }
            int mid = ((l+r) >> 1);
            if(ql<=mid) {
                if(son[0] == NULL)
                    son[0] = new Node;
                son[0]->change(l, mid, ql, qr, vl, vr, vv);
            }
            if(qr>mid) {
                if(son[1] == NULL)
                    son[1] = new Node;
                son[1]->change(mid+1, r, ql, qr, vl, vr, vv);
            }
        }
        int query(int l, int r, int x, int y) {
            if(l==r)return tree.query(y);
            int ret = tree.query(y);
            int mid = ((l+r)>>1);
            if(x<=mid) {
                if(son[0]!=NULL)
                    ret = std::min(ret, son[0]->query(l, mid, x, y));
            } else {
                if(son[1]!=NULL)
                    ret = std::min(ret, son[1]->query(mid+1, r, x, y));
            }
            return ret;
        }
    };
    Node *root;
    int L, R;
    Segtree(int u, int d, int l, int r):L(u),R(d) {
        inL = l, inR = r;
        root = new Node;
    }
    void change(int u, int d, int l, int r, int v) {
        root->change(L, R, u, d, l, r, v);
    }
    int query(int x, int y) {
        return root->query(L, R, x, y);
    }
};

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n, m;readInt(n, m);
        std::vector<std::vector<char> > map(n+2);
        for(int i=0;i<=n+1;++i)
            map[i].resize(m+2);
        for(int i=1;i<=n;++i)
            scanf("%s", &map[i][1]);
        std::vector<>
    }

    return 0;
}