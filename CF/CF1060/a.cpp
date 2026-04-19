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
        int n, k;readInt(n, k);
        std::vector<char> str(n+2);
        scanf("%s", str.begin()+1);
        int ans = 0, last = INT_MIN / 2;
        for(int i=1;i<=n;++i) {
            if(str[i] == '1') {
                if(i-last >= k)
                    ++ans;
                last = i;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}