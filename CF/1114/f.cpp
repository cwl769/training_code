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

i64 lowbit(i64 x) { return x & (-x); }

void append(veci64 &base, i64 x) {
    for (auto c : base) {
        if (lowbit(x & c) == lowbit(c)) {
            x ^= c;
        }
    }
    if (x == 0)
        return;
    int p = (int)base.size();
    base.emplace_back(x);
    while (p && lowbit(x) < lowbit(base[p - 1])) {
        std::swap(base[p], base[p-1]);
        --p;
    }
}

bool solve() {
    int n;
    readInt(n);
    veci64 a(n + 2), b(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    for (int i = 1; i <= n; ++i)
        readInt(b[i]);
    veci64 basea, baseb;
    for (int i = 1; i <= n; ++i)
        append(basea, a[i]);
    for (int i = 1; i <= n; ++i)
        append(baseb, b[i]);

    for (auto x : basea)
        printf("%lld ", x);
    printf("\n");
    for (auto x : baseb)
        printf("%lld ", x);
    printf("\n");
    
    if (basea.size() != baseb.size())
        return false;

    int sz = (int)basea.size();
    for (auto x : baseb) {
        append(basea, x);
    }
    if (sz != (int)basea.size())
        return false;
    return true;
}

int main() {
    int T;readInt(T);
    while(T--) {
        if (solve())
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
