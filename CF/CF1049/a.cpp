#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>

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
        std::vector<char> a(n+1);
        scanf("%s", a.begin());
        int cnt0 = 0;
        for(int i=0;i<n;++i)
            if(a[i] == '0')
                ++cnt0;
        int ans = 0;
        for(int i=0;i<cnt0;++i)
            if(a[i] == '1')
                ++ans;
        printf("%d\n", ans);
    }

    return 0;
}