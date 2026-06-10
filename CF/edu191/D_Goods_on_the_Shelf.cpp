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

void swap(int x, int y, veci& a, std::vector<std::set<int> > &pos) {
    int cx = a[x];
    int cy = a[y];
    pos[cx].erase(x);
    pos[cy].erase(y);
    pos[cx].insert(y);
    pos[cy].insert(x);
}

int cnt_diff(int tot, std::vector<std::set<int> > &pos, veci& cnt) {

    int cnt_diff = 0;
    for(int col = 1;col <= tot; ++col) {
        std::set<int> &cur = pos[col];
        if(cnt[col] == *cur.rbegin() - *cur.begin() + 1) {
            continue;
        }
        ++cnt_diff;
    }
    return cnt_diff;
}

void solve() {
    int n;readInt(n);
    std::vector<int> a(n+2);
    for(int i=1;i<=n;++i) {
        readInt(a[i]);
    }
    std::map<int, int> map;
    for(int i=1;i<=n;++i) {
        map[a[i]] = 0;
    }
    int tot = 0;
    for(auto &pr:map) {
        pr.second = ++tot;
    }
    for(int i=1;i<=n;++i) {
        a[i] = map[a[i]];
    }
    std::vector<std::set<int> > pos(tot+2);
    veci cnt(tot+2);
    for(int i=1;i<=n;++i) {
        pos[a[i]].insert(i);
        ++cnt[a[i]];
    }

    int cnt_init = cnt_diff(tot, pos, cnt);
    if(cnt_init > 2) {
        printf("NO\n");
        return;
    }
    if(cnt_init == 0) {
        printf("YES\n");
        return;
    }
    
    for(int col = 1;col <= tot; ++col) {
        std::set<int> &cur = pos[col];
        if(cnt[col] == *cur.rbegin() - *cur.begin() + 1) {
            continue;
        }
        int tmp = 0;
        int beg = *cur.begin();
        for(auto it=++cur.begin();it!=cur.end();++it) {
            int x = *it;
            if(cur.find(x+1)==cur.end()) {
                tmp = x+1;
                break;
            }
        }
        if(tmp > 0 && tmp <= n) {
            swap(beg, tmp, a, pos);
            if(cnt_diff(tot, pos, cnt) == 0) {
                printf("YES\n");
                return;
            }
            swap(beg, tmp, a, pos);
        }

        tmp = 0;
        beg = *cur.rbegin();
        for(auto it=++cur.rbegin();it!=cur.rend();++it) {
            int x = *it;
            if(cur.find(x+1)==cur.end()) {
                tmp = x+1;
                break;
            }
        }
        if(tmp > 0 && tmp <= n) {
            swap(beg, tmp, a, pos);
            if(cnt_diff(tot, pos, cnt) == 0) {
                printf("YES\n");
                return;
            }
            swap(beg, tmp, a, pos);
        }
    }
    printf("NO\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}