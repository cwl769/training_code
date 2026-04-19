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

char name[20][20];

int main() {
    int n;readInt(n);
    for(int i=1;i<=n;++i) {
        fgets(name[i], 20, stdin);
        name[i][strlen(name[i])-1] = '\0';
    }
    int x;readInt(x);
    scanf("%s", name[19]);
    if(strcmp(name[x], name[19])==0) 
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}