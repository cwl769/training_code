#include <cstdio>
#include <cstdint>

void unicode2utf8(int uc, char *ans) {
    ans[0] = (((uc>>18)&0b111) | 0b11110000);
    ans[1] = (((uc>>12)&0b00111111) | 0b10000000);
    ans[2] = (((uc>>6)&0b00111111) | 0b10000000);
    ans[3] = (((uc>>0)&0b00111111) | 0b10000000);
}

char tmp[100];

void printUnicode(int uc) {
    unicode2utf8(uc, tmp);
    printf("%s", tmp);
}

int main() {
    // unicode2utf8(0x1f600, tmp);
    // printf("%s\n", tmp);
    for(int x=0x1f400;x<=0x1f566;++x) {
        unicode2utf8(x, tmp);
        printf("%s", tmp);
    }
    for(int x=0x1f600;x<=0x1f64f;++x) {
        unicode2utf8(x, tmp);
        printf("%s", tmp);
    }
    for(int x=0x1f90c;x<=0x1f9ff;++x) {
        unicode2utf8(x, tmp);
        printf("%s", tmp);
    }

    for(int x=0xe6;x<=0xff;++x)
    for(int y=0xe6;y<=0xff;++y) {
        printUnicode(0x1f1|x);
        printUnicode(0x1f1|y);
    }

    return 0;
}