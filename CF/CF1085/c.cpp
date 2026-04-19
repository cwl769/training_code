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
    int l, r;
    int64 h;
    int64 tl, tr;
    // Node():l(),r(),h(),tl(),tr(){}
};

int main() {
    int T;readInt(T);
    while(T--) {
        int n, h;readInt(n, h);
        std::vector<int> a(n);
        for(int i=0;i<n;++i)
            readInt(a[i]);
        std::map<int, std::vector<int> > map;
        for(int i=0;i<n;++i) {
            map[a[i]].push_back(i);
        }
        std::vector<int> hs;
        for(auto pr:map) {
            hs.push_back(pr.first);
        }
        hs.push_back(h+1);
        std::vector<Node> nd[2];
        std::vector<bool> vis(n+1);
        int64 ans = 0;
        for(int t=0;hs[t]!=h+1;++t) {
            std::vector<Node>& cur = nd[t&1];
            std::vector<Node>& last = nd[(t&1)^1];
            cur.clear();
            int64 curh = hs[t+1] - hs[t];
            for(auto x:map[hs[t]]) {
                vis[x] = 1;
            }
            int l = 0, r=0;
            for(int i=0;i<=n;++i) {
                if(vis[i]) {
                    if(i==0 || !vis[i-1]) {
                        l = i;
                    }
                } else {
                    if(i>0 && vis[i-1]) {
                        r = l-1;
                        cur.push_back((Node){
                            .l = l,
                            .r = r,
                            .h = curh,
                            .tl = 1ll * (r-l+1) * h,
                            .tr = 1ll * (r-l+1) * h
                        });
                    }
                }
            }
            if(cur[0].l==0 && cur[0].r==n-1) {
                if(last.size()==1u) {
                    
                } else {

                }
                break;
            }
            int it = 0;
            for(int i=0;i<(int)cur.size();++i) {
                int len = r - l + 1;
                while(it < (int)last.size() && cur[i].l <= last[it].l && last[it].r <= cur[i].r) {
                    if(curh&1) {
                        cur[i].tl = std::max(cur[i].tl, 1ll * len * curh - (cur[i].r - last[it].r) + last[it].tr);
                        cur[i].tr = std::max(cur[i].tr, 1ll * len * curh - (last[it].l - cur[i].l) + last[it].tl);
                    } else {
                        cur[i].tl = std::max(cur[i].tl, 1ll * len * curh - (last[it].l - cur[i].l) + last[it].tl);
                        cur[i].tr = std::max(cur[i].tr, 1ll * len * curh - (cur[i].r - last[it].r) + last[it].tr);
                    }

                    ++it;
                }
            }
        }
    }

    return 0;
}