#include <cstdio>
#include <vector>
#include <cmath>

typedef long long int64;

void printBit(int x, int c) {
    if(c==0)return;
    printf("%d", (x>>(c-1))&1);
    printBit(x, c-1);
}

int main() {
    while(1) {
        int cnt, op;scanf("%d%d", &cnt, &op);
        for(int i=0;i<cnt;++i) {
            printf("0b");
            printBit(0b10000110 | ((op)<<3), 8);
            printf("\n");
        }
        fflush(stdout);
    }


    return 0;
}