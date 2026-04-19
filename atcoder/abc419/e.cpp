#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <vector>

int a[510];
int c[510][510];
int f[510][510];

int main() {
    int n, m, l;scanf("%d%d%d", &n, &m, &l);
    for(int i=1;i<=n;++i) {
        scanf("%d", a+i);
    }
    for(int i=1;i<=l;++i)
    for(int r=0;r<m;++r)
    {
        for(int d=0;i+d<=n;d+=l) {
            int t = a[i+d] % m;
            if(t <= r) c[i][r] += r - t;
            else c[i][r] += m + r - t;
        }
    }

    memset(f, 0x7f, sizeof(f));
    for(int j=0;j<m;++j)
        f[1][j] = c[1][j];
    for(int i=2;i<=l;++i)
    for(int j=0;j<m;++j)
    {
        int t = j;
        for(int k=0;k<m;++k) {
            f[i][j] = std::min(f[i][j], f[i-1][k] + c[i][t]);
            --t;if(t<0)t += m;
        }
    }

    // for(int i=1;i<=l;++i) {
    //     for(int j=0;j<m;++j)
    //         printf("%2d |", c[i][j]);
    //     printf("\n");
    // }
    // printf("--------------------------\n");
    // for(int i=1;i<=l;++i) {
    //     for(int j=0;j<m;++j)
    //         printf("%2d |", f[i][j]);
    //     printf("\n");
    // }
    // printf("--------------------------\n");

    printf("%d\n", f[l][0]);


    return 0;
}