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

void solve() {
    int l, r;readInt(l, r);
    if(r < 0 || std::abs(l) > std::abs(r)) {
        std::swap(l, r);
        l = -l;
        r = -r;
    }
    if(l < 0) {
        l = -l + 1;
    }
    if(l > r) {
        printf("0\n");
        return;
    }
    if(l == 0) {
        printf("%d\n", std::max(0, r - 1));
        return;
    }
    printf("%d\n", r - l);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}