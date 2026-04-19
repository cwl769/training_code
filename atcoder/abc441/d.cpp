#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <queue>

typedef long long int64;

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

typedef std::vector<std::vector<std::pair<int, int64> > > Graph;

int main() {
    int n, m, l;int64 s, t;readInt(n, m, l, s, t);
    Graph g(n+1);
    for(int i=0;i<m;++i) {
        int x, y;int64 c;
        readInt(x, y, c);
        g[x].push_back({y, c});
    }
    std::queue<std::pair<int, std::pair<int, int64> > > q;
    q.push({1, {0, 0}});
    std::vector<bool> ans(n+1);
    while(q.size()) {
        auto tmp = q.front();q.pop();
        if(tmp.second.first == l) {
            if(s <= tmp.second.second && tmp.second.second <= t) {
                ans[tmp.first] = 1;
            }
        } else {
            int x = tmp.first;
            for(auto e:g[x]) {
                int y = e.first;
                int64 c = e.second;
                q.push({y, {tmp.second.first+1, tmp.second.second + c}});
            }
        }
    }
    for(int i=1;i<=n;++i)
        if(ans[i])
            printf("%d ", i);
    printf("\n");

    return 0;
}