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

struct Fenwick {
    int *c;
    int N;
    Fenwick(int n) {
        N = n + 10;
        c = (int*)calloc(N, sizeof(int));
    }
    ~Fenwick() {
        free(c);
    }
    void add(int x, int v) {
        for(;x<N;x+=(x&(-x)))
            c[x] += v;
    }
    int query(int x) {
        int ans = 0;
        for(;x;x-=(x&(-x)))
            ans += c[x];
        return ans;
    }
};

int main() {
    int T;readInt(T);
    while(T--) {
        int n;readInt(n);
        std::vector<int> p(n+1);
        for(int i=1;i<=n;++i)
            readInt(p[i]);
        Fenwick tree(n);
        int cnt = 0;
        int ans = 0;
        int sum = 0;
        for(int i=1;i<=n;++i) {
            ans = std::max(ans, cnt + sum - tree.query(i-1));
            if(p[i] <= i) {
                ++cnt;
            } else {
                ++sum;
                tree.add(p[i], 1);
            }
        }
        ans = std::max(ans, cnt);
        printf("%d\n", ans);
    }

    return 0;
}