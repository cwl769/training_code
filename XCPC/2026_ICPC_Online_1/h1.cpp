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

typedef std::vector<veci> Graph;

char s[200010], t[200010];

void dfs(int x, const Graph& g, veci64 &ed, veci64 &cnt, i64 cur, i64 &ans) {
    cur += cnt[x];
    ans += cur * ed[x];
    for (auto y : g[x]) {
        dfs(y, g, ed, cnt, cur, ans);
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
    }

    int Q;scanf("%d", &Q);
    while(Q--) {
        printf("--------------new query--------------\n");
        i64 a, b;scanf("%lld%lld", &a, &b);
        veci64 cnt(tot + 2);
        for (int rr = 1; rr <= a; ++rr) {
            scanf("%s", s + 1);
            int len = strlen(s + 1);
            auto ptr = sam.root;
            for (int i = 1; i <= len; ++i) {
                ptr = ptr->next[s[i]];
                if(ptr == NULL)
                    break;
                cnt[ptr->id]++;
            }
        }
        int l = 1, r = n + 1;
        while(l < r) {
            int mid = ((l + r) >> 1);
            veci64 ed(tot + 2);
            for (int i = 1; i <= mid; ++i)
                ed[sp[i]] = mid - i + 1;
            i64 tmp = 0;
            dfs(0, g, ed, cnt, 0, tmp);
            printf("check(%d), sum = %lld\n", mid, tmp);
            if(tmp >= b)
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