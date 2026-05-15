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

struct Node {
    int size;
    Node *son[2];
    Node():size(0),son{NULL, NULL}{}
};

void dfs(Node *p, int dep, const int m) {
    if(dep == m)
        return;
    if(p->son[0])
        dfs(p->son[0], dep+1, m);
    if(p->son[1])
        dfs(p->son[1], dep+1, m);
    p->size = 0;
    if(p->son[0])p->size += p->son[0]->size;
    if(p->son[1])p->size += p->son[1]->size;
}

char str[110];

void solve() {
    int n, m;readInt(n, m);
    if(m < 20 && n == (1<<m)) {
        printf("No\n");
        return;
    }
    Node *root = new Node;
    for(int i=1;i<=n;++i) {
        scanf("%s", str+1);
        Node *cur = root;
        for(int j=1;j<=m;++j) {
            int ch = str[j] - '0';
            if(cur->son[ch] == NULL)
                cur->son[ch] = new Node;
            cur = cur->son[ch];
        }
        ++cur->size;
    }
    printf("Yes\n");
    dfs(root, 0, m);
    Node *cur = root;
    for(int t=1;t<=m;++t) {
        if(cur == NULL) {
            putchar('0');
            continue;
        }
        int s0 = ((cur->son[0]==NULL)?0:cur->son[0]->size);
        int s1 = ((cur->son[1]==NULL)?0:cur->son[1]->size);
        // printf("[%d]%d %d\n", t, s0, s1);
        if(s0 <= s1) {
            putchar('1');
            cur = cur->son[0];
        } else {
            putchar('0');
            cur = cur->son[1];
        }
    }
    printf("\n");
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}