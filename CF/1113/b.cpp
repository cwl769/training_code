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

bool solve() {
    int n, m;
    readInt(n, m);
    veci a(n + 2), b(m + 2);
    for (int i = 1; i <= n; ++i)
        readInt(a[i]);
    for (int i = 1; i <= m; ++i)
        readInt(b[i]);
    std::sort(a.begin() + 1, a.begin() + n + 1);
    std::sort(b.begin() + 1, b.begin() + m + 1);
    int it = 1;
    std::vector<bool> vis(m + 2);
    std::vector<bool> avi(n + 2);
    for (itn i = 1; i <= m; ++i) {
        while (it <= n && a[it] < b[i]) {
            avi[it] = 1;
            ++it;
        }
        if (it > n)
            break;
        if (a[it] == b[i]) {
            ++it;
            vis[i] = 1;
        } else {
        }
    }
    while (it <= n) {
        avi[it] = 1;
        ++it;
    }

    std::multiset<int> set;
    for (int i = 1; i <= n; ++i) {
        if (avi[i])
            set.insert(a[i]);
    }

    for (int i = 1; i <= m; ++i) {
        if (!vis[i]) {
            if (set.empty())
                return false;
            int val = *set.begin();
            if (val > b[i])
                return false;
            set.erase(set.find(val));
        }
    }

    for (int i = m; i >= 1; --i) {
        if (!vis[i]) {
            if (set.empty())
                return false;
            int val = *set.rbegin();
            if (val < b[i])
                return false;
            set.erase(set.find(val));
        }
    }

    
    return true;
}

int main() {
    int T;readInt(T);
    while(T--) {
        if (solve()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
