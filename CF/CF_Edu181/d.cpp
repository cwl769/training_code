#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <vector>
#include <algorithm>

const uint64_t p = 998244353;

uint64_t pow(uint64_t a, uint64_t b)
{
    uint64_t base = a, ans = 1llu;
    for(;b;b>>=1)
    {
        if(b&1)ans = ans * base % p;
        base = base * base % p;
    }
    return ans;
}

struct line
{
    int l, r;
    uint64_t pg, ng;
};

bool cmp(line a, line b)
{
    return a.r < b.r;
}

uint64_t ans[200010];

int main()
{
    int n, m;scanf("%d%d", &n, &m);
    std::vector<line> vec;
    for(int i=1;i<=n;++i) {
        int l, r;uint64_t x, y;
        scanf("%d%d%llu%llu", &l, &r, &x, &y);
        vec.push_back({l, r, x*pow(y, p-2)%p, (y-x)*pow(y, p-2)%p});
        // printf("%d %d, %llu %llu\n", vec.back().l, vec.back().r, vec.back().pg, vec.back().ng);
    }
    std::sort(vec.begin(), vec.end(), cmp);
    ans[0] = 1;
    for(auto it=vec.begin();it!=vec.end();++it) {
        ans[0] = ans[0] * it->ng % p;
    }
    for(auto it=vec.begin();it!=vec.end();++it) {
        ans[it->r] = (ans[it->r] + ((ans[it->l-1] * pow(it->ng, p-2) % p) * it->pg % p))%p;
    }
    // for(int i=0;i<=m;++i)
    //     printf("%llu ", ans[i]);
    // printf("\n");
    printf("%llu", ans[m]);

    return 0;
}