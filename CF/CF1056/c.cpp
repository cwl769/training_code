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
        int n;readInt(n);
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i) {
            readInt(a[i]);
            --a[i];
        }
        bool all_same = true;
        for(int i=1;i<n;++i)
            if(a[i]!=a[i+1]) {
                all_same = false;
                break;
            }
        if(all_same) {
            int ans = 0;
            if(n/2 == a[1])++ans;
            if((n-1)/2 == a[1])++ans;
            printf("%d\n", ans);
        } else {
            std::vector<int> chs(n+1, -1);
            int ans = 1;
            for(int i=1;i<n;++i) {
                if(std::abs(a[i] - a[i+1])>1) {
                    ans = 0;
                    break;
                }
                if(a[i] > a[i+1]) {
                    if(chs[i]==0){
                        ans = 0;
                        break;
                    } else {
                        chs[i] = 1;
                        chs[i+1] = 1;
                    }
                } else if (a[i] < a[i+1]) {
                    if(chs[i]==1){
                        ans = 0;
                        break;
                    } else {
                        chs[i] = 0;
                        chs[i+1] = 0;
                    }
                } else {
                    if(~chs[i]) {
                        chs[i+1] = (chs[i] ^ 1);
                    }
                }
            }
            if(ans) {
                for(int i=n-1;i>=1;--i) {
                    if(a[i] == a[i+1] && (chs[i]==-1)) {
                        chs[i] = (chs[i+1]^1);
                    }
                }
            }
            if(ans) {
                int cnt = 0;
                for(int i=2;i<=n;++i) {
                    cnt += chs[i];
                }
                if(cnt!=a[1])
                    ans = 0;
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}