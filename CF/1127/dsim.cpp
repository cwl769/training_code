#include <cstdio>

bool vis[200010];
bool tmp[200010];

int main() {
    int n;scanf("%d", &n);
    for (int i = 2; i <= n + n; ++i) {
        vis[i] = 1;
    }
    
    int l = 2, r = n + n;
    while(1) {
        printf("|");
        for (int i = l; i <= r; ++i) {
            if(vis[i])
                printf("%02d ", i);
            else
                printf("   ");
        }
        printf("\n");
        int p;
        if(scanf("%d", &p) == EOF)
            break;
        printf("read %d\n", p);
        vis[p] = 0;
        for (int i = l; i <= r; ++i)
            tmp[i] = 0;
        for (int i = l; i <= r; ++i) {
            if(!vis[i])
                continue;
            tmp[i - 2] = 1;
            tmp[i + 1] = 1;
        }
        for (int i = l; i <= r; ++i)
            vis[i] = tmp[i];
    }

    return 0;
}