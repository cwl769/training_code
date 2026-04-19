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

struct DSU {
    int *fa;
    DSU(int n) {
        fa = (int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;++i)
            fa[i] = i;
    }
    ~DSU() {
        free(fa);
    }
    int get(int x) {
        if(fa[x] == x)return x;
        return fa[x] = get(fa[x]);
    }
    void merge(int x, int y) {
        x = get(x);
        y = get(y);
        if(x == y)return;
        fa[x] = y;
    }
};

void solve() {
    int n, k;readInt(n, k);
    std::vector<int> a(n+1);
    std::vector<int> b(n+1);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    for(int i=1;i<=n;++i)
        readInt(b[i]);
    DSU dsu(n*2);
    for(int i=1;i<=n-k;++i) {
        if(a[i] == a[i+k]) {
            dsu.merge(n+i, n+i+k);
        } else {
            dsu.merge(i, n+i);
            dsu.merge(i+k, n+i+k);
        }
    }
    std::vector<int> val(n*2+1, -1);
    for(int i=1;i<=n;++i) {
        int rt = dsu.get(i);
        if(val[rt] > 0 && val[rt] != a[i]) {
            printf("NO\n");
            return;
        }
        if(val[rt] < 0) {
            val[rt] = a[i];
        }
    }
    
    for(int i=1;i<=n;++i) {
        int rt = dsu.get(n+i);
        if(val[rt] > 0) {
            if(b[i] > 0) {
                if(b[i] != val[rt]) {
                    printf("NO\n");
                    return;
                }
            } else {
                //nothing
            }
        } else {
            if(b[i] > 0) {
                val[rt] = b[i];
            } else {
                //nothing
            }
        }
    }

    for(int i=1;i<=n;++i) {
        b[i] = val[dsu.get(n+i)];
    }
    std::multiset<int> set;
    for(int i=1;i<=k;++i) {
        if(b[i] > 0) {
            set.insert(b[i]);
        }
    }
    for(int i=1;i<=k;++i) {
        auto it = set.find(a[i]);
        if(it!=set.end()) {
            set.erase(it);
        }
    }
    if(set.size()){
        printf("NO\n");
        return;
    }
    printf("YES\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}