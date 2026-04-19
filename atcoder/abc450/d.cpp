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
typedef std::vector<int> vector;

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

#include <queue>

int main() {
    int64 n, k;readInt(n, k);
    std::vector<int64> a(n);
    for(int i=0;i<n;++i)
        readInt(a[i]);
    for(int i=0;i<n;++i)
        a[i] %= k;
    std::sort(a.begin(), a.end());
    a.resize(std::unique(a.begin(), a.end()) - a.begin());
    std::queue<int64> q;
    int64 ans = LLONG_MAX;
    for(int i=0;i<(int)a.size();++i) {
        q.push(a[i]);
    }
    for(int i=0;i<n;++i) {
        ans = std::min(ans, q.back() - q.front());
        q.push(q.front() + k);
        q.pop();
    }
    printf("%lld\n", ans);

    return 0;
}