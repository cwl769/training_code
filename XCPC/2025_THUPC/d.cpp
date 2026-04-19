#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

template<typename T>
void readInt(T& x) {
    bool f = 0;
    x = 0;
    char c = getchar();
    for(;c<'0'||c>'9';c=getchar()){if(c=='-')f=!f;}
    for(;'0'<=c&&c<='9';c=getchar())
        x = x * 10 + (c - '0');
    if(f)x = -x;
}

template<typename T, typename ...ARGS>
void readInt(T& x, ARGS&... args) {
    readInt(x);
    readInt(args...);
}

struct Data {
    int v, u, id;
};

bool cmp(const Data& a, const Data& b) {
    if(a.v == b.v) {
        if(a.u == b.u) {
            return a.id < b.id;
        }
        return a.u > b.u;
    }
    return a.v > b.v;
}

int main() {
    int n, h;readInt(n, h);
    std::vector<int> u(n+1);
    for(int i=1;i<=n;++i)
        readInt(u[i]);
    std::vector< Data > tmp;
    for(int i=1;i<=n;++i) {
        for(int t=u[i];t;t>>=1) {
            tmp.push_back((Data){
                .v = t,
                .u = u[i],
                .id = i,
            });
        }
    }
    std::sort(tmp.begin(), tmp.end(), cmp);
    std::vector<int> ans(n+1);
    for(auto beg=tmp.begin();beg!=tmp.end();) {
        auto end = beg;
        while(end!=tmp.end() && end->v == beg->v) {
            ++end;
        }
        std::vector<bool> vis(end - beg);
        for(auto it=beg;it!=end;++it) {
            if(ans[it->id] == 0) {
                if(h) {
                    --h;
                    ++ans[it->id];
                    vis[it - beg] = 1;
                } else break;
            }
        }
        if(h==0)break;
        for(auto it=beg;it!=end;++it) {
            if(!vis[it-beg]) {
                if(h) {
                    --h;
                    ++ans[it->id];
                } else break;
            }
        }
        if(h==0)break;
        beg = end;
    }

    for(int i=1;i<=n;++i) {
        if(ans[i]==0 && h) {
            --h;
            ++ans[i];
        }
    }

    int mxi = 0;
    for(int i=1;i<=n;++i)
        if(u[i] > u[mxi])
            mxi = i;
    ans[mxi] += h;

    for(int i=1;i<=n;++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}