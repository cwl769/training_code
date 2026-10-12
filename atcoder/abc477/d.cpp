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

char op[10];

void solve() {
    int n, q;readInt(n, q);
    std::vector<veci> cht(n + 2);
    std::map<int, char, std::greater<int> > map;
    for (int t = 1; t <= q; ++t) {
        int tp;readInt(tp);
        if(tp == 1) {
            int x;readInt(x);
            cht[x].emplace_back(t);
        } else {
            scanf("%s", op);
            map[t] = op[0];
        }
    }
    for(int i = 1; i <= n; ++i)
        cht[i].emplace_back(q + 1);
    for (int i = 1; i <= n; ++i) {
        char cur = 'a';
        bool sta = 0;
        int l = 1;
        for(auto ttt : cht[i]) {
            int r = ttt - 1;

            auto it = map.lower_bound(r);
            if(!sta) {
                if(it != map.end() && it->first >= l)
                    cur = it->second;
            }

            l = r + 1;
            sta ^= 1;
        }
        printf("%c", cur);
    }
    printf("\n");
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}