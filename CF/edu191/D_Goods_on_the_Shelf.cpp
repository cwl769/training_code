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

void swap(int x, int y, veci& a, int &cnt, const int n) {
    if(x == y) {
        return;
    }
    if(x > y)
        std::swap(x, y);
    // x < y
    // printf("swap(%d, %d)\n", x, y);
    if(x > 1 && a[x] != a[x-1]) {--cnt;}
    if(y < n && a[y] != a[y+1]) {--cnt;}
    if(x > 1 && a[y] != a[x-1]) {++cnt;}
    if(y < n && a[x] != a[y+1]) {++cnt;}
    if(x + 1 == y) {
        std::swap(a[x], a[y]);
        // for(int i=1;i<=n;++i)
        //     printf("%d ", a[i]);
        // printf("|%d\n", cnt);
        return;
    }
    if(a[x] != a[x+1]) {--cnt;}
    if(a[y] != a[y-1]) {--cnt;}
    if(a[y] != a[x+1]) {++cnt;}
    if(a[x] != a[y-1]) {++cnt;}
    std::swap(a[x], a[y]);
    // for(int i=1;i<=n;++i)
    //     printf("%d ", a[i]);
    // printf("|%d\n", cnt);
}

void solve() {
    int n;readInt(n);
    veci a(n+2);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    int cnt = 0;
    for(int i=2;i<=n;++i) {
        if(a[i] != a[i-1])
            ++cnt;
    }
    std::map<int, int> map;
    for(int i=1;i<=n;++i) {
        map[a[i]] = 0;
    }
    int tot = 0;
    for(auto &pr:map) {
        pr.second = ++tot;
    }
    if(tot - 1 == cnt) {
        printf("YES\n");
        return;
    }
    for(int i=1;i<=n;++i) {
        a[i] = map[a[i]];
    }
    std::vector<std::vector<int> > pos(tot+2);
    for(int i=1;i<=n;++i)
        pos[a[i]].emplace_back(i);
    for(int c=1;c<=tot;++c) {
        if(pos[c].size() == 1u)
            continue;
        int first, second, sp;
        first = pos[c][0];
        second = pos[c][1];
        sp = first;
        swap(first, second-1, a, cnt, n);
        if(cnt == tot - 1) {
            printf("YES\n");
            return;
        }
        swap(first, second-1, a, cnt, n);
        for(int i=1;i<(int)pos[c].size();++i) {
            if(i == pos[c].size() - 1 || pos[c][i]+1 != pos[c][i+1]) {
                sp = pos[c][i] + 1;
                break;
            }
        }
        if(sp <= n) {
            swap(first, sp, a, cnt, n);
            if(cnt == tot - 1) {
                printf("YES\n");
                return;
            }
            swap(first, sp, a, cnt, n);
        }
        
        first = pos[c][pos[c].size()-1];
        second = pos[c][pos[c].size()-2];
        sp = first;
        swap(first, second+1, a, cnt, n);
        if(cnt == tot - 1) {
            printf("YES\n");
            return;
        }
        swap(first, second+1, a, cnt, n);
        for(int i=pos[c].size()-2;i>=0;--i) {
            if(i == 0 || pos[c][i]-1 != pos[c][i-1]) {
                sp = pos[c][i] - 1;
                break;
            }
        }
        if(sp >= 1) {
            swap(first, sp, a, cnt, n);
            if(cnt == tot - 1) {
                printf("YES\n");
                return;
            }
            swap(first, sp, a, cnt, n);
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