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
        int n, q;readInt(n, q);
        std::vector<char> str(n+1);
        scanf("%s", str.begin());
        bool allA = true;
        for(int i=0;i<n;++i)
            if(str[i]=='B') {
                allA = false;
                break;
            }
        if(allA) {
            for(;q;--q) {
                int x;readInt(x);
                printf("%d\n", x);
            }
        } else {
            for(;q;--q) {
                int x;readInt(x);
                int ans = 0;
                int p = -1;
                while(x) {
                    ++p;++ans;
                    if(p==n)p = 0;
                    if(str[p]=='A')
                        --x;
                    else
                        x>>=1;
                }
                printf("%d\n", ans);
            }
        }
    }

    return 0;
}