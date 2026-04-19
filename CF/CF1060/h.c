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
    Euler(1000000);
    int n;scanf("%d", &n);
    int mxa = 0;
    for(int i=1;i<=n;++i) {
        scanf("%d", a+i);
        if(a[i] > mxa)
            mxa = a[i];
        ++cnt[a[i]];
    }
    int64 ans = 0;
    for(int d=1;d<=mxa;++d) {
        int tcnt = 0;
        for(int j=1;;++j) {
            int tmp = d * j;
            if(tmp > mxa)break;
            tcnt += cnt[tmp];
        }
        ans += 1ll * miu[d] * tcnt * tcnt;
    }
    ans -= cnt[1];
    ans >>= 1;
    printf("%lld\n", ans);

    return 0;
}