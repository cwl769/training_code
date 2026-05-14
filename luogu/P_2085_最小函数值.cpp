#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <queue>
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

struct Func {
    i64 a, b, c;
};

void solve() {
    int n, m;scanf("%d%d", &n, &m);

    std::vector<Func> func(n+1);
    for(int i=1;i<=n;++i)
        scanf("%lld%lld%lld", &func[i].a, &func[i].b, &func[i].c);
    std::priority_queue<std::pair<i64, std::pair<int, int> > > heap;
    for(int i=1;i<=n;++i)
        heap.push({-(func[i].a + func[i].b + func[i].c), {i, 1}});
    for(int i=1;i<=m;++i) {
        i64 val = -heap.top().first;
        int fc = heap.top().second.first;
        int x = heap.top().second.second;
        heap.pop();

        printf("%lld ", val);
        Func cur = func[fc];
        ++x;

        heap.push({-(cur.a * x * x + cur.b * x + cur.c), {fc, x}});
    }
    
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}



std::priority_queue<int> heap;
std::priority_queue<int, std::vector<int>, std::greater<int> > heap;