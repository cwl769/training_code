#include <cstdio>
#include <cstring>
#include <queue>

typedef long long int64;

struct Data {
    int v, person, part;
};

bool operator < (Data a, Data b) {
    return a.v < b.v;
}

int main() {
    int T;scanf("%d", &T);
    for(;T;--T) {
        int n;scanf("%d", &n);
        std::priority_queue<Data> heap;
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=3;++j) {
                int x;scanf("%d", &x);
                heap.push({
                    .v = x,
                    .person = i,
                    .part = j
                });
            }
        }
        int64 ans = 0;
        std::vector<bool> vis(n+1);
        int cnt[4] = {0, 0, 0, 0};
        while(heap.size()) {
            Data cur = heap.top();heap.pop();
            if(vis[cur.person])continue;
            if(cnt[cur.part]==n/2)continue;
            ans += cur.v;
            vis[cur.person] = true;
            ++cnt[cur.part];
        }
        printf("%lld\n", ans);
    }

    return 0;
}