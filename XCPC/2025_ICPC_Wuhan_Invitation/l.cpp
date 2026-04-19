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

int func(int a, int b, int c) {
    if(a < 0 || b < 0 || c < 0) return -10;
    if(std::min(a,c) + b <= std::max(a,c)) {
        return 2 * (std::min(a, c) + b);
    } else {
        return (a + b + c) / 2 * 2;
    }
}

//<= x sum
int cnt(int x, std::map<int, int> &map) {
    auto it = map.upper_bound(x);
    if(it == map.begin())
        return 0;
    --it;
    return it->second;
}

void solve() {
    int n;readInt(n);
    std::vector<int> a(n+1);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    std::map<int, int> map;
    for(int i=1;i<=n;++i) {
        ++map[a[i]];
    }
    int ans = 0;
    int sum = 0;
    for(auto &pr:map) {
        ans = std::max(ans, pr.second);
        pr.second += sum;
        sum = pr.second;
    }
    for(int i=1;i<=n;++i) {
        for(int j=i+1;j<=n;++j) {
            if(a[i] == a[j])continue;
            int mn = std::min(a[i], a[j]);
            int mx = std::max(a[i], a[j]);
            if((mn + mx) & 1) {
                continue;
            }
            int md = ((mn+mx) >> 1);
            // printf("[%d, %d] %d %d %d\n", i, j, mn, md, mx);
            int a = cnt(md-1, map) - cnt(mn-1, map);
            int b = cnt(md, map) - cnt(md-1, map);
            int c = cnt(mx, map) - cnt(md, map);
            // printf("%d %d %d\n", a, b, c);
            ans = std::max(ans, func(a-1, b-1, c-1) + 3);
            ans = std::max(ans, func(a-1, b-1, c-2) + 4);
            ans = std::max(ans, func(a-1, b-2, c-1) + 4);
            // printf("%d ", func(a-1, b-1, c-1) + 3);
            // printf("%d ", func(a-1, b-1, c-2) + 4);
            // printf("%d ", func(a-1, b-2, c-1) + 4);
            // printf("\n");
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}