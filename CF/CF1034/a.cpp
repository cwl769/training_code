#include <cstdio>
#include <cstdlib>
#include <cstdint>


int main()
{
    int t;scanf("%d", &t);
    for(;t;--t)
    {
        int n;scanf("%d", &n);
        printf("%s\n", (n % 4 == 0)?"Bob":"Alice");
    }


    return 0;
}