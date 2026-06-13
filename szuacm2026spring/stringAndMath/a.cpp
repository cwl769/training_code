#include <cstdio>
#include <cstring>

char str[1000010];

int pi[1000010];

void kmp() {
    // printf("[%s]\n", str+1);
    int n = strlen(str+1);
    pi[1] = 0;
    for(int i=2,j=0;i<=n;++i) {
        pi[i] = 0;
        while(j && str[j+1] != str[i])j = pi[j];
        if(str[j+1] == str[i])
            pi[i] = j+1;
        j = pi[i];
    }
    // for(int i=1;i<=n;++i) {
    //     printf("%d ", pi[i]);
    // }
    // printf("\n");
}

int main() {
    while(1) {
        scanf("%s", str+1);
        if(str[1] == '.') {
            break;
        }
        int n = strlen(str+1);
        kmp();
        int d = n - pi[n];
        if( d<=pi[n] && n % d == 0) {
            printf("%d\n", n / d);
        } else {
            printf("1\n");
        }
    }

    return 0;
} 