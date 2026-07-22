#include <cstdio>
#include <cstring>

typedef long long i64;

void solve(int n) {
    
    for (int i = 0; i < n; ++i) {
        printf("%d ", 2*i+1-n);
    }
    //printf("\n");

    i64 mx = 0, mn = 0;
    for (int i = 0; i < n; ++i) {
        mx += (2ll * i + 1ll - n) * i;
        mn += (2ll * i + 1ll - n) * (n-1-i);
    }
    printf("[%lld, %lld]", mn, mx);
    

    return;
}

int main() {
    for (int x = 1; x <= 10; ++x) {
        printf("%2d|", x);
        solve(x);
        printf("\n");
    }

    return 0;
}
