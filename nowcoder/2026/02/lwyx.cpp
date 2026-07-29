#include<bits/stdc++.h>
using namespace std;
#define int long long
using ull=unsigned long long;
using ll=long long;
using db=double;
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define fd(a,b,c) for(int a=b;a>=c;a--)
const int N=5e5+5,M=1e3+5,inf=1e18,mod=998244353,K=2e6+5,P=13331;
int n,i,j,k,T,tmp,m,p[N],pp[N],f[(1<<22)+5],g[(1<<22)+5];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        pp[i] = p[i];
    }
    vector<pair<int,int> > lm;
    for (int v = n; v >= 1; --v) {
        int pos = 1;
        while (pp[pos] != v)
            ++pos;
        for (int i = pos; i + 1 <= v; ++i) {
            std::swap(pp[i], pp[i + 1]);
            lm.emplace_back(pp[i], v);
        }
    }
    for(auto [x,y]:lm){
        g[x-1]|=(1<<(y-1));
    }
    f[0]=1;
    fu(bit,0,(1<<n)-1){
        fu(i,0,n-1){
            if((bit>>i)&1)continue;
            if((bit&g[i])==g[i]){
                (f[bit|(1<<i)]+=f[bit])%=mod;
            }
        }
    }
    cout<<(f[(1<<n)-1]*2)%mod;
    return 0;
}