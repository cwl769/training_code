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

char str[1000010];

void solve() {
    int n;
    readInt(n);
    scanf("%s", str + 1);
    veci s(n + 2);
    for (int i = 1; i <= n; ++i) {
        if (str[i] == '1') {
            s[i] = s[i-1] + 1;
        } else {
            s[i] = s[i-1] - 1;
        }
    }
    int cnt[3] = {0, 0, 0};
    i64 ans = 0;
    cnt[0]++;
    for (int i = 1; i <= n; ++i) {
        int val = (s[i] % 3 + 3) % 3;
        ans += cnt[0] + cnt[1] + cnt[2] - cnt[val];
        cnt[val]++;
    }
    // printf("%lld ", ans);
    int last = 1;
    for (itn i = 2; i <= n; ++i) {
        if (str[i] != str[i - 1]) {
            int len = i - last + 1;
            ans -= (len - 1) / 2;
        } else {
            last = i;
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
