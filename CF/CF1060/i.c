#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long int64;

int64 t(int64);

int main()
{
    int64 n;
    scanf("%lld",&n);
    printf("%lld",t(n));
    return 0;
}

int64 t(int64 n)
{
    if(n==0)return 0;
    for(int64 i=1;;i++)
    {
        if((1ll<<(i-1)) <= n && n < (1ll<<i)) {
            return t(n-(1<<(i-1))) + i;
        }
    }
}