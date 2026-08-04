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

char s[200010], t[200010];

void solve() {
    int n, q;
    readInt(n, q);
    scanf("%s%s", s + 1, t + 1);
    veci sum[4];
    for (int j = 0; j < 4; ++j)
        sum[j].resize(n + 2);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 4; ++j)
            sum[j][i] = sum[j][i-1];
        if (s[i] == '0' && t[i] == '0') {
            ++sum[0][i];
        } else if (s[i] == '1' && t[i] == '1') {
            ++sum[1][i];
        } else if (s[i] == '0' && t[i] == '1') {
            ++sum[2][i];
        } else if (s[i] == '1' && t[i] == '0') {
            ++sum[3][i];
        }
    }
    while (q--) {
        int l, r;
        readInt(l, r);
        int cnt0 = sum[0][r] - sum[0][l-1];
        int cnt1 = sum[1][r] - sum[1][l-1];
        int cnt2 = sum[2][r] - sum[2][l-1];
        int cnt3 = sum[3][r] - sum[3][l-1];
        int d = std::abs(cnt2 - cnt3);
        if(cnt0 + cnt1 >= d) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
