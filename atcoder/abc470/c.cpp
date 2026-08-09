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

void solve() {
    itn n, q;
    readInt(n, q);
    std::map<int, int> map;
    int cur = 0;
    while (q--) {
        int tp;
        readInt(tp);
        if (tp == 1) {
            int x;
            readInt(x);
            int val = map[x];
            cur ^= val;
            cur ^= val + 1;
            ++map[x];
        } else {
            std::vector<int> del;
            for (auto &[x, v] : map) {
                cur ^= v;
                cur ^= v - 1;
                --v;
                if (v == 0)
                    del.emplace_back(x);
            }
            for (auto x : del)
                map.erase(x);
        }
        printf("%d\n", cur);
    }
    
}

int main() {
    //int T;readInt(T);
    //while(T--) {
        solve();
        //}

    return 0;
}
