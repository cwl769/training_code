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

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<int> a(n);
        for(int i=0;i<n;++i)
            readInt(a[i]);
        int cnt[2] = {0, 0};
        for(int i=0;i<n;++i) {
            if(a[i] < 2)
                ++cnt[a[i]];
        }
        if(cnt[0] == 0) {
            printf("NO\n");
        } else {
            if(cnt[1] == 0) {
                if(cnt[0] >= 2)
                    printf("NO\n");
                else
                    printf("YES\n");
            } else {
                printf("YES\n");
            }
        }
    }

    return 0;
}