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
    // int T;readInt(T);
    // for(;T;--T) {
        int n = 250000;readInt(n);
        if(n==4) {
            printf("4\n");
            printf("1 4\n");
            printf("3 1\n");
            printf("2 1\n");
            printf("3 1\n");
        } else {
            n = 250047;
            std::vector<std::pair<int, int> > ans;
            int a = 63;
            for(int t=a;;t*=a) {
                int tt = t / a;
                for(int d=-tt*(a-1);d<0;d+=tt) {
                    for(int i=n;i>0;i-=t) {
                        ans.push_back({i+d, tt});
                    }
                }
                if(t>=n)
                    break;
            }
            printf("%d\n", (int)ans.size());
            for(auto x:ans) {
                printf("%d %d\n", x.first, x.second);
            }
        }
    // }

    return 0;
}