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
    int n;readInt(n);
    std::vector<int> a(n+1);
    std::vector<int> cnt(n+1);
    for(int i=1;i<=n;++i) {
        readInt(a[i]);
        if(~a[i])
            ++cnt[a[i]];
    }
    for(int i=1;i<=n;++i)
        if(cnt[i] > 1) {
            printf("No\n");
            return 0;
        }
    printf("Yes\n");
    int it = 1;
    for(int i=1;i<=n;++i){
        if(~a[i]) {
            printf("%d ", a[i]);
        } else {
            for(;cnt[it]!=0;)++it;
            printf("%d ", it);
            ++cnt[it];
        }
    }
    printf("\n");


    return 0;
}