#include <cstdio>
#include <cstring>
#include <vector>

typedef long long i64;

struct Trie {
    struct Node {
        int cnt;
        Node *son[2];
        Node():cnt(),son{NULL, NULL} {}
    };
    Node *root;
    Trie() {
        root = new Node;
    }
    void add(i64 x) {
        Node *cur = root;
        ++cur->cnt;
        for(i64 i=30;i>=0;--i) {
            int v = ((x >> i) & 1);
            if(cur->son[v] == NULL) {
                cur->son[v] = new Node;
            }
            cur = cur->son[v];
            ++cur->cnt;
        }
    }
    void del(i64 x) {
        Node *cur = root;
        --cur->cnt;
        for(i64 i=30;i>=0;--i) {
            int v = ((x >> i) & 1);
            // if(cur->son[v] == NULL) {
            //     cur->son[v] = new Node;
            // }
            cur = cur->son[v];
            --cur->cnt;
        }
    }
    i64 getmax(i64 x) {
        i64 ans = 0;
        Node *cur = root;
        for(i64 i=30;i>=0;--i) {
            int v = ((x >> i) & 1);
            if(cur->son[!v]!=NULL && cur->son[!v]->cnt) {
                ans = ((ans << 1) | 1);
                cur = cur->son[!v];
            } else {
                ans = ((ans << 1) | 0);
                cur = cur->son[v];
            }
        }
        return ans;
    }
};

typedef std::vector<std::vector<std::pair<int, int> > > Graph;

int val[100010];

void dfs(int x, int faa, int cur, Graph& g) {
    val[x] = cur;
    for(auto [y, z]:g[x]) {
        if(y == faa)continue;
        dfs(y, x, cur^z, g);
    }
}

int main() {
    int n;scanf("%d", &n);
    Graph g(n+2);
    for(int i=1;i<n;++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    dfs(1, 0, 0, g);
    Trie trie;
    trie.add(val[1]);
    i64 ans = 0;
    for(int i=2;i<=n;++i) {
        ans = std::max(ans, trie.getmax(val[i]));
        trie.add(val[i]);
    }
    printf("%lld\n", ans);

    return 0;
}