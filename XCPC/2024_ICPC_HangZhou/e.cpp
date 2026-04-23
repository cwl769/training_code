#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#define itn int

typedef long long int64;
typedef long long i64;
typedef unsigned long long ui64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;


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

struct Range {
    int id;
    i64 l, r;
};

void solve() {
    itn n;i64 f;readInt(n, f);
    std::vector<Range> a(n);
    for(int i=0;i<n;++i) {
        a[i].id = i + 1;
        readInt(a[i].l, a[i].r);
    }
    std::vector<Range> ori;
    ori.push_back({0, 0, 0});
    for(auto x:a)
        ori.push_back(x);
    std::sort(a.begin(), a.end(), [](Range a, Range b)->bool {
        if(a.l == b.l)
            return a.r > b.r;
        return a.l < b.l;
    });
    std::vector<Range> sp;
    for(i64 i=0,r=LLONG_MIN;i<n;++i) {
        if(r < a[i].l) {
            sp.push_back(a[i]);
            r = a[i].r;
        } else if(a[i].r > r) {
            sp.push_back(a[i]);
            r = a[i].r;
        }
    }
    std::vector<bool> vis(n+1);
    i64 ans = 0;
    veci ansv;
    for(int i=0;i<(int)sp.size();++i) {
        if(f <= sp[i].l) {
            if(i == 0 || f > sp[i-1].r) {
                ans += sp[i].l - f;
                ansv.push_back(sp[i].id);
                vis[sp[i].id] = 1;
                for(int j=i+1;j<(int)sp.size();++j) {
                    ansv.push_back(sp[j].id);
                    vis[sp[j].id] = 1;
                    if(sp[j].l > sp[j-1].r)
                        ans += sp[j].l - sp[j-1].r;
                }
            } else {
                ansv.push_back(sp[i-1].id);
                vis[sp[i-1].id] = 1;
                for(int j=i;j<(int)sp.size();++j) {
                    ansv.push_back(sp[j].id);
                    vis[sp[j].id] = 1;
                    if(sp[j].l > sp[j-1].r)
                        ans += sp[j].l - sp[j-1].r;
                }
            }
            break;
        }        
    }
    if(ansv.size() == 0u) {
        ansv.push_back(sp.back().id);
        vis[sp.back().id] = 1;
    }
    std::sort(a.begin(), a.end(), [](Range a, Range b)->bool {
        return a.r > b.r;
    });
    for(auto rg:a) {
        ans += rg.r - rg.l;
        if(!vis[rg.id])
            ansv.push_back(rg.id);
    }
    printf("%lld\n", ans);
    for(auto x:ansv)
        printf("%d ", x);
    printf("\n");

    
    // for(auto x:sp) {
    //     printf("{%d, %lld, %lld}\n", x.id, x.l, x.r);
    // }

    // i64 tmp = 0;
    // for(auto rg:a) {
    //     tmp += rg.r - rg.l;
    // }
    // if(f < ori[ansv[0]].l)
    //     tmp += ori[ansv[0]].l - f;
    // for(int i=1;i<n;++i) {
    //     if(ori[ansv[i]].l > ori[ansv[i-1]].r)
    //         tmp += ori[ansv[i]].l - ori[ansv[i-1]].r;
    // }
    // printf("tmp:%lld\n", tmp);
    // assert(tmp == ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}