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

struct Data {
    int pos, id;
};

bool operator < (Data a, Data b) {
    return a.pos < b.pos;
}

void solve() {
    int n, d;readInt(n, d);
    veci x(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(x[i]);
    std::vector<Data> data(n);
    for (int i = 0; i < n; ++i) {
        data[i].id = i + 1;
        data[i].pos = x[i + 1];
    }
    std::sort(data.begin(), data.end());
    veci ans;
    for (int i = 0; i < n; ++i) {
        bool apart = true;
        if(i > 0 && data[i - 1].pos > data[i].pos - d)
            apart = false;
        if(i + 1 < n && data[i].pos + d > data[i + 1].pos)
            apart = false;
        if(apart)
            ans.emplace_back(data[i].id);
    }
    std::sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for(auto x : ans)
        printf("%d ", x);
    printf("\n");
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}