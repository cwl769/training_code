#include<bits/stdc++.h>
using namespace std;
#define fu(a,b,c) for(int a=b;a<=c;a++)
const int N=5e5+5;
int a[N], n, i, j, k, l, o, p, b[N];
typedef long long i64;

void printAns(int n) {
    for (int i = 1; i <= n; ++i)
        printf("%d ", b[i]);
    printf("\n");
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k,x;
    cin >> n >> k >> x;
    i64 sum1=0;
    fu(i, 1, n) cin >> a[i];
    fu(i, 1, n) sum1 = (sum1 + 1ll * (2 * i - 1) * a[i]);
    
    b[k+1]=x;
    int t=0;
    fu(i, 1, n) {
        if(i==k+1)continue;
        if(t==x)t++;
        b[i]=t;
        t++;
    }
    i64 sum2=0;
    fu(i, 1, n) sum2 = (sum2 + 1ll * (2 * i - 1) * b[i]);

    if ((sum2 - 2 + n) % n == sum1 % n && k > 1) {
        std::swap(b[1], b[2]);
        printAns(n);
        return 0;
    }
    if ((sum2 - 2 + n) % n == sum1 % n && k + 2 < n) {
        std::swap(b[k + 2], b[k + 3]);
        printAns(n);
        return 0;
    }

    if ((n & 1) && (k & 1)) {
        std::swap(b[k], b[k + 2]);
        sum2 -= 4;
    }
    if (sum2 % n == sum1 % n) {
        printAns(n);
        return 0;
    }

    for (int i = 1; i + 1 < k + 1; i+=2) {
        std::swap(b[i], b[i + 1]);
        sum2 -= 2;
        if (sum2 % n == sum1 % n) {
            printAns(n);
            return 0;
        }
    }
    for (int i = n; i - 1 > k + 1; i -= 2) {
        std::swap(b[i], b[i - 1]);
        sum2 -= 2;
        if (sum2 % n == sum1 % n) {
            printAns(n);
            return 0;
        }
    }


    for (int i = 0; i <= n; ++i)
        b[i] = 0;
    b[k + 1] = x;
    t = n - 1;
    for (int i = 1; i <= n; ++i) {
        if (i==k+1)
            continue;
        if (t == x)
            --t;
        b[i] = t;
        --t;
    }
    // printAns(n);
    sum2 = 0;
    for (int i = 1; i <= n; ++i) {
        sum2 += 1ll * b[i] * (2 * i - 1);
    }

    if ((sum2 + 2) % n == sum1 % n && k > 1) {
        std::swap(b[1], b[2]);
        printAns(n);
        return 0;
    }
    if ((sum2 + 2) % n == sum1 % n && k + 2 < n) {
        std::swap(b[k+2], b[k+3]);
        printAns(n);
        return 0;
    }

    if ((n & 1) && (k & 1)) {
        std::swap(b[k], b[k + 2]);
        sum2 += 4;
    }
    if (sum2 % n == sum1 % n) {
        printAns(n);
        return 0;
    }

    
    for (int i = 1; i + 1 < k + 1; i+=2) {
        std::swap(b[i], b[i + 1]);
        sum2 += 2;
        if (sum2 % n == sum1 % n) {
            printAns(n);
            return 0;
        }
    }
    for (int i = n; i - 1 > k + 1; i -= 2) {
        std::swap(b[i], b[i - 1]);
        sum2 += 2;
        if (sum2 % n == sum1 % n) {
            printAns(n);
            return 0;
        }
    }

    printf("-1\n");
    
    return 0;
}
