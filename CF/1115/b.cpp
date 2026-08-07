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

const int inf = 0x3f3f3f3f;

int check(int cnt0, int cnt1) {
    if (std::abs(cnt0 - cnt1) <= 1)
        return cnt0 + cnt1;
    return inf;
}

char str[200010];

void solve() {
    int n;
    readInt(n);
    scanf("%s", str + 1);
    if (n == 1) {
        printf("0\n");
        return;
    }
    int cnt[2] = {0, 0};
    for (int i = 2; i <= n; ++i) {
        if (str[i] == str[i - 1]) {
            ++cnt[str[i]-'0'];
        }
    }
    int bged = 0;
    if (str[1] == '1')
        ++bged;
    if (str[n] == '1')
        ++bged;
    int ans = check(cnt[0], cnt[1]);
    if (bged == 0) {
        ans = std::min(ans, check(cnt[0] + 1, cnt[1]));
        ans = std::min(ans, check(cnt[0] + 2, cnt[1]));
    } else if (bged == 1) {
        ans = std::min(ans, check(cnt[0] + 1, cnt[1]));
        ans = std::min(ans, check(cnt[0], cnt[1] + 1));
        ans = std::min(ans, check(cnt[0] + 1, cnt[1] + 1));
    } else if (bged == 2) {
        ans = std::min(ans, check(cnt[0], cnt[1] + 1));
        ans = std::min(ans, check(cnt[0], cnt[1] + 2));
    }
    if (ans == inf)
        printf("-1\n");
    else
        printf("%d\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
