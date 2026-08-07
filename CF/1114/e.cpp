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

void solve() {
    int n;
    readInt(n);
    veci64 b(n + 2);
    for (int i = 1; i <= n; ++i) {
        readInt(b[i]);
    }
    i64 sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += b[i];
    if (sum <= 0) {
        printf("-1\n");
        return;
    }
    sum = 0;
    std::multiset<i64> set;
    veci64 sorted;
    for (int i = 1; i <= n; ++i) {
        if (b[i] > 0)
            sorted.emplace_back(b[i]);
        else
            set.emplace(b[i]);
    }
    std::sort(sorted.begin(), sorted.end());
    for (auto x : sorted) {
        sum += x;
        printf("%lld ", sum);
        while (set.size()) {
            auto it = set.upper_bound(-sum);
            if (it == set.end())
                break;
            sum += *it;
            printf("%lld ", sum);
            set.erase(it);
        }
    }

    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
