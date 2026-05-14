#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <queue>
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

typedef std::vector<std::vector<std::pair<int, int64> > > Graph;

struct Edge {
    int x, y;
    i64 a;
};

void dijkstra(int st, veci64& dis, const int n, const Graph& g) {
    dis.assign(n+1, LLONG_MAX / 4);
    std::priority_queue<std::pair<i64, int> > heap;
    dis[st] = 0;
    heap.push({-dis[st], st});
    std::vector<bool> vis(n+1);
    while(heap.size()) {
        int x = heap.top().second;
        heap.pop();
        if(vis[x])
            continue;
        vis[x] = 1;
        for(auto [y, val]:g[x]) {
            if(dis[x] + val < dis[y]) {
                dis[y] = dis[x] + val;
                heap.push({-dis[y], y});
            }
        }
    }
}

struct Segtree {
    struct Node {
        int val;
        Node *son[2];
        Node():val(),son{NULL, NULL}{}
        Node(Node *old) {
            if(old == NULL) {
                val = 0;
                son[0] = son[1] = NULL;
            }
            val = old->val;
            son[0] = old->son[0];
            son[1] = old->son[1];
        }
        void change(Node *old, int l, int r, int x, int v) {
            if(l == r) {
                this->val = v;
                return;
            }
            int mid = ((l+r)>>1);
            if(x<=mid) {
                Node *oldson = ((old==NULL)?NULL:old->son[0]);
                son[0] = new Node(oldson);
                son[0]->change(oldson, l, mid, x, v);
            } else {
                Node *oldson = ((old==NULL)?NULL:old->son[1]);
                son[1] = new Node(oldson);
                son[1]->change(oldson, mid+1, r, x, v);
            }
        }
        int query(int l, int r, int x) {
            if(l == r) {
                return val;
            }
            int mid = ((l+r)>>1);
            if(x<=mid)
                return son[0]->query(l, mid, x);
            else
                return son[1]->query(mid+1, r, x);
        }
    };
    int L, R;
    Segtree(int l, int r) {
        L = l;R = r;
    }
    Node* change(Node *root, int x, int v) {
        Node *cur = new Node(root);
        cur->change(root, L, R, x, v);
        return cur;
    }
    int query(Node *root, int x) {
        root->query(L, R, x);
    }
};
typedef Segtree::Node Node;

struct DSU {
    Segtree tree, mn;
    Node *lastroot, ;
    DSU(int n):tree(1, n),mn(1, n) {
        lastroot = NULL;
        for(int i=1;i<=n;++i) {
            lastroot = tree.change(lastroot, i, i);
        }
    }
    int get(Node *&root, int x) {
        int fa = tree.query(root, x);
        if(fa == x)return x;
        int ans = get(root, fa);
        root = tree.change(root, x, ans);
        return ans;
    }
    Node *merge(Node *root, int x, int y) {
        x = get(root, x);
        y = get(root, y);
        if(x == y)return root;
        return tree.change(root, x, y);
    }
};

void solve() {
    int n, m;readInt(n, m);
    Graph g(n+1);
    std::vector<Edge> edg;
    for(int i=1;i<=m;++i) {
        int x, y;i64 l, a;
        g[x].push_back({y, l});
        g[y].push_back({x, l});
        edg.push_back({x, y, a});
    }
    std::vector<i64> dis;
    dijkstra(1, dis, n, g);
    
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}