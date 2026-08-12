#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

#define debug(...) fprintf(stderr, __VA_ARGS__)

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

void allodd(int l, int r,
            std::vector<std::pair<std::pair<int, int>, int>> &ans) {
    if (r - l + 1 <= 1)
        return;
    ans.push_back({{l, l}, r - l});
    if (r - l + 1 <= 3)
        return;
    for (int i = l + 2; i + 1 < r; i += 2)
        ans.push_back({{i, l}, 1});
    for (int i = l + 1; i + 1 < r; i += 2)
        ans.push_back({{i, r - 1}, 1});
    for (int j = l + 1; j + 1 < r; j += 2)
        ans.push_back({{l, j}, 1});
    for (int j = l + 2; j + 1 < r; j += 2)
        ans.push_back({{r - 1, j}, 1});
    allodd(l + 2, r - 2, ans);
}

void solve() {
    int n, m;
    readInt(n, m);
    if ((n & 1) && (m & 1)) {
        std::vector<std::pair<std::pair<int, int>, int> > ans;
        if (n > m) {
            for (int i = m + 1; i + 1 <= n; i += 2)
                for (int j = 1; j + 1 <= m; j += 2)
                    ans.push_back({{i, j}, 1});
            n = m;
        } else if (n < m) {
            for (int j = n + 1; j + 1 <= m; j += 2)
                for (int i = 1; i + 1 <= n; i += 2)
                    ans.push_back({{i, j}, 1});
            m = n;
        }
        allodd(1, n, ans);
        printf("%d\n", (int)ans.size());
        for (auto pr : ans) {
            printf("%d %d %d\n", pr.first.first, pr.first.second, pr.second);
        }
        return;
    }
    int ans = (n / 2) * (m / 2);
    printf("%d\n", ans);
    for (int i = 1; i + 1 <= n; i += 2) {
        for (int j = 1; j + 1 <= m; j += 2) {
            printf("%d %d 1\n", i, j);
        }
    }
    
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }
    // solve();

    return 0;
}
