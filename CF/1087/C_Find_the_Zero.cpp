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

int query(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int ans;
    readInt(ans);
    return ans;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        bool printed = false;
        for(int i=2;i<=n;++i) {
            int val = query(i, i + n);
            if(val) {
                printf("! %d\n", i);
                fflush(stdout);
                printed = true;
                break;
            }
        }
        if(printed)continue;
        int val1 = query(1, 2);
        int val2 = query(1, n+2);
        if(val1) {
            printf("! %d\n", 1);
            fflush(stdout);
        } else if(val2) {
            printf("! %d\n", 1);
            fflush(stdout);
        } else {
            printf("! %d\n", 1 + n);
            fflush(stdout);
        }
    }

    return 0;
}