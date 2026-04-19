#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <vector>

bool vis[500010];
char S[500010], T[500010];

int main() {
    int n, m;scanf("%d%d", &n, &m);
    scanf("%s%s", S+1, T+1);
    for(int i=1;i<=m;++i) {
        int l, r;scanf("%d%d", &l, &r);
        vis[l] ^= 1;
        vis[r+1] ^= 1;
    }
    bool swp = 0;
    for(int i=1;i<=n;++i) {
        swp ^= vis[i];
        if(swp) putchar(T[i]);
        else putchar(S[i]);
    }
    printf("\n");


    return 0;
}