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

char map[300010];

int main() {
    int T;readInt(T);
    for(;T;--T) {
        scanf("%s", map+1);
        int n = strlen(map+1);

        bool has = false;
        bool inf = false;
        for(int i=1;i<=n;++i) {
            // printf("[%d]%d %d\n", i, (int)has, (int)inf);
            if(has && (map[i]=='*'||map[i]=='<')) {
                inf = true;
                break;
            }
            if(map[i]=='*'||map[i]=='>'){
                has = true;
                continue;
            }
        }
        if(inf) {
            printf("-1\n");
            continue;
        }

        int llen = 0, rlen = 0;
        for(int i=1;i<=n;++i) {
            if(map[i]=='>')
                break;
            ++llen;
        }
        for(int i=n;i>=1;--i) {
            if(map[i]=='<')
                break;
            ++rlen;
        }
        printf("%d\n", std::max(llen, rlen));
    }

    return 0;
}