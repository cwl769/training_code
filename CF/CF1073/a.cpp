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

bool check(std::vector<int>&a, std::vector<int>&b) {
    int i=0,j=0;
    int n = (int)a.size() + (int)b.size();
    std::vector<int> res;
    for(int t=0;t<n;++t) {
        if(t&1) {
            res.push_back(a[i]);
            ++i;
        } else {
            res.push_back(b[j]);
            ++j;
        }
    }
    // for(auto x:res)
    //     printf("%d ", x);
    // printf("\n");
    for(int i=1;i<n;++i) {
        if(res[i-1] > res[i]){
            return false;
        }
    }
    return true;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<int> a(n);
        for(int i=0;i<n;++i)
            readInt(a[i]);
        std::vector<int> r, b;
        for(int i=0;i<n;++i) {
            if(i&1)
                r.push_back(a[i]);
            else
                b.push_back(a[i]);
        }
        std::sort(r.begin(), r.end());
        std::sort(b.begin(), b.end());
        // for(auto x:r)
        //     printf("%d ", x);
        // printf("\n");
        // for(auto x:b)
        //     printf("%d ", x);
        // printf("\n");
        if(n&1) {
            if(check(r, b))
                printf("YES\n");
            else
                printf("NO\n");
        } else {
            if(check(r, b) || check(b, r))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}