#include <cstdio>
#include <cstdlib>
#include <cstdint>

int a[200010];

int main()
{
    int T;scanf("%d", &T);
    for(;T;T--)
    {
        int n, j, k;scanf("%d%d%d", &n, &j, &k);
        for(int i=1;i<=n;++i)scanf("%d", a+i);
        bool ismin = true, ismax = true;
        bool haseq = false;
        for(int i=1;i<=n;++i)
        {
            if(i==j)continue;
            if(a[i]==a[j])haseq = true;
            if(a[i]<a[j])ismin = false;
            if(a[i]>a[j])ismax = false;
        }
        if(k==1&&ismax == false)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }


    return 0;
}