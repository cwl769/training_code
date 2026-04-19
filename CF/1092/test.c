#include <stdio.h>

int main() {
    int a = 1;
    switch (a)
    {
    default:
        printf("i don't know\n");
        break;
    case 1:
        printf("a = 1\n");
        break;
    }

    return 0;
}