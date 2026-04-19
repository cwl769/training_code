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
        int n, k;readInt(n, k);
        std::vector<int> cnt(n*3+1);
        for(int i=1;i<=n;++i) {
            int x;readInt(x);
            ++cnt[x];
        }
        int64 ans = 0;
        while(1) {
            bool end = true;
            for(int v=3*n;v>=1;--v) {
                if(cnt[v]>k) {
                    end = false;
                    break;
                }
            }
            if(end)
                break;
            for(int v=3*n;v>=1;--v) {
                if(cnt[v]>1) {
                    cnt[v+1] += cnt[v] - 1;
                    cnt[v] = 1;
                }
            }
            ++ans;
        }
        printf("%lld\n", ans);
    }

    return 0;
}