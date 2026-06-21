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

void add(int x, std::set<i64> &ava) {
    ava.erase(x);
}

void del(int x, std::set<i64> &ava) {
    ava.insert(x);
}

void solve() {
    int n, m;readInt(n, m);
    std::vector<std::pair<int, int> > op;
    for(int i=1;i<=m;++i) {
        int l, r;readInt(l, r);
        op.emplace_back(l, -l);
        op.emplace_back(r+1, l);
    }
    std::sort(op.begin(), op.end());
    auto it = op.begin();
    std::multiset<int> setl;
    std::set<i64> ava;
    for(int i=1;i<=n;++i) {
        ava.insert(i);
    }
    int curl = 1;
    std::vector<int> ans(n+2);
    for(int i=1;i<=n;++i) {
        while(it!=op.end() && it->first == i) {
            // printf("%d %d\n", it->first, it->second);
            if(it->second < 0) {
                setl.insert(-it->second);
            } else {
                setl.erase(setl.find(it->second));
            }
            ++it;
        }
        int tl = (setl.empty()?i:*setl.begin());
        while(curl < tl) {
            del(ans[curl], ava);
            ++curl;
        }
        ans[i] = *ava.begin();
        add(ans[i], ava);
    }
    for(int i=1;i<=n;++i)
        printf("%d ", ans[i]);
    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}