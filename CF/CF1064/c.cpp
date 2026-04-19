#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
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
    int v;
    bool del;
    Node *pre, *nxt;
};

void print(Node *p, Node *st, bool first=0) {
    if(p==st&&!first) return;
    printf("%d ", p->v);
    print(p->pre, st);
}

void erase(Node *x) {
    if(x==x->pre || x==x->nxt)
        return;
    // printf("erase %p\n", x);
    x->del = true;
    x->pre->nxt = x->nxt;
    x->nxt->pre = x->pre;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i) {
            readInt(a[i]);
        }
        std::vector<Node*> nd(n+1);
        for(int i=1;i<=n;++i) {
            nd[i] = new Node;
            nd[i]->v = a[i];
            nd[i]->del = false;
        }
        for(int i=2;i<=n;++i)
            nd[i]->pre = nd[i-1];
        nd[1]->pre = nd[n];
        for(int i=1;i<n;++i)
            nd[i]->nxt = nd[i+1];
        nd[n]->nxt = nd[1];
        // print(nd[1], nd[1], 1);
        // printf("\n");
        std::map<int, std::vector<Node*> > map;
        for(int i=1;i<=n;++i) {
            map[a[i]].push_back(nd[i]);
        }
        int64 ans = 0;
        for(auto &x:map) {
            for(auto p:x.second) {
                // printf("%d %x\n", x.first, p);
                // printf("p %d %d %d\n", p->pre->v, p->v, p->nxt->v);
                while(!p->del && p->pre->v <= p->v && p->pre != p) {
                    erase(p->pre);
                    ans += p->v;
                    // print(p, p, 1);printf("\n");
                }

                while(!p->del && p->nxt->v <= p->v && p->nxt != p) {
                    erase(p->nxt);
                    ans += p->v;
                    // print(p, p, 1);printf("\n");
                }
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}