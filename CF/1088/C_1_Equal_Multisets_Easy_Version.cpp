#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

typedef long long int64;
typedef std::vector<int> vector;

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
    while(T--) {
        int n, k;readInt(n, k);
        std::vector<int> a(n+1);
        std::vector<int> b(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        for(int i=1;i<=n;++i)
            readInt(b[i]);
        bool printed = false;
        for(int i=1;i<=n-k;++i) {
            if(b[i] == -1) {
                b[i] = a[i];
            } else {
                if(b[i] != a[i]) {
                    printf("NO\n");
                    printed = true;
                    break;
                }
            }
        }
        if(printed)continue;
        for(int i=k+1;i<=n;++i) {
            if(b[i] == -1) {
                b[i] = a[i];
            } else {
                if(b[i] != a[i]) {
                    printf("NO\n");
                    printed = true;
                    break;
                }
            }
        }
        if(printed)continue;
        
        if(n-k < k) {
            std::vector<bool> vis(n+1);
            for(int i=1;i<=n-k;++i)
                vis[b[i]] = 1;
            for(int i=k+1;i<=n;++i)
                vis[b[i]] = 1;
            for(int i=n-k+1;i<=k;++i) {
                if(b[i] > 0) {
                    if(vis[b[i]]) {
                        printf("NO\n");
                        printed = true;
                        break;
                    } else {
                        vis[b[i]] = 1;
                    }
                }
            }
            if(!printed)
                printf("YES\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}