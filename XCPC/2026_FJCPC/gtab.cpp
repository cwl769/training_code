#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

struct Basis {
  int w, s; veci64 b;
  Basis(int n = 60) : w(n), s(0), b(n) {}
  void insert(i64 x) {
    for (int i = w - 1; i >= 0; --i) {
      if (!((x >> i) & 1)) continue;
      if (b[i] == 0) b[i] = x, ++s;
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

int map[110][110];

bool vis[110];

void dfs(int dep, int n, int st, int prev, i64 sta, Basis& base) {
    if(dep == 0) {
        sta ^= (1ll << map[st][prev]);
        base.insert(sta);
    }
    for (int x = 1; x <= n; ++x) {
        if(x == st || vis[x])continue;
        vis[x] = 1;
        dfs(dep - 1, n, st, x, sta ^ (1ll << map[x][prev]), base);
        vis[x] = 0;
    }
}

void check(int n) {
    Basis base;
    for(int k = 3; k <= n; ++k) {
        for (int st = 1; st <= n; ++st) {
            dfs(k - 1, st, st, st, 0, base);
        }
    }
    printf("%d -- %d\n", n, base.s);
}

int main() {
    int id = 0;
    for (int x = 2; x <= 100; ++x)
    for (int y = 1; y < x; ++y) {
        map[x][y] = map[y][x] = id;
        ++id;
    }

    for (int n = 1; n <= 11; ++n) {
        check(n);
    }

    return 0;
}