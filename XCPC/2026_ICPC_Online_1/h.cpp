#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
#include <map>

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
            if(p->next.find(c) != p->next.end()) {
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

            for (;
                p != NULL && p->next.find(c) != p->next.end() &&
                p->next[c] == q;
                p = p->link) {
                p->next[c] = cq;
            }
        }
        last = cur;
        return cur;
    } 
};

struct Segtree {
    struct Node {
        i64 a, b;
        Node *son[2];
        Node():a(),b(),son{NULL, NULL}{}
        void maketree(int l, int r) {
            if(l == r)
                return;
            int mid = ((l + r) >> 1);
            son[0] = new Node;
            son[1] = new Node;
            son[0]->maketree(l, mid);
            son[1]->maketree(mid + 1, r);
        }
        Node *add(int l, int r, int x, i64 da, i64 db) const {
            Node *cur = new Node;
            *cur = *this;
            cur->a += da;
            cur->b += db;
            if(l == r) {
                return cur;
            }
            int mid = ((l + r) >> 1);
            if(x <= mid) {
                cur->son[0] = son[0]->add(l, mid, x, da, db);
            } else {
                cur->son[1] = son[1]->add(mid + 1, r, x, da, db);
            }
            return cur;
        }
        std::pair<i64, i64> query(int l, int r, int ql, int qr) const {
            if(ql <= l && r <= qr) {
                return {a, b};
            }
            int mid = ((l + r) >> 1);
            i64 ansa = 0, ansb = 0;
            if(ql <= mid) {
                auto pr = son[0]->query(l, mid, ql, qr);
                ansa += pr.first;
                ansb += pr.second;
            }
            if(qr > mid) {
                auto pr = son[1]->query(mid + 1, r, ql, qr);
                ansa += pr.first;
                ansb += pr.second;
            }
            return {ansa, ansb};
        }
        void dfs(int l, int r) {
            printf("[%d, %d] %lld %lld\n", l, r, a, b);
        }
    };
    std::vector<Node*> root;
    int L, R;
    Segtree(int l, int r, int ver_size) {
        root.emplace_back(new Node);
        L = l;
        R = r;
        root.resize(ver_size);
        root[0]->maketree(L, R);
    }
    void add(int vsrc, int vtar, int x, i64 da, i64 db) {
        root[vtar] = root[vsrc]->add(L, R, x, da, db);
    }
    auto query(int ver, int l, int r) {
        return root[ver]->query(L, R, l, r);
    }
    void print(int ver) {
        root[ver]->dfs(L, R);
    }
};

typedef std::vector<veci> Graph;

char s[200010], t[200010];

int fa[400010], siz[400010], dep[400010], hs[400010];
int dfn[400010], seq[400010], dfn_tot = -1, top[400010];
int trr[400010];

void dfs1(int x, int faa, const Graph& g) {
    fa[x] = faa;
    siz[x] = 1;
    dep[x] = dep[faa] + 1;
    for(auto y : g[x]) {
        dfs1(y, x, g);
        siz[x] += siz[y];
        if(hs[x] == 0 || siz[y] > siz[x]) {
            hs[x] = y;
        }
    }
}

void dfs2(int x, const Graph& g, int tp) {
    dfn[x] = ++dfn_tot;
    seq[dfn[x]] = x;
    top[x] = tp;
    trr[x] = dfn[x];
    if(hs[x]){
        dfs2(hs[x], g, tp);
        trr[x] = trr[hs[x]];
    }
    for (auto y : g[x]) {
        if(y == hs[x])
            continue;
        dfs2(y, g, y);
        trr[x] = trr[y];
    }
}

int main() {
    scanf("%s", t + 1);
    int n = strlen(t + 1);
    SAM sam;
    veci sp(n + 2);
    for (int i = 1; i <= n; ++i) {
        sp[i] = sam.append(t[i])->id;
    }

    Graph g(tot + 2);
    for (auto ptr : sam.all_nodes) {
        if(ptr->link == NULL)
            continue;
        g[ptr->link->id].emplace_back(ptr->id);
        // printf("%d --> %d| %d, %d\n", ptr->link->id, ptr->id, ptr->link->len, ptr->len);
    }
    dfs1(0, 0, g);
    dfs2(0, g, 0);

    // printf("seq:");
    // for (int i = 0; i <= dfn_tot; ++i)
    //     printf("%d ", seq[i]);
    // printf("\n");

    // for (int i = 1; i <= n; ++i)
    //     printf("sp:%d\n", sp[i]);

    Segtree tree(0, tot + 10, n + 10);
    for (int i = 1; i <= n; ++i) {
        int x = sp[i];
        tree.add(i - 1, i, dfn[x], 1, -(i - 1));
        // printf("tree add [%d], %d, %d\n", dfn[x], 1, -(i - 1));
        // tree.print(i);
    }

    int Q;scanf("%d", &Q);
    while(Q--) {
        // printf("--------------new query--------------\n");
        i64 a, b;scanf("%lld%lld", &a, &b);
        veci ed;
        for (int rr = 1; rr <= a; ++rr) {
            scanf("%s", s + 1);
            int len = strlen(s + 1);
            auto ptr = sam.root;
            for (int i = 1; i <= len; ++i) {
                ptr = ptr->next[s[i]];
                if(ptr == NULL)
                    break;
                ed.emplace_back(ptr->id);
                // printf("add %d\n", ptr->id);
            }
        }

        int l = 1, r = n + 1;
        while(l < r) {
            int mid = ((l + r) >> 1);
            i64 sum = 0;
            for (auto x : ed) {
                auto pr = tree.query(mid, dfn[x], trr[x]);
                sum += pr.first * mid + pr.second;
                // printf("check [%d, %d] {%lld %lld}\n", dfn[x], trr[x], pr.first, pr.second);
            }
            // printf("check(%d), sum = %lld\n", mid, sum);
            if(sum >= b)
                r = mid;
            else
                l = mid + 1;
        }
        if(l > n)
            printf("-1\n");
        else
            printf("%d\n", l);
    }
    


    return 0;
}