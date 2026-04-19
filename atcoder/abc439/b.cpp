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

bool vis[100010];

bool check(int64 x) {
    int64 ans = 0;
    for(int64 t=x;t;t/=10) {
        ans += (t%10) * (t%10);
    }
    if(ans == 1)return true;
    if(vis[ans])return false;
    vis[ans] = 1;
    bool ret = check(ans);
    vis[ans] = 0;
    return ret;
}

int main() {
    int n;readInt(n);
    bool ans = check(n);
    if(ans)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}