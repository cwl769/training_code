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

int64 C[110][110];

int main() {
    int n;readInt(n);
    for(int i=1;i<=n;++i)
    for(int j=i+1;j<=n;++j)
        readInt(C[i][j]);
    bool ans = false;
    for(int a=1;a<=n;++a) {
        for(int b=a+1;b<=n;++b) {
            for(int c=b+1;c<=n;++c) {
                if(C[a][b] + C[b][c] < C[a][c]) {
                    ans = true;
                }
            }
        }
    }
    if(ans)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}