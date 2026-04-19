#include <cstdio>
#include <cstdlib>
#include <cstdint>

char str[200010];

int main()
{
    int T;scanf("%d", &T);
    for(;T;--T)
    {
        int n, k;scanf("%d%d", &n, &k);
        scanf("%s", str+1);
        int cnt1 = 0;
        for(int i=1;i<=n;++i)
        {
            str[i] -= '0';
            if(str[i]==1)++cnt1;
        }
        if(cnt1<=k)printf("Alice\n");
        else
        {
            int cnt1m = 0;
            for(int i=n-k+1;i<=k;++i)
                if(str[i]==1)++cnt1m;
            if(cnt1 - cnt1m > k)
                printf("Bob\n");
            else
                printf("Alice\n");
        }
    }


    return 0;
}