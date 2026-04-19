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

char str[1000010];

int main() {
    int n;readInt(n);
    scanf("%s", str+1);
    int64 ans1 = 0, ans2 = 0;
    for(int i=1,t=1;i<=n*2;++i) {
        if(str[i] == 'A') {
            ans1 += abs(t - i);
            t += 2;
        }
    }
    for(int i=1,t=2;i<=n*2;++i) {
        if(str[i] == 'A') {
            ans2 += abs(t - i);
            t += 2;
        }
    }
    printf("%lld\n", std::min(ans1, ans2));

    return 0;
}