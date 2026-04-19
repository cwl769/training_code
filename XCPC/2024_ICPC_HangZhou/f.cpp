#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>

#define BELONG(x) (((x)-1)/len+1)

typedef std::vector<std::vector<int> > Graph;
typedef long long int64;
typedef long long i64;
typedef unsigned long long ui64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

bool vis[200010];
std::stack<int> stack;
int dfn[200010];
int low[200010];
int tot = 0;

int scc[200010];
int scc_tot = 0;

void tarjan(int x, const Graph& g) {
    dfn[x] = ++tot;
    low[x] = dfn[x];
    stack.push(x);
    vis[x] = 1;
    for(auto y:g[x]) {
        if(dfn[y]) {
            if(vis[y]) {
                low[x] = std::min(low[x], dfn[y]);
            }
        } else {
            tarjan(y, g);
            low[x] = std::min(low[x], low[y]);
        }
    }
    if(dfn[x] == low[x] ) {
        ++scc_tot;
        do {
            int top = stack.top();
            scc[top] = scc_tot;
            vis[top] = 0;
            stack.pop();
            if(top == x)break;
        } while(1);
    }
}

int func(int l, int r, veci& vec) {
    return std::upper_bound(vec.begin(), vec.end(), r) - std::lower_bound(vec.begin(), vec.end(), l);
}

int main() {
    int T;scanf("%d", &T);
    while(T--) {
        int n, k, q;scanf("%d%d%d", &n, &k, &q);
        std::vector<std::vector<int> > p(k+1);
        for(int i=1;i<=k;++i) {
            p[i].resize(n+1);
        }
        for(int i=1;i<=k;++i) {
            for(int j=1;j<=n;++j)
                scanf("%d", &p[i][j]);
        }
        Graph g(n+1);
        for(int i=1;i<=k;++i) {
            for(int j=2;j<=n;++j) {
                g[p[i][j-1]].push_back(p[i][j]);
            }
        }
        for(int i=1;i<=n;++i) {
            dfn[i] = 0;
            vis[i] = 0;
            low[i] = 0;
            tot = 0;
            scc[i] = 0;
            scc_tot = 0;
            while(stack.size())
                stack.pop();
        }
        for(int i=1;i<=n;++i) {
            if(dfn[i] == 0) {
                tarjan(i, g);
            }
        }


        int len = pow(n, 0.5);
        int num = n / len;

        std::vector<std::vector<std::vector<int64> > > sumblk(k+1);
        for(int id=1;id<=k;++id) {
            for(int l=1;l<=num;++l) {
                std::vector<int> cnt(scc_tot+1);
                for(int r=l;r<=num;++r) {
                    sumblk[id][l][r] = sumblk[id][l][r-1];
                    for(int i=len*(r-1)+1;i<=len*r;++i) {
                        sumblk[id][l][r] += cnt[scc[p[id][i]]];
                        ++cnt[scc[p[id][i]]];
                    }
                }
            }
        }


        std::vector<std::vector<std::vector<int> > > pos(k+1);
        for(int id=1;id<=k;++id) {
            pos[id].resize(scc_tot+1);
            for(int i=1;i<=n;++i) {
                pos[id][scc[p[id][i]]].push_back(i);
            }
        }

        int64 lastans = 0;
        while(q--) {
            int _id, _l, _r;
            scanf("%d%d%d", &_id, &_l, &_r);
            int id, l, r;
            id = (_id + lastans) % k + 1;
            l = (_l + lastans) % n + 1;
            r = (_r + lastans) % n + 1;
            if(l > r)
                std::swap(l, r);

            int bl = BELONG(l);
            int br = BELONG(r);
            if(bl == br || bl + 1 == br) {
                int64 ans = 0;
                for(int i=l+1;i<=r;++i) {
                    ans += func(l, i-1, pos[id][scc[p[id][i]]]);
                }
                printf("%lld\n", ans);
                lastans = ans;
            } else {
                int64 ans = sumblk[id][bl+1][br-1];
                for(int i=(br-1)*len+1;i<=r;++i) {
                    ans += func(bl*len+1, i-1, pos[id][scc[p[id][i]]]);
                }
                for(int i=bl*len;i>=l;--i) {
                    ans += func(i+1, r, pos[id][scc[p[id][i]]]);
                }
                printf("%lld\n", ans);
                lastans = ans;
            }
        }
    }


    return 0;
}