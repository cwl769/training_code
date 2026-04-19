#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <algorithm>

int main() {
    int T;scanf("%d", &T);
    for(;T;--T) {
        int n, s;scanf("%d%d", &n, &s);
        int sum = 0;
        int cnt[3] = {0, 0, 0};
        for(int i=1;i<=n;++i) {
            int x;scanf("%d", &x);
            sum += x;
            ++cnt[x];
        }
        if (s < sum || s-sum == 1) {
            int i = 0;
            for(int j=0;j<cnt[i];++j)
                printf("%d ", i);
            i = 2;
            for(int j=0;j<cnt[i];++j)
                printf("%d ", i);
            i = 1;
            for(int j=0;j<cnt[i];++j)
                printf("%d ", i);
            printf("\n");
        } else {
            printf("-1\n");
        }
    }
    return 0;
}