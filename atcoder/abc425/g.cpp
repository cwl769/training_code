#include <stdio.h>
#include <math.h>


int main()
{
    int a[200000]={0};
    int n,q;
    scanf("%d%d",&n,&q);
    int i,j;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int num=0;
    for(j=0;j<q;j++)
    {
        int op,c,l,r;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&c);
            for(i=0;i<c;i++)
            {
                a[n+i+num]=a[i+num];
            }
            num += c;
            // printf("%d\n",num);
        }
        else
        {
            scanf("%d%d",&l,&r);
            int sum=0;
            for(l=l+num-1;l<(r+num);l++)
            {
                sum+=a[l];
                // printf("%d ",a[l]);
            }
            printf("%d\n",sum);
        }
        for(int i=0;i<n+num;++i)
            printf("%d ", a[i]);
        printf("\n");
    }

    return 0;
}