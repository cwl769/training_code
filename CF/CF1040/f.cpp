#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <algorithm>

const int LEN = 1;
char str[256];

void print(int s) {
    for(int i=0,p=1;i<LEN;++i,p<<=1) {
        snprintf(str+i+1, 2, (s&p) ? "(" : ")" );
    }
    printf("%s", str+1);
}

int ans[LEN+1][LEN+1];
int vis[LEN+1][LEN+1];

void dp() {
    for(int len = 2;len<=LEN;++len) {
        for(int l=1,r=len;r<=LEN;++l,++r) {
            ans[l][r] = ans[l][r-1];
            if((len&1)^1) { // len is even
                vis[l][r] = 0;
                if(str[l]=='(' && str[r]==')') {
                    vis[l][r] ^= vis[l+1][r-1];
                }
                for(int sp=l+1;sp<r;sp+=2) {
                    vis[l][r] ^= ((vis[l][sp])&(vis[sp+1][r]));
                }
            } else {
                vis[l][r] = 0;
            }
            for(int i=l;i<r;++i) {
                ans[l][r] += vis[i][r];
            }
        }
    }
}

int main() {
    for(int i=0;i<13;++i) {
        printf("%d\n", a[i] + (b[i] * (b[i] + 1)) / 2);
    }
    for(int l=1;l<=LEN;++l)
        vis[l][l-1] = 1;
    int s = 1<<LEN;
    for(int i=0;i<s;++i) {
        print(i);
        dp();
        printf(" %d\n", ans[1][LEN]);
        // for(int l=1;l<=LEN;++l) {
        //     for(int r=1;r<=LEN;++r)
        //         printf("%2d ", ans[l][r]);
        //     printf("\n");
        // }
        // printf("\n");
        // for(int l=1;l<=LEN;++l) {
        //     for(int r=1;r<=LEN;++r)
        //         printf("%2d ", vis[l][r]);
        //     printf("\n");
        // }
        // printf("\n");
    }
    return 0;
}