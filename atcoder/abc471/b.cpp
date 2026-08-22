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

char str[110][100];
int ans[110];

void solve() {
    int n;readInt(n);
    for (itn i = 1; i <= n; ++i)
        scanf("%s", str[i]);
    for (int i = 1; i <= n; ++i) {
        int len = strlen(str[i]);
        for (int j = 0; j < len; ++j)
            if('A' <= str[i][j] && str[i][j] <='Z') {
                str[i][j] = str[i][j] - 'A' + 'a';
            }
    }

    for (int i = 1; i <= n; ++i) {
        int fst = i;
        for(int j = 1; j < i; ++j) {
            if(strcmp(str[i], str[j]) == 0) {
                fst = j;
                break;
            }
        }
        ++ans[fst];
    }
    int fin = 1;
    for(int i = 1; i <= n; ++i) {
        fin = std::max(fin, ans[i]);
    }
    printf("%d\n", fin);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}