#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>

int a[500010];

void solve() {
    int n;scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    std::map<int, int> map;
    for (int i = 1; i <= n; ++i)
        ++map[a[i]];
    int mex = 0;
    while(map.find(mex) != map.end() && map[mex] == 1) {
        ++mex;
    }
    std::map<int, int, std::greater<int> > big;
    for (int i = 1; i <= n; ++i) {
        if(a[i] >= mex)
            big[a[i]]++;
    }

    while(1) {
        bool brk = true;
        for(auto &[pos, cnt] : big) {
            if(cnt >= 2) {
                brk = false;
                int val = cnt / 2;
                cnt = cnt - val - val;
                big[pos - 1] += val;
                big[pos + 1] += val;
                break;
            }
        }
        if(brk) {
            break;
        }
    }
    mex = std::min(mex, big.rbegin()->first);
    printf("%d\n", mex);
}

int main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }

    return 0;
}