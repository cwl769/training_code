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
        std::vector<int> p(n+1);
        for(int i=1;i<=n;++i)
            readInt(p[i]);
        std::vector<char> tar(n+2);
        scanf("%s", tar.begin()+1);
        int mxi = 1, mni = 1;
        for(int i=2;i<=n;++i) {
            if(p[i] > p[mxi])
                mxi = i;
            if(p[i] < p[mni])
                mni = i;
        }
        if(tar[1]=='1' || tar[n]=='1' || tar[mxi]=='1' || tar[mni]=='1') {
            printf("-1\n");
            continue;
        }
        printf("5\n");
        printf("%d %d\n", 1, mni);
        printf("%d %d\n", 1, mxi);
        printf("%d %d\n", mni, n);
        printf("%d %d\n", mxi, n);
        printf("%d %d\n", std::min(mni, mxi), std::max(mni, mxi));
    }


    return 0;
}