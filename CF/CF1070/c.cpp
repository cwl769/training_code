#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

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
        std::vector<int64> a(n+1);
        std::vector<int64> seq[2];
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        for(int i=1;i<=n;++i) {
            seq[a[i]&1].push_back(a[i]);
        }
        if((int)seq[0].size() == n) {
            for(int i=1;i<=n;++i)
                printf("%d ", 0);
            printf("\n");
            continue;
        }
        if((int)seq[1].size() == n) {
            int64 mx = 0;
            for(int i=1;i<=n;++i)
                mx = std::max(mx, a[i]);
            for(int i=1;i<=n;++i) {
                if(i&1) printf("%d ", mx);
                else printf("0 ");
            }
            printf("\n");
            continue;
        }
        std::sort(seq[0].begin(), seq[0].end());
        std::sort(seq[1].begin(), seq[1].end());
        printf("%lld ", seq[1].back());
        int64 sum = seq[1].back();
        for(int i=1;i<=(int)seq[0].size();++i) {
            sum += seq[0][(int)seq[0].size()-i];
            printf("%lld ", sum);
        }
        for(int i=1;i<=n-(1+(int)seq[0].size());++i) {
            if(i&1) {
                if(i==n-(1+(int)seq[0].size())) printf("0 ");
                else printf("%lld ", sum - seq[0][0]);
            } else {
                printf("%lld ", sum);
            }
        }
        printf("\n");
    }

    return 0;
}