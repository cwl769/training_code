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

char str[110];
int cnt[256];

int main() {
    scanf("%s", str);
    for(char *p = str;*p!='\0';++p) {
        ++cnt[(int)*p];
    }
    int mx = 0;
    for(char c='a';c<='z';++c) {
        mx = std::max(mx, cnt[c]);
    }
    for(char *p = str;*p!='\0';++p) {
        if(cnt[(int)*p] != mx) {
            putchar(*p);
        }
    }

    return 0;
}