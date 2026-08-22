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

char a[400010], b[400010], c[400010];
int sa[400010], sb[400010], sc[400010];
int sans[400010];
char ans[400010];

void solve() {
    int n;
    readInt(n);
    int n2 = n * 2;
    scanf("%s%s%s", a + 1, b + 1, c + 1);
    for (int i = 1; i <= n2; ++i) {
        sa[i] = sa[i - 1];
        if (a[i] == '1')
            ++sa[i];
    }
    for (int i = 1; i <= n2; ++i) {
        sb[i] = sb[i - 1];
        if (b[i] == '1')
            ++sb[i];
    }
    for (int i = 1; i <= n2; ++i) {
        sc[i] = sc[i - 1];
        if (c[i] == '1')
            ++sc[i];
    }

    for (int i = 1; i <= n2; ++i) {
        veci v({sa[i], sb[i], sc[i]});
        std::sort(v.begin(), v.end());
        sans[i] = v[1];
    }
    for (int i = 1; i <= n2; ++i) {
        ans[i] = '0';
        if (sans[i] != sans[i - 1])
            ++ans[i];
    }
    ans[n2 + 1] = '\0';
    i64 cnt = 0;
    for (int i = 1; i <= n2; ++i) {
        cnt += std::abs(sa[i] - sans[i]);
        cnt += std::abs(sb[i] - sans[i]);
        cnt += std::abs(sc[i] - sans[i]);
    }
    printf("%lld\n%s\n", cnt, ans + 1);
    
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}
