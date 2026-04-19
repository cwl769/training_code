#include<bits/stdc++.h>
// #include "testlib.h"
using namespace std;
 
int main(int argc, char* argv[]){
    // registerGen(argc, argv, 1);
    
    int n = 3e5, q = 3e5;
    cout << n << ' ' << q << '\n';

    for(int i = 0; i < n; i++)
        cout << 30 << " \n"[i==n-1];

    for(int i = 1; i < q; i++)
        cout << 1 << ' ' << 30 << '\n';
    
    cout << 3 << ' ' << (1ll<<30) << '\n';

}