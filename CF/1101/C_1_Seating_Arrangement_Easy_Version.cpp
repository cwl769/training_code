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

char str[3010];
char tmp[3010];

void solve() {
    int n, m, s;readInt(n, m, s);
    scanf("%s", str+1);
    int cnta = 0;
    for(int i=1;i<=n;++i) {
        if(str[i] == 'A')
        ++cnta;
    }
    int ans = 0;
    for(int a=0;a<=cnta;++a) {
        int cura = 0;
        for(int i=1;i<=n;++i) {
            if(str[i] == 'A') {
                ++cura;
                if(cura <= a)
                    tmp[i] = 'I';
                else
                    tmp[i] = 'E';
            } else {
                tmp[i] = str[i];
            }
        }
        int sum = 0;
        int avi = 0, emp = m;
        for(int i=1;i<=n;++i) {
            if(tmp[i] == 'I') {
                if(emp) {
                    ++sum;
                    --emp;
                    avi += s - 1;
                }
            } else {
                if(avi) {
                    ++sum;
                    --avi;
                }
            }
        }
        ans = std::max(ans, sum);
    }
    printf("%d\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}