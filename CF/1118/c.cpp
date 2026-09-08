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

bool query(int x, int y, int d) {
    printf("? %d %d %d\n", x, y, d);
    fflush(stdout);
    int ans;
    readInt(ans);
    return ans;
}

void answer(int x, int y, int d){
    printf("! %d %d %d\n", x, y, d);
    fflush(stdout);
}

void solve() {
    int n;readInt(n);
    int dm = 2;
    int nx = 2;
    for(int x = 2; x <= n; ++x) {
        while(query(1, x, dm)) {
            ++dm;
            nx = x;
        }
    }
    int ny = 1;
    for(int y = 2; y <= n; ++y) {
        if(y == nx)
            continue;
        while(query(nx, y, dm)) {
            ++dm;
            ny = y;
        }
    }
    answer(nx, ny, dm - 1);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}