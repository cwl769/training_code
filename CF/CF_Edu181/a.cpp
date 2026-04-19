#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <algorithm>

char str[200010];
char ans[200010];

int main()
{
    int T;scanf("%d", &T);
    for(;T;--T) {
        scanf("%s", str);
        char *pp = ans;
        for(char *p=str;*p!='\0';++p) {
            if(*p=='T') {
                *pp = 'T';
                ++pp;
            }
        }

        for(char *p=str;*p!='\0';++p) {
            if(*p!='T') {
                *pp = *p;
                ++pp;
            }
        }

        *pp = '\0';
        printf("%s\n", ans);
    }

    return 0;
}