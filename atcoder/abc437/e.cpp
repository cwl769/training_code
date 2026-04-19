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

struct Node {
    std::vector<int> ind;
    std::map<int, Node*> p;
};

void dfs(Node *nd) {
    for(auto x:nd->ind)
        printf("%d ", x);
    for(auto it:nd->p) {
        dfs(it.second);
    }
}

int main() {
    int n;readInt(n);
    std::vector<Node*> nd(n+1);
    nd[0] = new Node;
    for(int i=1;i<=n;++i) {
        int x, y;readInt(x, y);
        auto it = nd[x]->p.find(y);
        if(it!=nd[x]->p.end()) {
            nd[i] = nd[x]->p[y];
        } else {
            nd[i] = new Node;
            nd[x]->p[y] = nd[i];
        }
        nd[i]->ind.push_back(i);
    }
    dfs(nd[0]);
    printf("\n");

    return 0;
}