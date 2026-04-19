#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

struct DSU {
    int *fa;
    DSU(int n) {
        fa = (int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;++i)
            fa[i] = i;
    }
    ~DSU() {
        free(fa);
    }
    int get(int x) {
        if(fa[x] == x)return x;
        return fa[x] = get(fa[x]);
    }
    bool merge(int x, int y) {
        x = get(x);
        y = get(y);
        if(x == y)return false;
        fa[x] = y;
        return true;
    }
};

char s1[1010], s2[1010], s3[1010];

bool solve() {
    scanf("%s%s%s", s1, s2, s3);
    int n1, n2, n3;    
    n1 = strlen(s1);
    n2 = strlen(s2);
    n3 = strlen(s3);

    if(n1!=n2) {
        return false;
    }

    if(n1!=n3)
        return true;

    int n = n1;

    DSU dsu(256);

    for(int i=0;i<n;++i) {
        dsu.merge(s1[i], s2[i]);
    }

    for(int i=0;i<n;++i) {
        s1[i] = dsu.get(s1[i]);
    }
    for(int i=0;i<n;++i) {
        s3[i] = dsu.get(s3[i]);
    }

    return strcmp(s1, s3) != 0;
}

int main() {
    int T;scanf("%d", &T);
    while(T--) {
        bool ans = solve();
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}