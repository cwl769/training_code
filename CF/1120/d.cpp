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
#include <queue>
#include <stack>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

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
  i64* c;
  int N;
  Fenwick(int n) : N(n) {
    c = (i64*)calloc(n + 10, sizeof(i64));
  }
  virtual ~Fenwick() { free(c); }
  void add(int x, i64 v) {
    x += 5;
    for (; x <= N; x += (x & (-x))) c[x] += v;
  }
  i64 query(int x) {
    x += 5;
    i64 ans = 0;
    for (; x; x -= (x & (-x))) ans += c[x];
    return ans;
  }
};

void solve() {
    int n;readInt(n);
    veci64 a(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    veci pp(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(pp[i]);
    std::set<int> set, spset;
    set.insert(0);
    set.insert(n + 1);
    spset.insert(0);
    spset.insert(n + 1);
    a[n + 1] = (i64) 4e14;
    Fenwick tree(n + 10);
    tree.add(n + 1, (i64) 4e14);
    // int ans = 0;

    auto update = [&n, &a, &spset, &tree](std::set<int>::iterator it)-> void {
        veci del;
        auto prv = it;
        --prv;
        for(;it != spset.end(); ++it) {
            i64 prsum = tree.query(*it - 1) - tree.query(*prv - 1);
            if(prsum >= a[*it]) {
                del.emplace_back(*it);
            } else {
                break;
            }
        }
        for(auto x : del) {
            // --ans;
            spset.erase(x);
        }
    };

    veci ans(n + 2);

    for(int i = n; i >= 1; --i) {
        int p = pp[i];
        i64 val = a[p];
        int nxt = *set.upper_bound(p);
        auto it = spset.lower_bound(nxt);
        set.insert(p);

        // if(*it == nxt) {
        //     auto prv = it;
        //     --prv;
        //     i64 prsum = tree.query(p - 1) - tree.query(*prv - 1);
        //     // i64 cursum = 0;
        //     if(val >= a[nxt]) {
        //         spset.erase(it);
        //         spset.insert(p);
        //         tree.add(p, a[p]);
        //         update(spset.upper_bound(p));
        //     } else if (val > prsum) {
        //         spset.insert(p);
        //         // ++ans;
        //         tree.add(p, a[p]);
        //     } else {
        //         tree.add(p, a[p]);
        //         update(it);
        //     }
        // } else {
        //     auto prv = it;
        //     --prv;
        //     i64 prsum = tree.query(p - 1) - tree.query(*prv - 1);
        //     if(val > prsum) {
        //         spset.insert(p);
        //         tree.add(p, a[p]);
        //         update(it);
        //     }
        // }

        auto prv = it;
        --prv;
        i64 prsum = tree.query(p - 1) - tree.query(*prv - 1);
        if(val > prsum) {
            spset.insert(p);
            tree.add(p, a[p]);
            update(spset.upper_bound(p));
        } else {
            tree.add(p, a[p]);
            update(spset.upper_bound(p));
        }

        ans[i] = (int)spset.size() - 3;
    }
    for (int i = 1; i <= n; ++i)
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