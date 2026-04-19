#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint>

uint64_t gcd(uint64_t a, uint64_t b) {
    if(b==0llu)return a;
    return gcd(b, a%b);
}

int main()
{
    int T;scanf("%d", &T);
    for(;T;--T) {
        uint64_t a, b, k;scanf("%llu%llu%llu", &a, &b, &k);
        uint64_t g = gcd(a, b);
        if(a / g <= k && b / g <= k)printf("1\n");
        else printf("2\n");
    }

    return 0;
}