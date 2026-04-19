#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define M 998244353
#define b(x) (1ll<<((x)-1))

const ll N=1000000,inf=1e18;

ll i,j,k,n,m,t,it,a[N+50];

//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng(114514);

basic_string<ll> p{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
#define cnt(x) __builtin_popcountll(x)

int main(int argc,char **argv) {
	//n=rng()%300000+2; m=rng()%500000+1; t=rng()%1+25;
	
	t=10000;
	cout<<t<<endl;
	while(t--){
		n=rng()%2+4;
		cout<<n<<endl;
		for(i=1;i<=n;i++)cout<<rng()%5+1<<" \n"[i==n];
		for(i=1;i<=n;i++)cout<<rng()%5+1<<" \n"[i==n];
	}
}