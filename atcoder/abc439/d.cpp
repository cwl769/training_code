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

int64 great(const std::vector<int>&vec, int d) {
    return vec.end() - std::upper_bound(vec.begin(), vec.end(), d);
}

int64 less(const std::vector<int>&vec, int d) {
    return std::lower_bound(vec.begin(), vec.end(), d) - vec.begin();
}

int main() {
    int n;readInt(n);
    std::map<int, std::vector<int> > map;
    for(int i=1;i<=n;++i) {
        int x;readInt(x);
        map[x].push_back(i);
    }
    int64 ans = 0;
    for(auto pr:map) {
        int x = pr.first;
        if(x % 5)continue;
        int d = x / 5;
        for(auto j:pr.second) {
            ans += great(map[3*d], j) * great(map[7*d], j);
            ans += less(map[3*d], j) * less(map[7*d], j);
        }
    }
    printf("%lld\n", ans);

    return 0;
}