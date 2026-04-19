#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <algorithm>
#include <vector>

int main() {
    int n;scanf("%d", &n);
    int mnx = INT_MAX, mxx = INT_MIN, mny = INT_MAX, mxy = INT_MIN;
    for(int i=1;i<=n;++i) {
        int x, y;scanf("%d%d", &x, &y);
        if(x < mnx) mnx = x;
        if(x > mxx) mxx = x;
        if(y < mny) mny = y;
        if(y > mxy) mxy = y;
    }
    int ans = std::max(
        (mxx - mnx + 1) / 2,
        (mxy - mny + 1) / 2
    );
    printf("%d\n", ans);


    return 0;
}