#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::vector<veci> Graph;

struct Operation {
    int x;
    int l, r;
    int id;
    Operation(int a, int b, int c, int d) {
        x = a;
        l = b;
        r = c;
        id = d;
    }
};
bool operator < (const Operation& a, const Operation& b) {
    return a.x < b.x;
}

struct Segtree {
    struct Node {
        int val;
        Node *son[2];
        Node():val(-1), son{NULL, NULL}{}
        Node(int x):val(x), son{NULL, NULL}{}
        void pushdown() {
            if(val == -1)
                return;
            if(son[0] == NULL)
                son[0] = new Node(val);
            else
                son[0]->val = val;
            if(son[1] == NULL)
                son[1] = new Node(val);
            else
                son[1]->val = val;
            val = -1;
        }
        void change(int l, int r, int ql, int qr, int v) {
            if(ql <= l && r <= qr) {
                val = v;
                return;
            }
            pushdown();
            int mid = ((l + r) >> 1);
            if(ql <= mid)
                son[0]->change(l, mid, ql, qr, v);
            if(qr > mid)
                son[1]->change(mid+1, r, ql, qr, v);
        }
        int query(int l, int r, int x) {
            if(val != -1)
                return val;
            pushdown();
            int mid = ((l + r) >> 1);
            if(x <= mid)
                return son[0]->query(l, mid, x);
            else
                return son[1]->query(mid + 1, r, x);
        }
    };
    Node *root;
    int L, R;
    Segtree(int l, int r) {
        root = new Node;
        L = l;
        R = r;
        root->val = 0;
    }
    void change(int l, int r, int v) {
        root->change(L, R, l, r, v);
    }
    int query(int x) {
        return root->query(L, R, x);
    }
};

constexpr int N = 500010;

struct Fenwick {
    int c[N];
    void add(int x, int v) {
        ++x;
        for(;x < N;x += (x & (-x)))
            c[x] += v;
    }
    int query(int x) {
        ++x;
        int ans = 0;
        for(;x;x -= (x & (-x)))
            ans += c[x];
        return ans;
    }
    int sum(int x) {
        return query(x);
    }
};
int fa[N];
veci g[N];

int dep[N], siz[N], hs[N];
int dfn[N], seq[N], dfn_tot = -1, top[N];
void dfs1(int x) {
    if(x) dep[x] = dep[fa[x]] + 1;
    siz[x] = 1;
    for (auto y : g[x]) {
        dfs1(y);
        siz[x] += siz[y];
        if(hs[x] == 0 || siz[y] > siz[hs[x]])
            hs[x] = y;
    }
}

void dfs2(int x, int ttop) {
    top[x] = ttop;
    dfn[x] = ++dfn_tot;
    seq[dfn[x]] = x;
    if(hs[x]) {
        dfs2(hs[x], ttop);
    }
    for (auto y : g[x]) {
        if(y == hs[x])
            continue;
        dfs2(y, y);
    }
}

bool val[N];
Fenwick tree, ans;

int find(int x) {
    // printf("find %d\n", x);
    while(top[x] && tree.sum(dfn[top[x]]) == 0) {
        x = fa[top[x]];
    }
    // printf("now x = %d\n", x);
    if(tree.sum(dfn[x]))
        return dep[x] + 1;
    int l = dfn[top[x]], r = dfn[x];
    // printf("(find) [%d, %d]\n", l, r);
    for(int i = 20; i >= 0; --i) {
        int tt = r - (1 << i);
        if(tt >= l && tree.sum(tt) == 0)
            r = tt;
        // printf("r = %d, tt = %d\n", r, tt);
    }
    return dep[seq[r]];
}

char str[10];

int main() {
    int n, Q;
    scanf("%d%d", &n, &Q);
    std::vector<Operation> ops;
    for (int i = 1; i <= n; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        ops.emplace_back(x1, y1, y2, i);
        ops.emplace_back(x2, y1, y2, -i);
    }
    std::sort(ops.begin(), ops.end());
    Segtree segtree(1, 1e9+10);
    for (auto op : ops) {
        if(op.id > 0) {
            fa[op.id] = segtree.query(op.l);
            g[fa[op.id]].emplace_back(op.id);
            segtree.change(op.l, op.r, op.id);
        } else {
            segtree.change(op.l, op.r, fa[-op.id]);
        }
    }
    // for (int i = 1; i <= n; ++i)
    //     printf("fa[%2d] = %2d | %2d -> %2d\n", i, fa[i], fa[i], i);
    dfs1(0);
    dfs2(0, 0);
    while(Q--) {
        int kk;
        scanf("%s%d", str, &kk);
        // printf("-------%s %d-------\n", str, kk);
        if(str[0] == '^') {
            if(val[kk]) {
                int x = kk;
                while(1) {
                    int l = dfn[top[x]];
                    int r = dfn[x];
                    tree.add(l, -1);
                    tree.add(r + 1, 1);
                    if(top[x] == 0)
                        break;
                    x = fa[top[x]];
                }
                x = kk;

                if(tree.sum(dfn[kk]) == 0) {
                    int l = find(kk);
                    int r = dep[kk];
                    // printf("ans change [%d, %d] - 1\n", l, r);
                    ans.add(l, -1);
                    ans.add(r + 1, 1);
                }
            } else {
                if(tree.sum(dfn[kk]) == 0) {
                    int l = find(kk);
                    int r = dep[kk];
                    // printf("ans change [%d, %d] + 1\n", l, r);
                    ans.add(l, 1);
                    ans.add(r + 1, -1);
                }

                int x = kk;
                while(1) {
                    int l = dfn[top[x]];
                    int r = dfn[x];
                    tree.add(l, 1);
                    tree.add(r + 1, -1);
                    if(top[x] == 0)
                        break;
                    x = fa[top[x]];
                }
                x = kk;
            }
            val[kk] ^= 1;
        } else {
            printf("%d\n", ans.sum(kk + 1));
        }
        // for (int i = 0; i <= n; ++i)
        //     printf("%2d ", ans.sum(i));
        // printf("\n");

        // printf("tree:\n");
        // for (int i = 0; i <= n; ++i)
        //     printf("%2d ", tree.sum(i));
        // printf("\n");
    }

    return 0;
}