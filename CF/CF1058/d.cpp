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

int query(std::vector<int> &set, int x) {
    printf("? %d %d ", 1 + (int)set.size(), x);
    for(auto t:set)
        printf("%d ", t);
    printf("\n");
    fflush(stdout);
    int ret;readInt(ret);
    return ret;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<int> ans(2*n+1);
        std::vector<int> set;
        set.push_back(1);
        for(int i=2;i<=n*2;++i) {
            int ret = query(set, i);
            if(ret) {
                ans[i] = ret;
            } else {
                set.push_back(i);
            }
        }
        std::vector<int> antiset;
        for(int i=1,j=0;i<=n*2;++i) {
            if(j<set.size() && set[j] == i) {
                ++j;
                continue;
            }
            antiset.push_back(i);
        }
        for(auto x:set) {
            ans[x] = query(antiset, x);
        }
        printf("! ");
        for(int i=1;i<=n*2;++i)
            printf("%d ", ans[i]);
        printf("\n");
        fflush(stdout);
    }

    return 0;
}