#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <vector>

char str[110];

int main() {
    scanf("%s", str);
    if(strcmp(str, "red") == 0) {
        printf("SSS\n");
    } else if(strcmp(str, "blue") == 0) {
        printf("FFF\n");
    } else if(strcmp(str, "green") == 0) {
        printf("MMM\n");
    } else {
        printf("Unknown\n");
    }


    return 0;
}