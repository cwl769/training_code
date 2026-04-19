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
    int n, m;readInt(n, m);
    std::vector<int> a(n+1);
    int sum = 0;
    for(int i=1;i<=n;++i) {
        readInt(a[i]);
        sum += a[i];
    }
    bool can = false;
    for(int i=1;i<=n;++i) {
        if(sum-a[i]==m) {
            can = true;
            break;
        }
    }
    if(can)printf("Yes\n");
    else printf("No\n");

    return 0;
}