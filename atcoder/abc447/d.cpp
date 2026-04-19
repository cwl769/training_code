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

char str[1000010];

int main() {
    scanf("%s", str + 1);
    int n = strlen(str+1);
    int a = 0, ab = 0, abc = 0;
    // printf("%s[%d]\n", str+1, n);
    for(int i=1;i<=n;++i) {
        if(str[i] == 'A') {
            ++a;
        } else if(str[i] == 'B') {
            if(a) {
                --a;
                ++ab;
            }
        } else {
            if(ab) {
                --ab;
                ++abc;
            }
        }
        // printf("[%d] %d %d %d\n", i, a, ab, abc);
    }
    printf("%d\n", abc);

    return 0;
}