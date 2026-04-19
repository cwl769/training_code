#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>

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

void printID(int x) {
    for(int i=0;i<7;++i,x/=26) {
        putchar((x%26)+'a');
    }
}

char op[100];

char str[100010];

int main() {
    scanf("%s", op);
    if(strcmp(op, "first")==0) {
        int n;readInt(n);
        std::set<int> set;
        std::vector<int> a(n);
        char *p = str;
        for(int i=0;i<n;++i) {
            int x;readInt(x);
            printID(x);
        }    
    } else {
        scanf("%s", str);
        int n = strlen(str) / 7;
        printf("%d\n", n);
        for(int i=0;i<n;++i) {
            int x = 0;
            for(int j=0;j<7;++j)
                x = x * 26 + (str[7*i+6-j] - 'a');
            printf("%d ", x);
        }
    }

    return 0;
}