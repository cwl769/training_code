#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>

typedef long long int64;
typedef unsigned long long uint64;

template<const int64 M>
class Int_t {
private:
    int64 v;
public:
    Int_t():v(){}
    Int_t(const Int_t& b) {
        v = b.v;
    }
    Int_t(Int_t&& b) {
        v = b.v;
    }
    Int_t(int64 x) {
        if(x<0) {
            v = (x%M)+M;
            if(v==M)v = 0;
        } else if (x >= M) {
            v = x % M;
        } else {
            v = x;
        }
    }
    Int_t& operator = (const Int_t& b) {
        v = b.v;
        return *this;
    }
    Int_t& operator = (Int_t&& b) {
        v = b.v;
        return *this;
    }
    Int_t operator + (Int_t b) const {
        return v + b.v;
    }
    Int_t operator - (Int_t b) const {
        return v - b.v;
    }
    Int_t operator * (Int_t b) const {
        return v * b.v;
    }
    Int_t& operator += (Int_t b) {
        v += b.v;
        if(v >= M)
            v -= M;
        return *this;
    }
    Int_t& operator -= (Int_t b) {
        v -= b.v;
        if(v < 0)
            v += M;
        return *this;
    }
    Int_t& operator *= (Int_t b) {
        v = (v * b.v) % M;
        return *this;
    }
    Int_t operator ^ (uint64 b) const {
        Int_t ans = 1;
        Int_t base = *this;
        for(;b;b>>=1) {
            if(b&1)
                ans *= base;
            base *= base;
        }
        return ans;
    }
    int64 val() const {return v;}
};

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

typedef Int_t<998244353ll> Int;

// struct Segtree {
//     struct Node {
//         Int tag;
//         Node *son[2];
//         Node():tag(),son{NULL, NULL}{}
//         void add(int l, int r, int ql, int qr, const Int& v) {
//             if(ql<=l&&r<=qr) {
//                 tag += v;
//                 return;
//             }
//             int mid = ((l+r)>>1);
//             if(ql<=mid) {
//                 if(son[0] == NULL)
//                     son[0] = new Node;
//                 son[0]->add(l, mid, ql, qr, v);
//             }
//             if(qr>mid) {
//                 if(son[1] == NULL)
//                     son[1] = new Node;
//                 son[1]->add(mid+1, r, ql, qr, v);
//             }
//         }
//         Int query(int l, int r, int x) {
//             if(l == r)
//                 return this->tag;
//             int mid = ((l+r)>>1);
//             Int ans = this->tag;
//             if(x<=mid) {
//                 if(son[0]!=NULL)
//                     ans += son[0]->query(l, mid, x);
//             } else {
//                 if(son[1]!=NULL)
//                     ans += son[1]->query(mid+1, r, x);
//             }
//             return ans;
//         }
        
//     };
//     Node *root;
//     int L, R;
//     Segtree(int l, int r):L(l), R(r) {
//         root = new Node;
//     }
//     void add(int l, int r, Int v) {
//         // printf("tree[0x%x] add(%d, %d, %lld);\n", (int64)(root)&0xff, l, r, v.val());
//         root->add(L, R, l, r, v);
//     }
//     Int query(int x) {
//         return root->query(L, R, x);
//     }
// };

struct Segtree {
    Int *data;
    int N;
    Segtree(int l, int r) {
        N = r + 10;
        data = new Int[N];
    }
    ~Segtree() {
        delete[] data;
    }
    void add(int x, Int v) {
        for(;x<N;x+=(x&(-x))) {
            data[x] += v;
        }
    }
    void add(int l, int r, Int v) {
        add(l, v);
        add(r + 1, Int(0)-v);
    }
    Int query(int x) {
        Int ans = 0;
        for(;x;x-=(x&(-x))) {
            ans += data[x];
        }
        return ans;
    }
};

struct Node {
    std::pair<int, int> val;
    int size;
    Node *son[2];
    Node(int v1, int v2):val(v1, v2) {
        son[0] = son[1] = NULL;
    }
};

void dfs(Node *ptr) {
    if(ptr == NULL) return;
    ptr->size = 1;
    if(ptr->son[0]!=NULL) {
        dfs(ptr->son[0]);
        ptr->size += ptr->son[0]->size;
    }
    if(ptr->son[1]!=NULL) {
        dfs(ptr->son[1]);
        ptr->size += ptr->son[1]->size;
    }
}

int main() {
    int n, M;readInt(n, M);
    std::vector<int> a(n+1);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    std::vector<int> k(M+1);
    for(int i=1;i<=M;++i)
        readInt(k[i]);
    Node *root = new Node(INT_MIN, INT_MIN);
    std::stack<Node*> stack;
    stack.push(root);
    for(int i=1;i<=n;++i) {
        Node *cur = new Node(a[i], i);
        Node *lson = NULL;
        while(stack.top()->val >= cur->val) {
            lson = stack.top();
            stack.pop();
        }
        stack.top()->son[1] = cur;
        stack.push(cur);
        cur->son[0] = lson;
    }
    dfs(root);
    std::map<int, int> kid;
    for(int i=1;i<=M;++i) {
        kid[k[i]] = i;
    }
    Segtree trk(1, M), trc(1, M);
    std::queue<Node*> q;
    q.push(root->son[1]);
    while(q.size()) {
        Node *ptr = q.front();
        q.pop();
        // printf("-------{%d, %d} %d-------\n", ptr->val.first, ptr->val.second, ptr->size);
        int m = ptr->val.first;
        Int m_inv = (Int(m) ^ (998244351));
        // printf("%lld %lld\n", m, m_inv.val());
        int64 cnt = 1;
        if(ptr->son[0] != NULL) {
            cnt *= ptr->son[0]->size + 1ll;
        }
        if(ptr->son[1] != NULL) {
            cnt *= ptr->son[1]->size + 1ll;
        }
        auto it = kid.find(m-1);
        if(it != kid.end()) {
            int id = kid[m-1];
            trc.add(id, id, (Int(1) - m_inv) * cnt);
        }
        it = kid.lower_bound(m);
        if(it != kid.end()) {
            int id = it->second;
            trc.add(id, M, (Int(2) - Int(m) - m_inv) * cnt);
            trk.add(id, M, Int(cnt));
        }
        it = kid.lower_bound(m-1);
        if(it!=kid.begin()) {
            --it;
            int id = it->second;
            trk.add(1, id, m_inv * cnt);
        }
        if(ptr->son[0]!=NULL)
            q.push(ptr->son[0]);
        if(ptr->son[1]!=NULL)
            q.push(ptr->son[1]);
    }
    Int base;
    for(int i=1;i<=n;++i) {
        base += (Int(a[i]) ^ 998244351) * (i) * (n-i+1);
    }
    for(int i=1;i<=M;++i) {
        int id = kid[k[i]];
        // printf("[%d] %lld %lld\n", k[i], trk.query(id).val(), trc.query(id).val());
        printf("%lld\n", (base + (Int(k[i]) * trk.query(id) + trc.query(id))).val());
    }

    return 0;
}