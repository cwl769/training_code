#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

typedef long long int64;

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

int main() {
    int64 n, m;readInt(n, m);
    std::vector<int64>x(n+1), y(n+1);
    for(int i=1;i<=n;++i) {
        readInt(x[i], y[i]);
    }
    int64 mnp = 0;
    x[0] = LLONG_MAX;
    for(int i=1;i<=n;++i) {
        if(x[i]+y[i] < x[mnp]+y[mnp]) {
            mnp = i;
        } else if (x[i]+y[i] == x[mnp]+y[mnp] && )
    }


    return 0;
}