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

char name[110][110];

std::pair<char, char> handle(char *a, char *b) {
    int n = std::max(strlen(a), strlen(b));
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            return {a[i], b[i]};
        }
    }
    return {'\0', '\0'};
}

#include <queue>

bool map[256][256];
int dgr[256];
char ans[256];
int ans_tot = 0;

void solve() {
    int n;
    readInt(n);
    for (int i = 1; i <= n; ++i)
        scanf("%s", name[i]);
    for (int i = 2; i <= n; ++i) {
        auto pr = handle(name[i - 1], name[i]);
        if (pr.first == '\0')
            continue;
        if (pr.second == '\0' && pr.first != '\0') {
            printf("Impossible\n");
            return;
        }
        if(map[pr.first][pr.second] == 0) {
            map[pr.first][pr.second] = 1;
            ++dgr[pr.second];
        }
    }
    std::queue<char> q;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (dgr[c] == 0)
            q.emplace(c);
    }
    
    while (q.size()) {
        char x = q.front();
        q.pop();
        ans[ans_tot++] = x;
        for (char y = 'a'; y <= 'z'; ++y) {
            if (!map[x][y])
                continue;
            --dgr[y];
            if (dgr[y] == 0)
                q.emplace(y);
        }
    }
    if (ans_tot != 26)
        printf("Impossible\n");
    else
        printf("%s\n", ans);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}
