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

char str[110][110];

int cnt[110];

int diff(char *s, char *t) {
    if(strlen(s) != strlen(t)) {
        return 1e9;
    }
    int ans = 0;
    while(*s!='\0') {
        if(*s != *t)
            ++ans;
        ++s, ++t;
    }
    return ans;
}

char tmp[110];

int dd[110];

void solve() {
    int n, m;readInt(n, m);
    for (int i = 0; i < n; ++i)
        scanf("%s", str[i]);
    for (int rnd = 0; rnd < m; ++rnd) {
        scanf("%s", tmp);
        for (int i = 0; i < n; ++i)
            dd[i] = diff(str[i], tmp);
        bool ret = false;
        for (int i = 0; i < n; ++i) {
            if(dd[i] == 0) {
                ret = true;
                ++cnt[i];
            }
        }
        if(ret)continue;
        int cc = 0;
        for (int i = 0; i < n; ++i) {
            if(dd[i] == 1)
                ++cc;
        }
        if(cc != 1)continue;
        for (int i = 0; i < n; ++i)
            if(dd[i] == 1)
                ++cnt[i];
    }
    for (int i = 0; i < n; ++i)
        printf("%d\n", cnt[i]);
}

int main() {
    // int T;readInt(T);
    // while(T--)
        solve();

    return 0;
}