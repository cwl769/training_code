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

char str[2000010];
bool val[2000010];
int ans[2000010];

void solve() {
    int nn;
    readInt(nn);
    int n = (1 << nn) - 1;
    scanf("%s", str + 1);
    for (int i = 1; i <= n; ++i) {
        val[i] = (str[i] == '1');
    }
    int pos = 0;
    for (int i = 1; i <= n; ++i) {
        if (val[i])
            pos ^= i;
    }
    val[pos] ^= 1;

    for (itn i = 1; i <= n; ++i) {
        ans[i] = 0;
    }
    std::priority_queue<int> heap;
    for (int i = 1; i <= n; ++i) {
        if (val[i])
            heap.emplace(i);
    }
    while (heap.size() > 1u) {
        int x = heap.top();
        heap.pop();
        int y = heap.top();
        heap.pop();
        if (x == y)
            continue;
        ans[x] = y;
        heap.emplace(x ^ y);
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
