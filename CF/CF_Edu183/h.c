#include <stdio.h>
#include <stdint.h>

typedef long long int64;

int main() {
    int a = 0xffffffff;
    int64 b = 40;
    uint64_t ans = (a>>b);
    printf("%x\n", ans);
    return 0;
}