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

#include <queue>

void solve() {
    int n;
    readInt(n);
    std::queue<int> q;
    if (n & 1) {
        for (int i = (n + 3) / 2; i >= 3; --i) {
            q.emplace(i);
            if (i == (n + 3) / 2) {
                q.emplace(2);
            } else {
                q.emplace(n + 3 - i);
            }
        }
    } else {
        for (int i = (n + 2) / 2; i < n; ++i) {
            q.emplace(i);
            q.emplace(n + 1 - i);
        }
        q.emplace(n);
    }
    printf("1 ");
    while (q.size()) {
        printf("%d ", q.front());
        q.pop();
    }
    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
