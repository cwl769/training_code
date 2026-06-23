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
        int len;
        Node *fail;
        Node *son[26];
        Node() {
            len = 0;
            fail = NULL;
            for(int i=0;i<26;++i)
                son[i] = NULL;
        }
    };
    Node *root;
    acam() {
        root = new Node;
    }
    void add(const char *str) {
        Node *cur = root;
        int len = 0;
        for(;*str!='\0';++str) {
            ++len;
            char c = *str - 'a';
            if(cur->son[c]==NULL)
                cur->son[c] = new Node;
            cur = cur->son[c];
        }
        cur->len = len;
        // printf("add [] len = %d\n", len);
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

#include <stack>

char str[100010];
char tmp[100010];
typedef acam::Node Node;
Node *sta[100010];

void solve() {
    scanf("%s", str+1);
    int n;readInt(n);
    acam acam;
    for(int i=0;i<n;++i) {
        scanf("%s", tmp);
        acam.add(tmp);
    }
    acam.make_fail();
    int len = strlen(str+1);
    std::stack<std::pair<char, Node*> > ans;
    ans.emplace('\0', acam.root);
    for(int i=1;i<=len;++i) {
        char c = str[i] - 'a';
        Node *cur = ans.top().second->son[c];
        ans.emplace(str[i], cur);
        if(cur->len) {
            for(int j=0;j<cur->len;++j)
                ans.pop();
        }
    }
    len = ans.size() - 1;
    str[len+1] = '\0';
    for(int i=len;i>=1;--i) {
        str[i] = ans.top().first;
        ans.pop();
    }
    printf("%s\n", str+1);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}