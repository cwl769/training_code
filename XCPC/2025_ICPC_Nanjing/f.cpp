#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

int siz[4096][1010];
int fa[4096][1010];

int get(const int& s, int x) {
    if(fa[s][x] == x)
        return x;
    return fa[s][x] = get(s, fa[s][x]);
}

void merge(int s, int x, int y) {
    x = get(s, x);
    y = get(s, y);
    if(x == y)
        return;
    if(siz[s][x] < siz[s][y]) {
        fa[s][x] = y;
        siz[s][y] += siz[s][x];
    } else {
        fa[s][y] = x;
        siz[s][x] += siz[s][y];
    }
}

void solve() {
    int n, q;scanf("%d%d", &n, &q);
    char str[4];
    int x, y;
    for(int s = 0; s < 4096; ++s) {
        for (int i = 1; i <= n; ++i)
            fa[s][i] = i;
        for (int i = 1; i <= n; ++i)
            siz[s][i] = 1;
    }
    i64 ans = 0;
    
    while(q--) {
        scanf("%s%d%d", str, &x, &y);
        if(str[0] == '+') {
            int w;scanf("%d", &w);
            for(int t = w; ; t = ((t - 1) & w)) {
                merge(t, x, y);

                if(t == 0)
                    break;
            }
        } else {
            bool noans = true;
            for (int s = 4095; s >= 0; --s) {
                if(get(s, x) == get(s, y)) {
                    ans += s;
                    noans = false;
                    // printf("tmpans: %d\n", s);
                    break;
                }
            }
            if(noans) {
                --ans;
                // printf("tmpans: -1\n");
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }

    return 0;
}