#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint>

bool set[220];
uint64_t sum[220];

int main()
{
    for(int i=1;i*2<=210;++i)
        set[i*2] = 1;
    for(int i=1;i*3<=210;++i)
        set[i*3] = 1;
    for(int i=1;i*5<=210;++i)
        set[i*5] = 1;
    for(int i=1;i*7<=210;++i)
        set[i*7] = 1;
    uint64_t cnt = 0;
    for(int i=1;i<=210;++i)
        if(!set[i])
            ++cnt;
    for(int i=1;i<=210;++i) {
        if(!set[i])
            sum[i] = sum[i-1] + 1;
        else
            sum[i] = sum[i-1];
    }

    for(int i=1;i<=210;++i)
        fprintf(stderr, "sum[%d] = %llu\n", i, sum[i]);
    // sum[0] = sum[210];
    int T;scanf("%d", &T);
    for(;T;--T) {
        uint64_t l, r;scanf("%llu%llu", &l, &r);
        uint64_t ll = (l - 1llu) / 210;
        uint64_t rr = (r - 1llu) / 210;

        fprintf(stderr, "[%llu, %llu]%llu, %llu\n", ll, rr, l, r);
        if(ll == rr) {
            printf("%llu\n", sum[r - rr*210llu] - sum[l - ll*210llu - 1llu]);
        } else {
            printf("%llu\n", (rr - ll - 1llu) * cnt + sum[r - rr*210llu] + (sum[210llu] - sum[l - ll*210llu - 1llu]) );
        }
    }

    return 0;
}