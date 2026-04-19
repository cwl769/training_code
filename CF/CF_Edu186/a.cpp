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
        std::vector<char> str(n+2);
        scanf("%s", str.begin() + 1);
        int ans = 4;
        for(int i=1;i+3<=n;++i) {
            int cnt = 0;
            if(str[i] != '2') ++cnt;
            if(str[i+1] != '0') ++cnt;
            if(str[i+2] != '2') ++cnt;
            if(str[i+3] != '6') ++cnt;
            ans = std::min(ans, cnt);
        }
        int cnt = 0;
        for(int i=1;i+3<=n;++i) {
            if(str[i] == '2' && str[i+1] == '0' && str[i+2] == '2' && str[i+3] == '5') {
                ++cnt;
            }
        }
        ans = std::min(ans, cnt);
        printf("%d\n", ans);
    }

    return 0;
}