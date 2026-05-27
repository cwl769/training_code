#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <map>

typedef long long i64;
typedef std::vector<int> veci;

int n = 6, vlim = 9;

void dfs(int ii, int vst, veci& cur, std::map<veci, int>& map) {
    if(ii == n) {
        veci sonv;
        for(int j=0;j<n;++j) {
            if(cur[j]==0)continue;
            if(j>0&&cur[j] == cur[j-1])continue;
            veci tmp = cur;
            for(int i=0;i<n;++i) {
                tmp[i] = std::min(tmp[i], cur[j]);
            }
            --tmp[j];
            if(map.find(tmp)==map.end()) {
                for(auto x:cur)
                    fprintf(stderr, "%d ", x);
                fprintf(stderr, "\n");
                for(auto x:tmp)
                    fprintf(stderr, "%d ", x);
                fprintf(stderr, "\n");
            }
            assert(map.find(tmp)!=map.end());
            sonv.emplace_back(map[tmp]);
        }
        std::sort(sonv.begin(), sonv.end());
        int mex = 0;
        for(auto x:sonv) {
            if(mex==x) {
                ++mex;
                continue;
            }
            break;
        }
        map[cur] = mex;
        for(auto x:cur)
            printf("%d,", x);
        printf(":%d\n", mex);
        return;
    }
    for(int v=vst;v<=vlim;++v) {
        cur[ii] = v;
        dfs(ii+1, v, cur, map);
    }
}

int main() {
    std::map<veci, int> map;
    veci cur(n);
    dfs(0, 0, cur, map);

    return 0;
}