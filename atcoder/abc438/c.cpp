#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>

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

// struct Node {
//     int val;
//     Node *pre, *nxt;

//     void add(Node *p, Node *nw) {
//         nw->pre = p;
//         nw->nxt = p->nxt;
//         p->nxt->pre = nw;
//         p->nxt = nw;
//     }
//     void erase(Node *p) {
        
//     }
// };

int main() {
    int n;readInt(n);
    std::vector<int> a(n+1);
    for(int i=1;i<=n;++i) {
        readInt(a[i]);
    }
    std::stack<std::pair<int, int>  > stack;
    for(int i=1;i<=n;++i) {
        int x = a[i];
        if(stack.empty()) {
            stack.push({x, 1});
        } else {
            auto p = stack.top();
            if(p.first == x && p.second == 3) {
                for(int i=1;i<=3;++i)
                    stack.pop();
            } else if(p.first == x) {
                stack.push({x, p.second+1});
            } else {
                stack.push({x, 1});
            }
        }
    }
    printf("%d\n", (int)stack.size());

    return 0;
}