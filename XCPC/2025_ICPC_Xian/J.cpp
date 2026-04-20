#include<bits/stdc++.h>
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define fd(a,b,c) for(int a=b;a>=c;a--)
#define int long long
using namespace std;
const int N=5e5+5,inf=1e18;
int T,n,i,j,k,l,o,p,c[N],m,in[N],out[N],tim,f[N],h[N],dp[N];
vector<int> g[N];
inline void dfs(int u,int fa){
    int mn=inf,mmn=inf;
    if(g[u].size()==1){
        dp[u]=c[u];
        in[u]=++tim;
        out[u]=++tim;
        return;
    }
    in[u]=++tim;
    for(auto v:g[u]){
        if(v==fa)continue;
        dfs(v,u);
        if(dp[v]<mn){
            mmn=mn;
            mn=dp[v];
        }
        else {
            mmn=min(mmn,dp[v]);
        }
    }
    dp[u]=min(c[u],mmn+mn);
    out[u]=++tim;
    for(auto v:g[u]){
        if(v==fa)continue;
        if(mn==dp[v]){
            f[v]=mmn;
        }
        else f[v]=mn;
    }
}
inline void init(int u,int fa){
    if(u!=1){
        h[u]=h[fa]+f[u];
    }
    for(auto v:g[u]){
        if(v!=fa)init(v,u);
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m;
        tim=0;
        fu(i,1,n)cin>>c[i];
        dp[n+1]=inf;
        fu(i,1,n){
            in[i]=out[i]=f[i]=0;
            h[i]=0;
            dp[i]=0;
            g[i].clear();
        }
        fu(i,1,n-1){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        init(1,0);
        while(m--){
            int x,y;
            cin>>x>>y;
            if(!(in[x]>in[y]&&out[x]<out[y])){
                cout<<"-1\n";
                continue;                                                      
            }
            cout<<h[x]-h[y]<<'\n';
        }
    }
    return 0;
}