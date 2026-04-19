#include <stdio.h>
#include <stdlib.h>

typedef long long int64;

int p[1000000], pcnt=0;
int mnp[1000010];
int miu[1000010];
void Euler(int N) {
    miu[1] = 1;
    for(int x=2;x<=N;++x) {
        if(!mnp[x]) {
            p[pcnt] = x;
            ++pcnt;
            mnp[x] = x;
            miu[x] = -1;
        }
        for(int j=0;;++j) {
            int64 t = 1ll * x * p[j];
            if(t>N)break;
            mnp[t] = p[j];
            if(p[j]==mnp[x]) {
                miu[t] = 0;
                break;
            } else {
                miu[t] = -miu[x];
            }
        }
    }
}

int a[1000010];
int cnt[1000010];

int main() {
    int n;scanf("%3d",  &n);
    printf("%d\n", n);

    return 0;
}