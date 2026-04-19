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
typedef std::vector<int> vector;

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
    if(m % 4 == 0) {
        printf("%d\n", n * (m / 4) * 2);
        for(int i=0;i<n-1;++i) {
            for(int j=0;j<m;j+=4) {
                printf("%d %d ", i, j);
                printf("%d %d ", i, j+1);
                printf("%d %d ", i+1, j+1);
                printf("%d %d ", i+1, j+2);
                printf("\n");
                printf("%d %d ", i+1, j+1);
                printf("%d %d ", i+1, j+2);
                printf("%d %d ", i, j+2);
                printf("%d %d ", i, j+3);
                printf("\n");
            }
        }
            for(int j=0;j<m;j+=4) {
                printf("%d %d ", n-1, j);
                printf("%d %d ", n-1, j+1);
                printf("%d %d ", n-1-1, j+1);
                printf("%d %d ", n-1-1, j+2);
                printf("\n");
                printf("%d %d ", n-1-1, j+1);
                printf("%d %d ", n-1-1, j+2);
                printf("%d %d ", n-1, j+2);
                printf("%d %d ", n-1, j+3);
                printf("\n");
            }
        return 0;
    }
    if(n % 4 == 0) {
        printf("%d\n", m * (n / 4) * 2);
        for(int j=0;j<m-1;++j) {
            for(int i=0;i<n;i+=4) {
                printf("%d %d ", i, j);
                printf("%d %d ", i+1, j);
                printf("%d %d ", i+1, j+1);
                printf("%d %d ", i+2, j+1);
                printf("\n");
                printf("%d %d ", i+1, j+1);
                printf("%d %d ", i+2, j+1);
                printf("%d %d ", i+2, j);
                printf("%d %d ", i+3, j);
                printf("\n");
            }
        }
            for(int i=0;i<n;i+=4) {
                printf("%d %d ", i, m-1);
                printf("%d %d ", i+1, m-1);
                printf("%d %d ", i+1, m-1-1);
                printf("%d %d ", i+2, m-1-1);
                printf("\n");
                printf("%d %d ", i+1, m-1-1);
                printf("%d %d ", i+2, m-1-1);
                printf("%d %d ", i+2, m-1);
                printf("%d %d ", i+3, m-1);
                printf("\n");
            }
        return 0;
    }
    printf("Impossible!\n");

    return 0;
}