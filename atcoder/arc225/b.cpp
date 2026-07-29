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

bool solve() {
    int n;
    readInt(n);

    veci a(n + 2);
    for (int i = 1; i <= n; ++i) {
        readInt(a[i]);
    }

    int cnt = 0;

    for (int i = 1; i <= n+1; ++i) {
        if (a[i]) {
            ++cnt;
            if (cnt > 2)
                return true;
        } else {
            if (cnt == 1 || cnt > 2)
                return true;
            cnt = 0;
        }
    }
    return false;
}

int main() {
    int T;readInt(T);
    while(T--) {
        if (solve()) {
            printf("Alice\n");
        } else {
            printf("Bob\n");
        }
    }

    return 0;
}
