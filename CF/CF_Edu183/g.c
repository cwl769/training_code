#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long int64;

long long read()
{
    long long x = 0, f = 1;
    long long c = getchar();
    while (c > '9' || c < '0')
    {
        if (c == '-')
            f = -f;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    return x * f;
}

int main() {
    int64 T = read();
    for(;T;--T) {
        int64 l, r;l = read();r = read();
        int64 len = r - l + 1;
        int64 ans = 0;
        for(int64 t=0;t<=60;++t) {
            int64 cur = (1ll<<t);
            if(cur < len)
                ans |= cur;
            else {
                if((l & cur) || (r & cur)) {
                    ans |= cur;
                }
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}