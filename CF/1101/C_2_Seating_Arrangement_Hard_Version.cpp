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

struct Fenwick {
    int N;
    int *c;
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
    int get(int x) {
        if(x == 0)return 0;
        int ans = 0;
        for(;x;x-=(x&(-x)))
            ans += c[x];
        return ans;
    }
    int getfirst(int x) {
        int bd = get(x);
        x = 0;
        int sum = 0;
        for(int t=20;t>=0;--t) {
            if(x+(1<<t)>=N)
                continue;
            if(sum + c[x+(1<<t)] <= bd) {
                sum += c[x+(1<<t)];
                x += (1<<t);
            }
        }
        return x + 1;
    }
};

char str[200010];
char tmp[200010];

void solve() {
    int n, m, s;readInt(n, m, s);
    scanf("%s", str+1);
    
    int cnti = 0;
    for(int i=1;i<=n;++i) {
        if(str[i] == 'I')
            ++cnti;
    }
    for(int i=1;i<=n;++i) {
        if(str[i] == 'A') {
            if(cnti<m) {
                ++cnti;
                str[i] = 'I';
            }
        }
    }

    int r1tab = m, r1avi = 0;
    int ans = 0;
    std::set<int> ipos;
    veci apos;
    Fenwick tree(n);
    for(int i=1;i<=n;++i) {
        if(str[i] == 'I') {
            if(r1tab) {
                ++ans;
                --r1tab;
                r1avi += s - 1;
                ipos.insert(i);
            }
        } else {
            if(r1avi) {
                ++ans;
                --r1avi;
            } else {
                tree.add(i, 1);
            }
            if(str[i] == 'A')
                apos.push_back(i);
        }
    }
    // printf("%s\n", str+1);
    // printf("tmp%d\n", ans);
    int tmp = ans;
    for(auto p:apos) {
        if(ipos.size() && p > *ipos.rbegin())
            break;
        int lim;
        if(tree.get(p) - tree.get(p-1) == 0) {
            --tmp;
            ++r1avi;
            lim = s;
        } else {
            tree.add(p, -1);
            lim = s-1;
        }
        while(r1avi && lim && tree.getfirst(p) <= n) {
            int x = tree.getfirst(p);
            // printf("x:%d\n", x);
            ++tmp;
            --r1avi;
            --lim;
            tree.add(x, -1);
        }
        // printf("[%d]%d\n", p, tmp);
        ans = std::max(ans, tmp);
    }
    printf("%d\n", ans);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}