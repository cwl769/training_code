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

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n, k, p, m;readInt(n, k, p, m);
        std::multiset<int> set;
        std::vector<int> a(n+1);
        for(int i=1;i<=k;++i) {
            int x;readInt(x);
            a[i] = x;
            set.insert(x);
        }
        std::queue<int> q;
        for(int i=k+1;i<=n;++i) {
            int x;readInt(x);
            a[i] = x;
            q.push(x);
        }
        if(n == k) {
            printf("%d\n", m / a[p]);
            continue;
        }
        int ans = 0;
        int winp = 0;
        if(p <= k) {
            winp = 0;
        } else {
            winp = p - k;
        }
        while(m>=a[p]) {
            // printf("%d %d %d\n", m, winp, ans);
            if(winp == 0) {
                m -= a[p];
                ++ans;
                set.erase(set.find(a[p]));
                q.push(a[p]);
                set.insert(q.front());
                q.pop();
                winp = n - k;
            } else {
                if(*set.begin() > m)
                    break;
                int val = *set.begin();
                m-=val;
                set.erase(set.begin());
                q.push(val);
                set.insert(q.front());
                q.pop();
                --winp;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}