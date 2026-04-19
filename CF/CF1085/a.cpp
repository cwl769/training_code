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
    while(T--) {
        int n;readInt(n);
        std::vector<char> str(n+2);
        scanf("%s", str.begin()+1);
        // std::vector<char> str1(str), str2(str);
        int mn = 0, mx = 0;
        for(int i=2;i<n;++i) {
            if(str[i-1] == '1' && str[i+1] == '1')
                str[i] = '1';
        }
        for(int i=1;i<=n;++i)
            mx += str[i] - '0';
        for(int i=2;i<n;++i) {
            if(str[i-1] == '1' && str[i+1] == '1')
                str[i] = '0';
        }
        for(int i=1;i<=n;++i)
            mn += str[i] - '0';
        printf("%d %d\n", mn, mx);
    }

    return 0;
}