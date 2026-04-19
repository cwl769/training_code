#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>
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
// FILE * log;
int query(int l, int r) {
    printf("? %d %d\n", l, r);
    // fprintf(log, "1-----\n");
    // fflush(log);
    fflush(stdout);
    // fprintf(log, "2-----\n");
    // fflush(log);
    int x;readInt(x);
    // fprintf(log, "3-----[%d, %d]%d\n", l, r, x);
    // fflush(log);
    return x;
}

char op[20];

int main() {
    // log = fopen("b.log", "w");
    scanf("%s", op);
    if(strcmp(op, "first")==0) {
        int T;readInt(T);
        for(;T;--T) {
            int n;readInt(n);
            int p1 = 0, pn = 0;
            for(int i=1;i<=n;++i) {
                int x;readInt(x);
                if(x==1)
                    p1 = i;
                if(x==n)
                    pn = i;
            }
            printf("%d\n", (p1 < pn)?0:1);
        }
    } else {
        int T;readInt(T);
        for(;T;--T) {
            int n, msg;readInt(n, msg);
            int cnt = 0;
            if(msg == 0) {
                int l = 2, r = n;
                for(;l<r;) {
                    int mid = ((l+r)>>1);
                    ++cnt;
                    // assert(cnt<=30);
                    if(query(1, mid)==n-1) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                printf("! %d\n", l);
                fflush(stdout);
            } else {
                int l = 1, r = n-1;
                for(;l<r;) {
                    int mid = ((l+r+1)>>1);
                    ++cnt;
                    // assert(cnt<=30);
                    if(query(mid, n)==n-1) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                printf("! %d\n", l);
                fflush(stdout);
            }
        }
    }

    return 0;
}