#include <bits/stdc++.h>
//#include <ext/pids/assoc_container.hpp>
//#include <ext/pids/tree_policy.hpp>

//using namespace __gnu_pbds;

using namespace std;
// typedef tree<pair<uint32_t, uint32_t>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // pair -> multiset, int -> set
// ordered_set s; // multiset: s.find_by_order(e - 1) -> first 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx2,mmx,fma,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")

//#define PI 3.1415926535897932384626433832795
#define MOD 1000000007LL
#define int long long
//#define ld __float128
// #define ld long double
//#define __float128 long double
//#define endl "\n"
using ll = long long;
using ld = long double;
const ll inf = 1e9;    
const double eps = 1e-9 ;   
const double PI = 3.14159265358979323846;

const int MAX = 5e5;


void solve() {
    int n = 5e5;
    int a = 1e8;
    int k = 1e8 - n;
    mt19937 gen(37849267); 
    uniform_int_distribution<> F(1,  1e8); 
    //shuffle(a.begin(), a.end(), gen);
    cout<< n << " " << n << endl;

    vector<int> F1;
    for(int i = 1; i <= n; i++) {
        //F1.push_back(F(gen));
    }
    sort(F1.begin(), F1.end());

    for(int i = 1; i <= n; i++) {
        if(i == n) cout<< F(gen) << endl;
        else cout<< F(gen) << " ";
    }
    for(int i = 1; i <= n; i++) {
        if(i == n) cout<< i * 200 << endl;
        else cout<< (i - 1) * 200 << " ";
    }
}

int32_t main(){
    
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    //mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    //uniform_int_distribution<> F(0,  n - 1); 
    //shuffle(a.begin(), a.end(), gen);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(nullptr);
    int test_case = 1; //cin>> test_case;
    while (test_case--)
    {
        solve();
    }
    return 0;
}



