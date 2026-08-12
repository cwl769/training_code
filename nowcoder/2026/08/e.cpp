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
typedef std::vector<veci> Graph;


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

const i64 MOD = 998244353;

char str[500010], prh[500010];

void dfs1(int x, const Graph& g, veci& endid, veci& ans) {
    if(endid[x])
        ans.emplace_back(endid[x]);
    for(auto y : g[x]) {
        dfs1(y, g, endid, ans);
    }
}

int dfs2(int x, const Graph& g, veci& lim, veci64& val, veci& lenl, veci& lenr) {
    int cur = lim[x];
    for(auto y : g[x]) {
        int sonlim = dfs2(y, g, lim, val, lenl, lenr);
        if(sonlim == -1)
            continue;
        if(cur == -1)
            cur = sonlim;
        else
            cur = std::min(cur, sonlim);
    }

    // printf("dfs2 [%d] %d\n", x, cur);

    if(cur == -1)
        return cur;

    if(cur <= lenl[x]) {
        val[x] = 0;
    } else if(cur <= lenr[x]) {
        val[x] = cur - lenl[x];
    }

    return cur;
}

void dfs3(int x, const Graph& g, veci64 &val, veci64 &dp) {
    dp[x] = 1;
    for(auto y : g[x]) {
        dfs3(y, g, val, dp);
        dp[x] = dp[x] * (dp[y] + 1ll) % MOD;
    }
    dp[x] = (dp[x] - 1 + MOD) % MOD;
    dp[x] = (dp[x] + val[x]) % MOD;
}

int main() {
    scanf("%s", str + 1);
    scanf("%s", prh + 1);
    int n = strlen(str + 1);
    int m = strlen(prh + 1);
    for(int i = 1; i <= n; ++i) {
        int j = n - i + 1;
        if(i < j)
            std::swap(str[i], str[j]);
        else
            break;
    }
    for(int i = 1; i <= m; ++i) {
        int j = m - i + 1;
        if(i < j)
            std::swap(prh[i], prh[j]);
        else
            break;
    }
    // printf("%s\n%s\n", str + 1, prh + 1);

    std::vector<SAM::Node*> node(n + 2);
    SAM sam;
    for(int i = 1; i <= n; ++i) {
        node[i] = sam.append(str[i]);
    }

    veci64 val(tot + 2);
    veci lenl(tot + 2), lenr(tot + 2);
    for(auto nd : sam.all_nodes) {
        if(nd->id == 0)
            continue;
        int l = nd->link->len + 1;
        int r = nd->len;
        val[nd->id] = r - l + 1;
        lenl[nd->id] = l;
        lenr[nd->id] = r;
    }

    auto prh_ptr = sam.root;
    for(int i = 1; i <= m; ++i) {
        auto it = prh_ptr->next.find(prh[i]);
        if(it != prh_ptr->next.end()) {
            prh_ptr = it->second;
        } else {
            prh_ptr = NULL;
            break;
        }
    }

    veci endid(tot + 2);
    for(int i = 1; i <= n; ++i) {
        endid[node[i]->id] = i;
    }

    Graph g(tot + 2);

    for(auto nd : sam.all_nodes) {
        if(nd->id == 0)
            continue;
        g[nd->link->id].emplace_back(nd->id);
        // printf("%d -> %d\n", nd->link->id, nd->id);
    }

    if(prh_ptr != NULL) {
        veci prh_end;
        int prh_id = prh_ptr->id;
        dfs1(prh_id, g, endid, prh_end);
        // printf("endpos: ");
        // for(auto x : prh_end)
        //     printf("%d ", x);
        // printf("\n");

        veci help(n + 2, -1);
        for(auto x : prh_end) {
            help[x] = x;
        }
        for(int i = 1; i <= n; ++i)
            help[i] = std::max(help[i], help[i - 1]);
        
        veci lim(tot + 2, -1);
        for(int i = 1; i <= n; ++i) {
            if(help[i] != -1) {
                lim[node[i]->id] = i - help[i] + m;
            }
        }

        dfs2(0, g, lim, val, lenl, lenr);
    }

    // for(int i = 0; i <= tot; ++i) {
    //     printf("[%d] %lld [%d, %d]\n", i, val[i], lenl[i], lenr[i]);
    // }

    veci64 dp(tot + 2);
    dfs3(0, g, val, dp);
    printf("%lld\n", dp[0]);


    return 0;
}