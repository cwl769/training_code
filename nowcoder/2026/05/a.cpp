#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

int cnt = -1;
struct SAM {
    struct Node {
        int id, len;
        Node *link;
        std::map<char, Node*> next;
        Node() {
            ++cnt;
            id = cnt;
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

int mnl[400010], mxl[400010];

struct Segtree {
    struct Node {
        i64 val, cnt, sum;
        i64 tag;
        Node *son[2];
        Node() : val(), cnt(), sum(), son{NULL, NULL} {}
        void pushup() {
            val = sum = 0;
            if (son[0]) {
                val += son[0]->val;
                sum += son[0]->sum;
            }
            if (son[1]) {
                val += son[1]->val;
                sum += son[1]->sum;
            }
        }
        void modify(int l, int r, i64 delta) {
            this->val += delta;
            this->sum += delta * (r - l + 1);
            this->tag += delta;
        }
        void pushdown(int l, int r) {
            if (son[0] == NULL)
                son[0] = new Node;
            if (son[1] == NULL)
                son[1] = new Node;
            if (tag == 0)
                return;
            int mid = ((l + r) >> 1);
            son[0]->modify(l, mid, this->tag);
            son[1]->modify(mid + 1, r, this->tag);
            this->tag = 0;
        }

        void add(int l, int r, int ql, int qr, i64 delta) {
            if (ql <= l && r <= qr) {
                this->modify(l, r, delta);
                return;
            }
            pushdown(l, r);
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
            pushdown(l, r);
            int mid = ((l + r) >> 1);
            i64 ans = 0;
            if (ql <= mid)
                ans += son[0]->query(l, mid, ql, qr);
            if (qr > mid)
                ans += son[1]->query(mid + 1, r, ql, qr);
            pushup();
            return ans;
        }
    };
};

typedef std::vector<std::vector<int> > Graph;
char str[200010];
int siz[400010], dep[400010], hs[400010], fa[400010];
int dfn[400010], seq[400010], dfn_tot = 0, top[400010];

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

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; ++i) {
        int j = n + 1 - i;
        if (j <= i)
            break;
        std::swap(str[i], str[j]);
    }
    SAM sam;
    std::vector<SAM::Node *> node(n + 2);
    for (int i = 1; i <= n; ++i) {
        node[i] = sam.append(str[i]);
    }

    Graph g(cnt + 2);
    for (auto ptr : sam.all_nodes) {
        int id = ptr->id;
        mxl[id] = ptr->len;
        if (id)
            mnl[id] = ptr->link->len + 1;
        else
            mnl[id] = 0;
        if (ptr->link == NULL)
            continue;
        g[ptr->link->id].emplace_back(ptr->id);
    }

    dfs1(0, 0, g);
    dfs2(0, 0, g);

    


    return 0;
}
