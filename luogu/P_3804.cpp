#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
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

char str[1000010];
typedef std::vector<veci> Graph;

void dfs(int x, const Graph& g, veci64 &occ, veci64 &len, i64 &ans) {
    for(auto y:g[x]) {
        // printf("%d -> %d\n", x, y);
        dfs(y, g, occ, len, ans);
        occ[x] += occ[y];
    }
    // printf("[%d] %lld %lld\n", x, occ[x], len[x]);
    if(occ[x] > 1)
        ans = std::max(ans, occ[x] * len[x]);
}

void solve() {
    scanf("%s", str + 1);
    int n = strlen(str + 1);
    i64 ans = 0;
    SAM sam;
    std::vector<SAM::Node*> node;
    for (int i = 1; i <= n; ++i) {
        node.emplace_back(sam.append(str[i] - 'a'));
    }
    Graph g(cnt+2);
    for(auto p : sam.all_nodes) {
        // printf("node #%d {\n", p->id);
        // printf("    len: %d\n", p->len);
        // printf("    next:\n");
        // for(auto pr : p->next) {
        //     printf("        %d --%c--> %d\n", p->id, pr.first+'a', pr.second->id);
        // }
        // printf("}\n");
        if(p->link == NULL)
            continue;
        // printf("                            link: %d -> %d\n", p->id, p->link->id);
        g[p->link->id].emplace_back(p->id);
    }
    veci64 occ(cnt + 2), len(cnt + 2);
    for(auto p : node) {
        occ[p->id] = 1;
    }
    for(auto p : sam.all_nodes) {
        len[p->id] = p->len;
    }

    dfs(0, g, occ, len, ans);

    // for(auto p : node) {
    //     printf("%d ", p->id);
    // }
    // printf("\n");

    printf("%lld\n", ans);
}

int main() {
    //printf("%lu\n", sizeof(std::vector<int>));
    //int T;readInt(T);
    //while(T--) {
        solve();
    //}

    return 0;
}
