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

void solve() {
    int n, q;
    readInt(n, q);
    veci a(n);
    for (int i = 0; i < n; ++i) {
        readInt(a[i]);
    }
    std::sort(a.begin(), a.end());
    veci sav(71);
    sav[0] = a.back() - a.front();
    for(int rnd = 1; rnd <= 70; ++rnd) {
        veci b;
        for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            b.emplace_back(a[i] ^ a[j]);
        }
        std::sort(b.begin(), b.end());
        for(int i = 0; i < n; ++i)
            a[i] = b[i];
        sav[rnd] = a.back() - a.front();
    }
    while(q--) {
        int x;readInt(x);
        if(x <= 70)
            printf("%d\n", sav[x]);
        else
            printf("0\n");
    }
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}