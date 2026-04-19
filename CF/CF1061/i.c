#include <stdio.h>
#include <math.h>

typedef long long int64;

int f[200000][5];

int64 fi(int64 x,int op,int m,int n,int i)
{
    if(op==0)
        return f[i][3]*x+f[i][4];
    if(op==1)
        return x+m;
    if(op==2)
        return x*m;
    if(op==3)
    {
        int64 ans=fi(fi(x,f[n-1][0],f[n-1][1],f[n-1][2],n-1),f[m-1][0],f[m-1][1],f[m-1][2],m-1);
        f[i][0]=0;
        f[i][3]=(f[m-1][3]*f[n-1][3]);f[i][4]=(f[m-1][3]*f[n-1][4]+f[m-1][4]);
        return ans;
    }
    if(op==4)
    {
        int64 ans=fi(x,f[m-1][0],f[m-1][1],f[m-1][2],m-1)+fi(x,f[n-1][0],f[n-1][1],f[n-1][2],n-1);
        f[i][0]=0;
        f[i][3]=(f[m-1][3]+f[n-1][3]);f[i][4]=(f[m-1][4]+f[n-1][4]);
        return ans;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&f[i][0]);
        if(f[i][0]<3)
        {
            scanf("%d",&f[i][1]);
            if(f[i][0]==1)
            {
                f[i][3]=1;
                f[i][4]=f[i][1];
            }
            else
                f[i][3]=f[i][1];
        }
        else
            scanf("%d%d",&f[i][1],&f[i][2]);
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int64 k,x;
        scanf("%lld%lld",&k,&x);
        int64 ans=fi(x,f[k-1][0],f[k-1][1],f[k-1][2],k-1);
        printf("%lld\n",ans);
    }
    return 0;
}