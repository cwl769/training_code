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

char s[100010];
char str[100010];

int main() {
    int T;readInt(T);
    for(;T;--T) {
        std::vector<int> cs(256), ct(256);
        scanf("%s", s);
        for(char *p=s;*p!='\0';++p)
            ++cs[(int)*p];
        scanf("%s", str);
        for(char *p=str;*p!='\0';++p)
            ++ct[(int)*p];
        
        bool possible = true;
        for(char c='a';c<='z';++c) {
            if(cs[c] > ct[c]) {
                possible = false;
                printf("Impossible\n");
                break;
            }
        }
        if(!possible) continue;
        for(char c='a';c<='z';++c) {
            ct[c] -= cs[c];
        }
        char cur = 'a';
        for(char *p=s;*p!='\0';++p) {
            if(*p>cur) {
                for(char c=cur;c<*p;++c) {
                    for(;ct[c];--ct[c])
                        putchar(c);
                }
            }
            putchar(*p);
        }
        for(char c=cur;c<='z';++c) {
            for(;ct[c];--ct[c])
                putchar(c);
        }
        putchar('\n');
    }

    return 0;
}