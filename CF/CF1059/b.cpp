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

char str[100];

bool check(int n, int s) {
    int i = 0, j = n - 1;
    for(;i<n;++i) {
        while(i<n&&!((s>>i)&1))++i;
        while(j>=0&&!((s>>j)&1))--j;
        if(i>=n)break;
        if(j<0)break;
        if(str[i]!=str[j])
            return false;
    }
    i = 0;
    char last = 0;
    for(;i<n;++i) {
        while(i<n&&((s>>i)&1))++i;
        if(i>=n)break;
        if(str[i] < last)
            return false;
        last = str[i];
    }
    // printf("check %d %d true\n", n, s);
    return true;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        scanf("%s", str);
        int end = (1<<n);
        bool flag = false;
        for(int s=0;s<end;++s) {
            if(check(n, s)) {
                int cnt = 0;
                for(int i=0;i<n;++i)
                    if((s>>i)&1)
                        ++cnt;
                printf("%d\n", n-cnt);
                for(int i=0;i<n;++i)
                    if(((s>>i)&1)==0)
                        printf("%d ", i+1);
                printf("\n");
                flag = true;
                break;
            }
        }
        if(!flag)
            printf("-1\n");
    }

    return 0;
}