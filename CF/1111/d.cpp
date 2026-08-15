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

const int inf = 0x3f3f3f3f;

void expand(veci &a) {
    int n = a.size();
    int tar = (1 << 20);
    for (int i = 20; i >= 0; --i) {
        if ((1 << i) >= n)
            tar = (1 << i);
        else
            break;
    }
    a.resize(tar, inf);
}

int mylog2(int x) {
    int ans = 0;
    for (;x > 1; x >>= 1)
        ++ans;
    return ans;
}

void solve() {
    int n, q;
    readInt(n, q);
    veci a(n);
    for (int i = 0; i < n; ++i)
        readInt(a[i]);
    expand(a);

    n = a.size();
    int lgn = mylog2(n);
    // printf("%d %d\n", n, lgn);

    if(n == 1) {
        // printf("q = %d\n", q);
        printf("0\n");
        while(q--) {
            int p, x;readInt(p, x);
            printf("0\n");
        }
        return;
    }

    std::vector<veci> mn(lgn);
    std::vector<veci> mx(lgn);
    veci cnt(lgn);
    mn[0].resize(n);
    mx[0].resize(n);
    for (int i = 0; i < n; ++i)
        mn[0][i] = mx[0][i] = a[i];
    for (int i = 1; i < n; ++i)
        if (mx[0][i - 1] > mn[0][i])
            ++cnt[0];
    for (int t = 1; t < lgn; ++t) {
        int len = (1 << t);
        int tot = n / len;
        mn[t].resize(tot);
        mx[t].resize(tot);
        // printf("t = %d| %d %d\n", t, len, tot);
        for (int i = 0; i < tot; ++i) {
            mn[t][i] = std::min(mn[t-1][(i << 1)], mn[t-1][(i << 1) ^ 1]);
            mx[t][i] = std::max(mx[t-1][(i << 1)], mx[t-1][(i << 1) ^ 1]);
        }
        for (int i = 1; i < tot; ++i) {
            if (mx[t][i - 1] > mn[t][i])
                ++cnt[t];
        }
    }

    int anst = 0;
    while (anst < lgn && cnt[anst])
        ++anst;
    printf("%d\n", (1 << anst) >> 1);

    while (q--) {
        int p, x;
        readInt(p, x);

        if (p > 0) {
            if (mx[0][p - 1] > mn[0][p])
                --cnt[0];
        }
        if (p + 1 < n) {
            if (mx[0][p] > mn[0][p + 1])
                --cnt[0];
        }
        mn[0][p] = mx[0][p] = x;
        if (p > 0) {
            if (mx[0][p - 1] > mn[0][p])
                ++cnt[0];
        }
        if (p + 1 < n) {
            if (mx[0][p] > mn[0][p + 1])
                ++cnt[0];
        }

        for (int t = 1; t < lgn; ++t) {
            int len = (1 << t);
            int tot = n / len;
            int bl = p / len;
            if (bl > 0) {
                if (mx[t][bl - 1] > mn[t][bl])
                    --cnt[t];
            }
            if (bl + 1 < tot) {
                if (mx[t][bl] > mn[t][bl + 1])
                    --cnt[t];
            }

            mn[t][bl] = std::min(mn[t-1][(bl << 1)], mn[t-1][(bl << 1) ^ 1]);
            mx[t][bl] = std::max(mx[t-1][(bl << 1)], mx[t-1][(bl << 1) ^ 1]);
            
            if (bl > 0) {
                if (mx[t][bl - 1] > mn[t][bl])
                    ++cnt[t];
            }
            if (bl + 1 < tot) {
                if (mx[t][bl] > mn[t][bl + 1])
                    ++cnt[t];
            }
        }
        

        a[p] = x;

        anst = 0;
        while (anst < lgn && cnt[anst])
            ++anst;
        printf("%d\n", (1 << anst) >> 1);
    }
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
