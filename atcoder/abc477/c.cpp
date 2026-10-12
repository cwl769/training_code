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

char str[400010], ttr[400010];
char comb[800010];

bool check(const char *s, const char *t) {
    for(;*t != '\0';++s,++t) {
        if(*s != *t)
            return false;
    }
    return true;
}

void solve() {
    int Q;readInt(Q);
    scanf("%s%s", str+1, ttr+1);
    int n = strlen(str + 1);
    veci sum(n + 2);
    for (int i = 1; i <= n; ++i)
        if(check(str + i, ttr + 1))
            ++sum[i];
    for (int i = 1; i <= n; ++i)
        sum[i] += sum[i - 1];
    int tl = strlen(ttr + 1);
    while(Q--) {
        int l, r;
        readInt(l, r);
        if(r - l + 1 < tl) {
            printf("No\n");
            continue;
        }
        r -= tl - 1;
        if(sum[r] - sum[l - 1])
            printf("Yes\n");
        else
            printf("No\n");
    }
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}