#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>

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
        int mx;//, mn;
        int tag;
        Node *son[2];
        Node():mx(INT_MIN),tag(),son{NULL, NULL}{}
        void update() {
            mx = INT_MIN;
            if(son[0] != NULL) {
                mx = std::max(mx, son[0]->mx);
            }
            if(son[1] != NULL) {
                mx = std::max(mx, son[1]->mx);
            }
        }
        void pushdown() {
            if(son[0] == NULL)
                son[0] = new Node;
            son[0] -> mx += tag;
            son[0] -> tag += tag;
            if(son[1] == NULL)
                son[1] = new Node;
            son[1] -> mx += tag;
            son[1] -> tag += tag;
            tag = 0;
        }
        void add(int l, int r, int ql, int qr, int v) {
            // printf("add %d %d %d %d %d\n", l, r, ql, qr, v);
            if(ql<=l&&r<=qr) {
                mx += v;
                tag += v;
                return ;
            }
            int mid = ((l+r) >> 1);
            // printf("pushdown %d %d\n", l, r);
            this->pushdown();
            if(ql<=mid) {
                son[0]->add(l, mid, ql, qr, v);
            }
            if(qr>mid) {
                son[1]->add(mid+1, r, ql, qr, v);
            }
            this->update();
        }
        void change(int l, int r, int x, int v) {
            if(l==r) {
                mx =  v;
                return ;
            }
            int mid = ((l+r)>>1);
            if(x<=mid) {
                if(son[0]==NULL)
                    son[0] = new Node;
                son[0]->change(l, mid, x, v);
            }
            else {
                if(son[1]==NULL)
                    son[1] = new Node;
                son[1]->change(mid+1, r, x, v);
            }
            this->update();
        }
        int max(int l, int r, int ql, int qr) {
            // printf("max %d %d %d %d\n", l, r, ql, qr);
            if(ql<=l&&r<=qr) return this->mx;
            int mid = ((l+r)>>1);
            // printf("pushdown %d %d\n", l, r);
            this->pushdown();
            int ans = INT_MIN;
            if(ql<=mid)
                ans = std::max(ans, son[0]->max(l, mid, ql, qr));
            if(qr>mid)
                ans = std::max(ans, son[1]->max(mid+1, r, ql, qr));
            return ans;
        }
        // int min(int l, int r, int ql, int qr) {
        //     if(ql<=l&&r<=qr) return this->mn;
        //     int mid = ((l+r)>>1);
        //     this->pushdown();
        //     int ans = INT_MAX;
        //     if(ql<=mid)
        //         ans = std::min(ans, son[0]->min(l, mid, ql, qr));
        //     if(qr>mid)
        //         ans = std::min(ans, son[1]->min(mid+1, r, ql, qr));
        //     return ans;
        // }
        void print(int l, int r) {
            printf("[%d, %d]\nmx:%d\ntag:%d\nson[0]:%p\nson[1]:%p\n", l, r, mx, tag, son[0], son[1]);
            printf("--------------------\n");
            int mid = ((l+r)>>1);
            if(son[0]!=NULL)
                son[0]->print(l, mid);
            if(son[1]!=NULL)
                son[1]->print(mid+1, r);
        }
    };
    Node *root;
    int L, R;
    Segtree(int l, int r):L(l),R(r){root = new Node;}
    void change(int x, int v) {
        root->change(L, R, x, v);
    }
    void add(int l, int r, int v) {
        if(l>r)
            return;
        root->add(L, R, l, r, v);
    }
    int max(int l, int r) {
        if(l > r)
            return INT_MIN;
        return root->max(L, R, l, r);
    }
    // int min(int l, int r) {
    //     return root->min(L, R, l, r);
    // }
    void print() {
        root->print(L, R);
    }
};

char str[200010];

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        scanf("%s", str+1);
        std::vector<int> sum(n+1);
        Segtree tree(1, n);
        for(int i=1;i<=n;++i) {
            if(str[i] == 'a')
                sum[i] = sum[i-1] + 1;
            else
                sum[i] = sum[i-1] - 1;
        }
        if(sum[n] == 0) {
            printf("0\n");
            continue;
        }
        if(sum[n] < 0) {
            for(int i=1;i<=n;++i) {
                if(str[i] == 'a')
                    str[i] = 'b';
                else
                    str[i] = 'a';
                sum[i] = -sum[i];
            }
        }
        for(int i=1;i<=n;++i)
            tree.change(i, sum[i]);
        // tree.print();
        int len = n;
        for(int st=1;st<=n;++st) {
            
            if(tree.max(st, n) >= sum[n]) {
                int l = st, r = n;
                for(;l<r;) {
                    int mid = ((l+r)>>1);
                    if(tree.max(st, mid) >= sum[n])
                        r = mid;
                    else
                        l = mid + 1;
                }
                len = std::min(len, r - st + 1);
            }
            int v = ((str[st]=='a')?1:-1);
            tree.add(st+1, n, -v);
        }
        if(len == n)
            printf("-1\n");
        else
            printf("%d\n", len);
    }

    return 0;
}