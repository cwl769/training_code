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

struct Basis {
  int w, s; veci64 b;veci id;
  Basis(int n = 60) : w(n), s(0), b(n), id(n) {}
  void insert(i64 x, int ii) {
    for (int i = w - 1; i >= 0; --i) {
      if (!((x >> i) & 1)) continue;
      if (b[i] == 0) b[i] = x, id[i] = ii, ++s;
      x ^= b[i];
    }
  }
  bool check(i64 x) const {
    for (int i = w - 1; i >= 0; --i)
      if (((x >> i) & 1)) x ^= b[i];
    return x == 0;
  }
  int size() const { return s; }
};

void solve() {
    int n;readInt(n);
    int tar = 0;
    for (int i = 1; i <= n; ++i)
        tar |= i;
    tar <<= 1;
    int ori = 0;
    for (int i = 1; i <= n; ++i) {
        ori ^= i;
    }
    Basis base;
    for (int i = 1; i <= n; ++i) {
        base.insert(i ^ (i << 1), i);
    }
    veci ans(n + 2);
    for(;;++tar) {
        int dif = (tar ^ ori);
        if(base.check(dif)) {
            // printf("tar = %d\n", tar);
            i64 x = dif;
            for (int i = 30; i >= 0; --i) {
                if((x >> i) & 1) {
                    x ^= base.b[i];
                    ans[base.id[i]] = 1;
                }
            }
            break;
        }
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