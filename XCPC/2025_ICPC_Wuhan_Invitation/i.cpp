#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

typedef long long int64;
typedef std::vector<int> vector;

template<typename T>
void readInt(T& x) {
    static bool f;
    x = 0;f = false;
    char c = getchar();
    for(;c<'0' || c>'9';c=getchar())if(c=='-')f=!f;
    for(;'0'<=c&&c<='9';c=getchar()) {
        x = x * 10 + c - '0';
    }
    if(f)x = -x;
}
template<typename T, typename ...Args>
void readInt(T& x, Args&... args) {
    readInt(x);
    readInt(args...);
}

int ans[100][100];

void solve() {
    int n, k;readInt(n, k);
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
        ans[i][j] = 0;
    if(k < n || k > n*n - n + 1) {
        printf("No\n");
        return;
    }
    int cnt = 0;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if(i == j)continue;
            ++cnt;
            if(cnt >= k) break;
            ans[i][j] = cnt;
        }
        if(cnt >= k)break;
    }
    ans[1][1] = k;
    cnt = k;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if(ans[i][j] == 0) {
                ++cnt;
                ans[i][j] = cnt;
            }
        }
    }
    printf("Yes\n");
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}