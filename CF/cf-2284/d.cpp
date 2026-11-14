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

char fs[100];

char str[1010];

void first() {
    int n;readInt(n);
    scanf("%s", str + 1);
    veci node[2];
    for (int i = 1; i < n; ++i) {
        node[str[i] - '0'].emplace_back(i);
    }
    node[0].emplace_back(n);
    if(node[1].size() == 0u) {
        printf("%d\n", n);
        printf("1 2\n");
        printf("2 3\n");
        printf("3 1\n");
        for (int i = 4; i <= n; ++i)
            printf("%d %d\n", i - 1, i);
        return;
    }
    printf("%d\n", (int)node[0].size() * (int) node[1].size());
    for (auto x : node[0]) {
        for (auto y : node[1])
            printf("%d %d\n", x, y);
    }
}

typedef std::vector<veci> Graph;

void second() {
    int n, m;readInt(n, m);
    Graph g(n + 2);
    for (int i = 1; i <= m; ++i) {
        int x, y;readInt(x, y);
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    veci col(n + 2, -1);
    col[n] = 0;
    std::queue<int> q;
    q.emplace(n);
    bool no = false;
    while(q.size()) {
        int x = q.front();q.pop();
        for (auto y : g[x]) {
            if(col[y] != -1) {
                if(col[x] == col[y]) {
                    no = true;
                    break;
                }
                continue;
            }
            col[y] = (col[x] ^ 1);
            q.emplace(y);
        }
        if(no)break;
    }
    if(no) {
        for (int i = 1; i < n; ++i)
            printf("0");
        printf("\n");
        return;
    }
    for (int i = 1; i < n; ++i)
        printf("%d", col[i]);
    printf("\n");
}

int main() {
    scanf("%s", fs);
    int T;readInt(T);
    if(fs[0] == 'f')
        while(T--)first();
    else
        while(T--)second();

    return 0;
}