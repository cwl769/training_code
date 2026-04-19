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

char s[300010], t[300010];

int main() {
    scanf("%s%s", s, t);
    char *p = s, *q = t;
    int ans = 0;
    --p;--q;
    do {
        ++p;++q;
        int scnt = 0, tcnt = 0;
        while(*p!='\0' && *p=='A') {
            ++scnt;
            ++p;
        }
        while(*q!='\0' && *q=='A') {
            ++tcnt;
            ++q;
        }
        // printf("%c %c %d %d\n", *p, *q, scnt, tcnt);
        if(*p != *q)
            break;
        // printf("%c %c %d %d\n", *p, *q, scnt, tcnt);
        ans += std::abs(scnt - tcnt);
    } while(*p != '\0');
    if(*p != *q) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}