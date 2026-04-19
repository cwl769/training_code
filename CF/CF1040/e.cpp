#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <algorithm>

const int a[13] = {0, 1, 1, 2, 1, 4, 9, 8, 3, 16, 34, 32, 1};
const int b[13] = {1, 1, 2, 3, 5, 7, 10, 15, 22, 31, 44, 63, 90};

int query(int l, int r) {
    printf("? %d ", r - l + 1);
    for(int i = l;i<=r;++i)
        printf("%d ", i);
    printf("\n");
    fflush(stdout);
    int ans;scanf("%d", &ans);
    return ans;
}

char str[1010];
const int maxAns = 13;

void getans(int l, int r, int t) {
    int len = r - l + 1;
    int sumcost = 0;
    for(int i=0;i<len;++i) {
        sumcost += ( (a[i] + b[i]) << 1);
        ++sumcost;
    }
    printf("? %d ", sumcost);
    int rep = 0;
    for(int i=l;i<=r;++i,++rep) {
        for(int j=0;j<a[rep];++j)
            printf("%d ", i);
        for(int j=0;j<b[rep];++j)
            printf("%d %d ", i, t);
        for(int j=0;j<a[rep];++j)
            printf("%d ", t);

        printf("%d ", t);
    }
    printf("\n");
    fflush(stdout);
    int ret;scanf("%d", &ret);
    rep = 1;
    for(int i=l;i<=r;++i,rep<<=1) {
        str[i] = ( (ret & rep) ? '(' : ')' );
    }
}

int main() {
    int T;scanf("%d", &T);
    for(;T;--T) {
        int n;scanf("%d", &n);
        str[n+1] = '\0';
        int t;
        printf("? %d ", n);
        for(int i=1;i<=n;++i)
            printf("%d ", i);
        printf("\n");
        fflush(stdout);
        int ret;
        scanf("%d", &ret);
        if(ret==0) {
            t = 1;
        }
        else {
            int l = 1, r = n;
            while(r - l > 1) {
                int mid = ((l+r)>>1);
                if(query(l, mid) > 0)
                    r = mid;
                else
                    l = mid;
            }
            t = r;
        }
        for(int l=1,r=maxAns;l<=n;l+=maxAns,r+=maxAns) {
            if(r > n) r = n;
            getans(l, r, t);
        }
        printf("! %s\n", str+1);
        fflush(stdout);
    }
    return 0;
}