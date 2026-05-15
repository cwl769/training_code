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

void solve() {
    int n;readInt(n);
    veci v6, v2, v3, v1;
    for(int i=1;i<=n;++i) {
        int x;readInt(x);
        if(x%6 == 0) {
            v6.push_back(x);
        } else if(x%2 == 0) {
            v2.push_back(x);
        } else if(x%3 == 0) {
            v3.push_back(x);
        } else {
            v1.push_back(x);
        }
    }
    for(auto x:v6)
        printf("%d ", x);
    for(auto x:v2)
        printf("%d ", x);
    for(auto x:v1)
        printf("%d ", x);
    for(auto x:v3)
        printf("%d ", x);
    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}