#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <cstring>
#include <algorithm>

const int N = 5010;

int tr[N];
int lowbit(int x){return (x)&(-x);}
void add(int x) {
    while(x < N) {
        ++tr[x];
        x = x + lowbit(x);
    }
}
int get(int x) {
    int ans = 0;
    while(x) {
        ans += tr[x];
        x = x - lowbit(x);
    }
    return ans;
}
void clear() {memset(tr, 0, sizeof(tr));}

int a[N];
int commit[N];

int main() {
    int T;scanf("%d", &T);
    for(;T;--T) {
        int n;scanf("%d", &n);
        for(int i=1;i<=n;++i)
            scanf("%d", a+i);
        clear();
        int ans = 0;
        for(int i=1;i<=n;++i) {
            commit[i] = i - 1 - get(a[i]);
            ans += commit[i];
            add(a[i]);
        }
        clear();
        for(int i=n;i>=1;--i) {
            commit[i] -= n - i - get(a[i]);
            add(a[i]);
        }
        // for(int i=1;i<=n;++i)
        //     printf("%d ", commit[i]);
        // printf("\n");
        for(int i=1;i<=n;++i) {
            if(commit[i]>0)
                ans -= commit[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}