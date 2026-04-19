#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

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

typedef std::vector<int> Vec;
typedef std::vector<std::vector<int> > Graph;
#define reset_vec(vec, siz) do { \
    vec.clear();            \
    vec.resize(siz);        \
} while(0)

Graph g;
Vec a, b, fa, siz, hs, seq, dfn, R;
Vec cnta, cntb, diff;
int needa = 0, needb = 0;
Vec ans;

void dfs_msg(int x) {
    dfn[x] = seq.size();
    seq.push_back(x);
    siz[x] = 1;
    hs[x] = 0;
    R[x] = dfn[x];
    for(int y:g[x]) {
        if(y==fa[x])continue;
        fa[y] = x;
        dfs_msg(y);
        siz[x] += siz[y];
        if(siz[y] > siz[hs[x]])
            hs[x] = y;
        R[x] = R[y];
    }
}

void add(int x) {
    if(a[x]) {
        if(cnta[a[x]]<cntb[a[x]]) {
            needa -= cntb[a[x]] - cnta[a[x]];
        } else {
            needb -= cnta[a[x]] - cntb[a[x]];
        }
        ++cnta[a[x]];
        if(cnta[a[x]]<cntb[a[x]]) {
            needa += cntb[a[x]] - cnta[a[x]];
        } else {
            needb += cnta[a[x]] - cntb[a[x]];
        }
    } else {++cnta[0];}
    if(b[x]) {
        if(cnta[b[x]]<cntb[b[x]]) {
            needa -= cntb[b[x]] - cnta[b[x]];
        } else {
            needb -= cnta[b[x]] - cntb[b[x]];
        }
        ++cntb[b[x]];
        if(cnta[b[x]]<cntb[b[x]]) {
            needa += cntb[b[x]] - cnta[b[x]];
        } else {
            needb += cnta[b[x]] - cntb[b[x]];
        }
    } else {++cntb[0];}
}
void del(int x) {
    if(a[x]) {
        if(cnta[a[x]]<cntb[a[x]]) {
            needa -= cntb[a[x]] - cnta[a[x]];
        } else {
            needb -= cnta[a[x]] - cntb[a[x]];
        }
        --cnta[a[x]];
        if(cnta[a[x]]<cntb[a[x]]) {
            needa += cntb[a[x]] - cnta[a[x]];
        } else {
            needb += cnta[a[x]] - cntb[a[x]];
        }
    } else {--cnta[0];}
    if(b[x]) {
        if(cnta[b[x]]<cntb[b[x]]) {
            needa -= cntb[b[x]] - cnta[b[x]];
        } else {
            needb -= cnta[b[x]] - cntb[b[x]];
        }
        --cntb[b[x]];
        if(cnta[b[x]]<cntb[b[x]]) {
            needa += cntb[b[x]] - cnta[b[x]];
        } else {
            needb += cnta[b[x]] - cntb[b[x]];
        }
    } else {--cntb[0];}
}

void dfs(int x, bool keep) {
    for(auto y:g[x]) {
        if(y==fa[x])continue;
        if(y==hs[x])continue;
        dfs(y, false);
    }
    if(hs[x])
        dfs(hs[x], true);
    for(auto y:g[x]) {
        if(y==fa[x])continue;
        if(y==hs[x])continue;
        for(int i=dfn[y];i<=R[y];++i) {
            add(seq[i]);
        }
    }

    add(x);
    //cal ans
    ans[x] = (int)(needa <= cnta[0] && needb <= cntb[0]);

    if(!keep) {
        for(int i=dfn[x];i<=R[x];++i) {
            del(seq[i]);
        }
    }
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        reset_vec(a, n+1);
        reset_vec(b, n+1);
        for(int i=1;i<=n;++i) {
            readInt(a[i]);
        }
        for(int i=1;i<=n;++i) {
            readInt(b[i]);
        }
        reset_vec(g, n+1);
        for(int i=1;i<n;++i) {
            int x, y;readInt(x, y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        reset_vec(fa, n+1);
        reset_vec(siz, n+1);
        reset_vec(hs, n+1);
        reset_vec(seq, 1);
        reset_vec(dfn, n+1);
        reset_vec(R, n+1);
        reset_vec(ans, n+1);
        dfs_msg(1);
        reset_vec(cnta, n+1);
        reset_vec(cntb, n+1);
        reset_vec(diff, n+1);
        needa = needb = 0;
        dfs(1, 0);
        for(int i=1;i<=n;++i)
            printf("%d", ans[i]);
        printf("\n");
    }

    return 0;
}