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

typedef long long int64;
typedef long long i64;
typedef unsigned long long ui64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;


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
    int n, m;readInt(n, m);
    veci a(n+2);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    int len = 0;
    a[0] = -1;
    a[n+1] = -1;
    for(int i=1;i<=n+1;++i) {
        if(a[i] == a[i-1]) {
            ++len;
        } else {
            if(len >= m)
                return false;
            len = 1;
        }
    }
    return true;
}

int main() {
    int T;readInt(T);
    while(T--) {
        if(solve()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}