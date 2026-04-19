#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

typedef long long int64;

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

#include <stack>

struct Node {
    std::pair<int, int> val;
    Node *son[2];
    Node(int v1, int v2):val(v1, v2) {
        son[0] = son[1] = NULL;
    }
};

// int cal(Node *ptr) {
//     if(ptr == NULL)return 0;
//     return 1 + cal(ptr->son[0]);
// }

int main() {
    int T;readInt(T);
    while(T--) {
        int n;readInt(n);
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i) {
            readInt(a[i]);
        }
        Node *root = new Node(INT_MAX, INT_MAX);
        std::stack<Node*> stack;
        stack.push(root);
        for(int i=1;i<=n;++i) {
            Node *cur = new Node(a[i], i);
            Node *lson = NULL;
            while(stack.top()->val <= cur->val) {
                lson = stack.top();
                stack.pop();
            }
            stack.top()->son[1] = cur;
            stack.push(cur);
            cur->son[0] = lson;
        }
        Node *p = root->son[1];
        int ans = 0;
        while(p != NULL) {
            ++ans;
            p = p->son[0];
        }
        printf("%d\n", ans);
    }

    return 0;
}