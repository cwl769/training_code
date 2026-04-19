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

bool query(int a, int b) {
    printf("%d %d\n", a, b);
    fflush(stdout);
    int x;readInt(x);
    return x;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        bool found = false;
        for(int d=1;d<n;++d) {
            for(int i=1;i<=n;i+=d*2) {
                for(int j=i;j<i+d&&j+d<=n;++j) {
                    if(query(j, j+d)) {
                        found = true;
                        break;
                    }
                }
                if(found)break;
            }
            if(found)break;
            for(int i=1;i<=n;i+=d*2) {
                for(int j=i+d;j<i+d*2&&j+d<=n;++j) {
                    if(query(j, j+d)) {
                        found = true;
                        break;
                    }
                }
                if(found)break;
            }
            if(found)break;
        }
    }

    return 0;
}