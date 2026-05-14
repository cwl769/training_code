#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[1000010];int n;
int check(int mid)
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=upper_bound(b+1,b+n+1,mid-a[i])-(b+1);
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    int l=1,r=2e9;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(check(mid)>=n)
        {
            r=mid;
        }
        else l=mid+1;
    }
    int cur=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]+b[j]<l)
            {
                c[++cur]=a[i]+b[j];
            }
            else break;
        }
    }
    sort(c+1,c+cur+1);
    for(int i=1;i<=n;i++)
    {
        if(c[i]==0)c[i]=l;
        cout<<c[i]<<" ";
    }
    return 0;
}