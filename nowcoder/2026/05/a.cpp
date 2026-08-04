#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

int tot = -1;
struct SAM {
    struct Node {
        int id, len;
        Node *link;
        std::map<char, Node*> next;
        Node() {
            ++tot;
            id = tot;
            len = 0;
            link = NULL;
        }
    };

    std::vector<Node*> all_nodes;

    Node *root, *last;
    SAM() {
        root = new Node;
        all_nodes.emplace_back(root);
        last = root;
    }
    Node *append(char c) {
        Node *cur = new Node;
        all_nodes.emplace_back(cur);
        cur->len = last->len + 1;
        Node *p = last;
        for (; p != NULL; p = p->link) {
            if (p->next.find(c) != p->next.end()) {
                break;
            } else {
                p->next[c] = cur;
            }
        }
        if (p == NULL) {
            cur->link = root;
            last = cur;
            return cur;
        }
        Node *q = p->next[c];
        if (p->len + 1 == q->len) {
            cur->link = q;
        } else {
            Node *cq = new Node;
            all_nodes.emplace_back(cq);
            cq->len = p->len + 1;
            cq->link = q->link;
            cq->next = q->next;
            
            q->link = cq;
            cur->link = cq;

            for (; p != NULL && p->next.find(c) != p->next.end() && p->next[c] == q; p = p->link) {
                p->next[c] = cq;
            }
        }
        last = cur;
        return cur;
    }
};

int mnl[800010], mxl[800010];

struct Segtree {
    struct Node {
        i64 val, cnt, sum;
        i64 tag;
        Node *son[2];
        Node() : val(), cnt(), sum(), tag(), son{NULL, NULL} {}
        void pushup() {
            val = cnt = sum = 0;
            if (son[0]) {
                val += son[0]->val;
                cnt += son[0]->cnt;
                sum += son[0]->sum;
            }
            if (son[1]) {
                val += son[1]->val;
                cnt += son[1]->cnt;
                sum += son[1]->sum;
            }
        }
        void modify(i64 delta) {
            this->val += delta;
            this->sum += delta * cnt;
            this->tag += delta;
        }
        void pushdown() {
            if (son[0] == NULL)
                son[0] = new Node;
            if (son[1] == NULL)
                son[1] = new Node;
            if (tag == 0)
                return;
            son[0]->modify(this->tag);
            son[1]->modify(this->tag);
            this->tag = 0;
        }

        void add(int l, int r, int ql, int qr, i64 delta) {
            if (ql <= l && r <= qr) {
                this->modify(delta);
                return;
            }
            pushdown();
            int mid = ((l + r) >> 1);
            if (ql <= mid)
                son[0]->add(l, mid, ql, qr, delta);
            if (qr > mid)
                son[1]->add(mid + 1, r, ql, qr, delta);
            pushup();
        }

        i64 query(int l, int r, int ql, int qr) {
            if (ql <= l && r <= qr)
                return this->sum;
            pushdown();
            int mid = ((l + r) >> 1);
            i64 ans = 0;
            if (ql <= mid)
                ans += son[0]->query(l, mid, ql, qr);
            if (qr > mid)
                ans += son[1]->query(mid + 1, r, ql, qr);
            pushup();
            return ans;
        }

        void setcnt(int l, int r, int x, i64 val) {
            if (l == r) {
                this->cnt = val;
                return;
            }
            int mid = ((l + r) >> 1);
            if (x <= mid) {
                if (son[0] == NULL)
                    son[0] = new Node;
                son[0]->setcnt(l, mid, x, val);
            } else {
                if (son[1] == NULL)
                    son[1] = new Node;
                son[1]->setcnt(mid+1, r, x, val);
            }
            this->pushup();
        }

        i64 getval(int l, int r, int x) {
            if (l == r) {
                return this->val;
            }
            pushdown();
            int mid = ((l + r) >> 1);
            if (x <= mid)
                return son[0]->getval(l, mid, x);
            else
                return son[1]->getval(mid + 1, r, x);
            pushup();
        }
    };

    Node *root;
    int L, R;
    Segtree(int l, int r) {
        root = new Node;
        L = l;
        R = r;
    }
    void add(int l, int r, i64 delta) {
        // printf("add %d %d %lld\n", l, r, delta);
        root->add(L, R, l, r, delta);
    }
    i64 query(int l, int r) {
        i64 ans = root->query(L, R, l, r);
        // printf("query %d %d = %lld\n", l, r, ans);
        return ans;
    }
    void setcnt(int x, i64 val) {
        // printf("setcnt %d %lld\n", x, val);
        root->setcnt(L, R, x, val);
    }
    i64 getval(int x) {
        i64 ans = root->getval(L, R, x);
        // printf("getval %d = %lld\n", x, ans);
        return ans;
    }
};

typedef std::vector<std::vector<int> > Graph;
char str[400010];
int siz[800010], dep[800010], hs[800010], fa[800010];
int dfn[800010], seq[800010], dfn_tot = -1, top[800010];

void dfs1(int x, int faa, const Graph &g) {
    siz[x] = 1;
    dep[x] = dep[faa] + 1;
    fa[x] = faa;
    for (auto y : g[x]) {
        dfs1(y, x, g);
        siz[x] += siz[y];
        if (hs[x] == 0 || siz[y] > siz[hs[x]]) {
            hs[x] = y;
        }
    }
}

void dfs2(int x, int faa, const Graph &g) {
    ++dfn_tot;
    dfn[x] = dfn_tot;
    seq[dfn_tot] = x;
    if (hs[x]) {
        top[hs[x]] = top[x];
        dfs2(hs[x], x, g);
    }
    for (auto y : g[x]) {
        if (y == hs[x])
            continue;
        top[y] = y;
        dfs2(y, x, g);
    }
}

i64 cal(int p, int m, Segtree &tree) {
    // printf("cal %d %d\n", p, m);
    for (; p;) {
        if (mnl[top[p]] > m) {
            p = fa[top[p]];
            continue;
        }
        int q = top[p];
        if (m <= mxl[q]) {
            p = q;
            break;
        }
        for (int i = 18; i >= 0; --i) {
            if (dfn[q] + (1 << i) > dfn[p])
                continue;
            if (mxl[seq[dfn[q] + (1 << i)]] < m)
                q = seq[dfn[q] + (1 << i)];
        }
        p = seq[dfn[q] + 1];
        break;
    }
    // printf("cal p = %d\n", p);
    assert(mnl[p] <= m && m <= mxl[p]);
    i64 ans = 0;
    ans += tree.getval(dfn[p]) * (m - mnl[p] + 1ll);
    p = fa[p];
    for (; p; p = fa[top[p]]) {
        ans += tree.query(dfn[top[p]], dfn[p]);
    }
    return ans;
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", str + 1);
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        int j = n + 1 - i;
        if (j <= i)
            break;
        std::swap(str[i], str[j]);
        std::swap(a[i], a[j]);
    }
    
    SAM sam;
    std::vector<SAM::Node *> node(n + 2);
    for (int i = 1; i <= n; ++i) {
        node[i] = sam.append(str[i]);
    }

    Graph g(tot + 2);
    for (auto ptr : sam.all_nodes) {
        int id = ptr->id;
        mxl[id] = ptr->len;
        if (id)
            mnl[id] = ptr->link->len + 1;
        else
            mnl[id] = 0;
        // printf("#%d: [%d, %d]\n", id, mnl[id], mxl[id]);
        if (ptr->link == NULL)
            continue;
        g[ptr->link->id].emplace_back(ptr->id);
        // printf("%d --> %d\n", ptr->link->id, ptr->id);
    }

    dfs1(0, 0, g);
    dfs2(0, 0, g);

    // for (int i = 0; i <= tot; ++i)
    //     printf("dfn[%d] = %d\n", i, dfn[i]);
    // for (int i = 0; i <= dfn_tot; ++i)
    //     printf("%d ", seq[i]);
    // printf("\n");

    Segtree tree(0, dfn_tot);

    for (int i = 1; i <= tot; ++i) {
        tree.setcnt(dfn[i], mxl[i] - mnl[i] + 1);
    }

    for (int i = 1; i <= n; ++i) {
        int p = node[i]->id;
        for (; p; p = fa[top[p]]) {
            tree.add(dfn[top[p]], dfn[p], a[i]);
        }
    }

    while (q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            i64 i, x;
            scanf("%lld%lld", &i, &x);
            i = n - i + 1;
            i64 delta = x - a[i];
            a[i] = x;

            int p = node[i]->id;
            for (; p; p = fa[top[p]]) {
                tree.add(dfn[top[p]], dfn[p], delta);
            }
        } else if (op == 2) {
            int p, m;
            scanf("%d%d", &p, &m);
            p = n - p + 1;
            p = node[p]->id;
            i64 ans = cal(p, m, tree);
            printf("%lld\n", ans);
        } else if (op == 3) {
            int p, m;
            i64 k;
            scanf("%d%d%lld", &p, &m, &k);
            p = n - p + 1;
            p = node[p]->id;
            int l = 1, r = m + 1;
            while (l < r) {
                int mid = ((l + r) >> 1);
                if (cal(p, mid, tree) >= k)
                    r = mid;
                else
                    l = mid + 1;
            }
            printf("%d\n", l % (m + 1));
        }
    }


    return 0;
}
