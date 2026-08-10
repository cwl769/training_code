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

bool can(int i, int val) {
    if (str[i] == '?')
        return true;
    return str[i] - '0' == val;
}

char rev(char c) {
    if (c == '0')
        return '1';
    return '0';
}

void solve() {
    int n;readInt(n);
    scanf("%s", str + 1);
    for (int i = 3; i <= n; ++i) {
        if (str[i - 2] != '?') {
            if (str[i] != '?' && str[i] == str[i - 2]) {
                printf("0\n");
                return;
            }
            str[i] = rev(str[i - 2]);
        }
    }
    for (int i = n - 2; i >= 1; --i) {
        if (str[i + 2] != '?') {
            if (str[i] != '?' && str[i] == str[i + 2]) {
                printf("0\n");
                return;
            }
            str[i] = rev(str[i + 2]);
        }
    }

    int ans = 1;
    if (str[1] == '?')
        ans <<= 1;
    if (str[2] == '?')
        ans <<= 1;
    printf("%d\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
