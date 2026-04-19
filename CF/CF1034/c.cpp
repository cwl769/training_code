#include <cstdio>
#include <cstdlib>
#include <cstdint>

int a[200010];
int ans[200010];

int main()
{
    int T;scanf("%d", &T);
    for(;T;--T)
    {
        int n;scanf("%d", &n);
        for(int i=1;i<=n;++i)scanf("%d", a+i);
        for(int i=1;i<=n;++i)ans[i] = 0;
        ans[1] = ans[n] = 1;
        for(int i=2,cmin=a[1];i<=n;++i)
        {
            if(cmin>a[i])
            {
                cmin = a[i];
                ans[i] = 1;
            }
        }
        for(int i=n-1,cmax=a[n];i>=1;--i)
        {
            if(cmax<a[i])
            {
                cmax = a[i];
                ans[i] = 1;
            }
        }
        for(int i=1;i<=n;++i)putchar((ans[i]==1)?'1':'0');
        putchar('\n');
    }


    return 0;
}