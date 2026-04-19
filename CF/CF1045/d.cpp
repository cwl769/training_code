#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>
#include <forward_list>

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

template<typename T>
class Graph {
public:
    class Edge {
    public:
        Edge* next;
        int to;
        T val;
        Edge(Edge*_next, int _to, T _val):next(_next),to(_to),val(_val){}
    };
    class Iterator {
    private:
        Edge* ptr;
    public:
        Iterator(Edge *p):ptr(p){}
        Iterator& operator ++() {
            ptr = ptr->next;
            return *this;
        }
        const Iterator operator ++(int) {
            Edge * tmp = ptr;
            ptr = ptr->next;
            return tmp;
        }
        Edge& operator *() const {
            return *ptr;
        }
        bool operator != (const Iterator& b) {
            return this->ptr != b.ptr;
        }
    };
    class Edge_set {
    public:
        Edge *start;
        Edge_set():start(NULL){}
        Iterator begin(){
            return start;
        }
        Iterator end(){
            return NULL;
        }
    };
    Graph(int N):h(N) {}
    void add_edge(int x, int y, T v) {
        edg.push_front(Edge(h[x].start, y, v));
        h[x].start = &edg.front();
    }
    Edge_set operator () (int x) {
        return h[x];
    }
private:
    std::forward_list<Edge> edg;
    std::vector<Edge_set> h;
};

typedef std::vector<int> Vec;

void dfs(int x, int f, Graph<int>& G, Vec& fa, Vec& siz, Vec& g, Vec& mxss, Vec& p) {
    printf("dfs to %d\n", x);
    
    fa[x] = f;
    siz[x] = 1;
    g[x] = 0;
    mxss[x] = 0;
    int secmxss = 0;
    for(auto edg:G(x)) {
        int y = edg.to;
        if(y==f)continue;
        dfs(y, x, G, fa, siz, g, mxss, p);
        siz[x] += siz[y];
        g[x] += g[y];
        if(siz[mxss[x]] < siz[y]){
            secmxss = mxss[x];
            mxss[x] = y;
        } else if (siz[secmxss] < siz[y]) {
            secmxss = y;
        }

    }
    g[x] += siz[x] - 1;
    g[x] -= siz[mxss[x]];
    for(auto edg:G(x)) {
        int y = edg.to;
        if(y==f)continue;
        if(y==mxss[x])
            p[y] = siz[secmxss];
        else
            p[y] = siz[mxss[x]];
    }
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        Graph<int> G(n+1);
        for(int i=1;i<n;++i) {
            int x, y;readInt(x, y);
            G.add_edge(x, y, 1);
            G.add_edge(y, x, 1);
        }
        Vec fa(n+1), siz(n+1), f(n+1), g(n+1), h(n+1), mxss(n+1), p(n+1);
        dfs(1, 0, G, fa, siz, g, mxss, p);
        for(int i=1;i<=n;++i) {
            printf("fa[%d] = %d\n", i, fa[i]);
        }
        for(int i=1;i<=n;++i) {
            printf("siz[%d] = %d\n", i, siz[i]);
        }
        for(int i=1;i<=n;++i) {
            printf("g[%d] = %d\n", i, g[i]);
        }
        for(int i=1;i<=n;++i) {
            printf("mxss[%d] = %d\n", i, mxss[i]);
        }
        for(int i=1;i<=n;++i) {
            printf("p[%d] = %d\n", i, p[i]);
        }
    }

    return 0;
}