#include <stdio.h>
#include <stdlib.h>

double arr[100][2];

int cmp(const void* pa, const void* pb) {
    double *a = *(double**)pa;
    double *b = *(double**)pb;
    if(a[0] < b[0])
        return -1;
    if(a[0] > b[0])
        return 1;
    return b[1] - a[1];
}

int main() {
    printf("%p\n", arr);
    printf("%p\n", arr+1);
    printf("%p\n", &arr[0][0]);
    printf("%p\n", &arr[0][1]);
    double **ptr = (double**)arr;
    printf("%p\n", ptr);
    printf("%p\n", ptr+1);
    printf("%p\n", *ptr);
    printf("%p\n", *(ptr+1));

    void *void_ptr = &((double*)(*arr));
    printf("%p\n", void_ptr);
    printf("%p\n", void_ptr+sizeof(*arr));

    return 0;
}