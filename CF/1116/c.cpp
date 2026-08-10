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

char str[200010];
char tmp[200010];

void solve() {
    int n, k;
    readInt(n, k);
    scanf("%s", str + 1);
    int n2 = n * 2;
    for (itn i = 1; i <= n2 + 1; ++i) {
        tmp[i] = '\0';
    }
    for (int i = 1; i <= n2; ++i) {
        if (str[i] == '1') {
            if (str[i % n2 + 1] == '0') {
                tmp[i] = '0';
                tmp[i % n2 + 1] = '1';
            }
        }
    }
    for (int i = 1; i <= n2; ++i)
        if (tmp[i] == '\0')
            tmp[i] = str[i];
    int cnt[2] = {0, 0};
    for (int i = 1; i <= n2; ++i)
        if (tmp[i] == '1') {
            cnt[i&1]++;
        }
    printf("%d %d\n", cnt[0], cnt[1]);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
