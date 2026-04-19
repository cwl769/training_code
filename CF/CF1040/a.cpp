#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <algorithm>

int main() {
    int T;scanf("%d", &T);
    for(;T;--T) {
        int n;scanf("%d", &n);
        int sum = 0;
        int cnt = 0;
        for(int i=1;i<=n;++i) {
            int x;scanf("%d", &x);
            if(x==0) ++cnt;
            sum += x;
        }
        sum += cnt;
        printf("%d\n", sum);
    }
    return 0;
}