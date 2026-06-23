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
#include <queue>

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

struct acam {
    struct Node {
        int id;
        Node *fail;
        Node *son[26];
        Node() {
            id = 0;
            fail = NULL;
            for(int i=0;i<26;++i)
                son[i] = NULL;
        }
    };
    Node *root;
    acam() {
        root = new Node;
    }
    void add(int id, const char *str) {
        Node *cur = root;
        for(;*str!='\0';++str) {
            char c = *str - 'a';
            if(cur->son[c]==NULL)
                cur->son[c] = new Node;
            cur = cur->son[c];
        }
        cur->id = id;
    }
    void make_fail() {
        std::queue<Node*> q;
        root->fail = root;
        for(int c=0;c<26;++c) {
            if(root->son[c] == NULL) {
                root->son[c] = root;
            } else {
                q.push(root->son[c]);
                root->son[c]->fail = root;
            }
        }
        while(q.size()) {
            Node *cur = q.front();
            q.pop();
            for(int c=0;c<26;++c) {
                if(cur->son[c] == NULL) {
                    cur->son[c] = cur->fail->son[c];
                } else {
                    cur->son[c]->fail = cur->fail->son[c];
                    q.push(cur->son[c]);
                }
            }
        }
    }
};
typedef acam::Node Node;

char tmp[200010];
char str[200010];

void solve() {
    int n;readInt(n);
    acam acam;
    for(int i=1;i<=n;++i) {
        scanf("%s", tmp);
        acam.add(i, tmp);
    }
    acam.make_fail();
    scanf("%s", str+1);
    int len = strlen(str+1);
    Node *cur = acam.root;

    std::vector<int> ans(n+2);
    for(int i=1;i<=len;++i) {
        char c = str[i] - 'a';
        cur = cur->son[c];
        ++ans[cur->id];
    }
    for(int i=1;i<=n;++i)
        printf("%d\n", ans[i]);
    
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}