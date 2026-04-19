#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>

typedef long long int64;

template<typename T>
void readInt(T& x) {
    static bool f;
    x = 0;f = false;
    char c = getchar();
    for(;c<'0' || c>'9';c=getchar())if(c=='-')f=!f;
    for(;'0'<=c&&c<='9';c=getchar()) {
        x = x * 10 + c - '0';
    }
    if(f)x = -x;
}
template<typename T, typename ...Args>
void readInt(T& x, Args&... args) {
    readInt(x);
    readInt(args...);
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n, k, q;readInt(n, k, q);
        std::vector<int> nk(n+2), nlk(n+2);
        for(int i=0;i<q;++i) {
            int op, l, r;readInt(op, l, r);
            if(op==1) {
                ++nlk[l];
                --nlk[r+1];
            } else {
                ++nk[l];
                --nk[r+1];
            }
        }
        int cur_nk = 0, cur_nlk = 0;
        for(int i=1;i<=n;++i) {
            cur_nk += nk[i];
            cur_nlk += nlk[i];
            if(cur_nk && cur_nlk) {
                printf("%d ", k+1);
            } else if((!cur_nk) && (!cur_nlk)) {
                printf("%d ", k+1);
            } else {
                if(cur_nk) {
                    printf("%d ", i%k);
                } else {
                    printf("%d ", k);
                }
            }
        }
        printf("\n");
    }

    return 0;
}