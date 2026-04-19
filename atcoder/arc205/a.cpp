#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>

template<typename T> 
void readInt(T& x) {
    x = 0;
    char c = getchar();
    while(c<'0'||c>'9')c=getchar();
    for(;'0'<=c&&c<='9';c=getchar()) {
        x = x * (T)10 + (c - '0');
    }
}
template<typename T, typename ...ARGS>
void readInt(T& x, ARGS&... args) {
    readInt(x);
    readInt(args...);
}

char map[510][510];
int f[510][510];

int main() {
    int n, q;readInt(n, q);
    for(int i=1;i<=n;++i) {
        scanf("%s", map[i]+1);
    }
    for(int i=1;i<n;++i)
    for(int j=1;j<n;++j) {
        if(
            map[i][j]=='.' &&
            map[i+1][j]=='.' &&
            map[i][j+1]=='.' &&
            map[i+1][j+1]=='.'
        ) {
            f[i][j] = 1;
        } else {
            f[i][j] = 0;
        }
    }
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j) {
        f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + f[i][j];
    }
    for(;q;--q) {
        int a, b, c, d;readInt(a, c, b, d);
        --c;--d;
        printf("%d\n", f[c][d] - f[c][b-1] - f[a-1][d] + f[a-1][b-1]);
    }


    return 0;
}