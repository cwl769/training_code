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
#include <queue>
#include <stack>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

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

i64 a[2000010];
int mna[30][2000010];

void f(int n, int prefix, i64 &ans,
       std::vector<std::pair<int, int>> &ansv) {
    if (n == 0) {
        return;
    }
    f(n - 1, prefix, ans, ansv);
    f(n - 1, prefix | (1 << (n - 1)), ans, ansv);
    int ind = mna[n - 1][prefix];
    ans += a[ind];
    ansv.emplace_back(ind, ind | (1 << (n - 1)));
}

void solve() {
    int n;
    readInt(n);
    int tot = (1 << n);
    for (int i = 0; i < tot; ++i) {
        readInt(a[i]);
    }
    a[tot] = LLONG_MAX;
    for (int i = 0; i < tot; ++i)
        mna[0][i] = i;
    for (int j = 1; j < 22; ++j) {
        int dd = (1 << (j - 1));
        for (int i = 0; i < tot; ++i) {
            mna[j][i] = mna[j - 1][i];
            if (i + dd < tot && a[mna[j - 1][i + dd]] < a[mna[j][i]])
                mna[j][i] = mna[j - 1][i + dd];
        }
    }
    i64 ans = 0;
    std::vector<std::pair<int, int>> ansv;
    f(n, 0, ans, ansv);
    printf("%d\n", tot - 1);
    for (auto [x, y] : ansv)
        printf("%d %d\n", x, y);
    printf("%lld\n", ans);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}
