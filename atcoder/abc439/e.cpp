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

struct Segtree {
    struct Node {
        int mx;
        Node *son[2];
        Node():mx(INT_MIN),son{NULL, NULL}{}
        void update() {
            mx = INT_MIN;
            if(son[0]!=NULL)
                mx = std::max(son[0]->mx, mx);
            if(son[1]!=NULL)
                mx = std::max(son[1]->mx, mx);
        }

        void change(int l, int r, int x, int v) {
            if(l==r) {
                mx = std::max(mx, v);
                return; 
            }
            int mid = ((l+r)>>1);
            if(x<=mid) {
                if(son[0] == NULL)
                    son[0] = new Node;
                son[0]->change(l, mid, x, v);
            } else {
                if(son[1] == NULL)
                    son[1] = new Node;
                son[1]->change(mid+1, r, x, v);
            }
            this->update();
        }
        int query(int l, int r, int ql, int qr) {
            if(ql<=l&&r<=qr) {
                return mx;
            }
            int mid = ((l+r)>>1);
            int ans = INT_MIN;
            if(ql <= mid) {
                if(son[0]!=NULL)
                    ans = std::max(ans, son[0]->query(l, mid, ql, qr));
            }
            if(qr>mid) {
                if(son[1]!=NULL)
                    ans = std::max(ans, son[1]->query(mid+1, r, ql, qr));
            }
            return ans;
        }
    };

    Node *root;
    int L, R;
    Segtree(int l, int r) {
        L = l;R = r;
        root = new Node;
    }
    void change(int x, int v) {
        root->change(L, R, x, v);
    }
    int query(int l, int r) {
        return root->query(L, R, l, r);
    }
};

int main() {
    int n;readInt(n);
    std::vector< std::pair<int, int> > vec(n);
    for(int i=0;i<n;++i)
        readInt(vec[i].first, vec[i].second);
    std::sort(vec.begin(), vec.end());
    Segtree tree(0, 1e9);
    std::vector<int> f(n);
    for(auto it=vec.begin();it!=vec.end();) {
        auto end = it;
        while(end!=vec.end() && end->first == it->first) ++ end;
        for(auto tt=it;tt!=end;++tt) {
            f[tt-vec.begin()] = 1 + std::max(0, tree.query(0, tt->second - 1));
        }
        for(auto tt=it;tt!=end;++tt) {
            tree.change(tt->second, f[tt-vec.begin()]);
        }
        it = end;
    }
    int ans = 0;
    for(int i=0;i<n;++i)
        ans = std::max(ans, f[i]);
    printf("%d\n", ans);

    return 0;
}