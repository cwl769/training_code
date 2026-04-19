#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>

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

void manacher(const std::vector<int>& str, int n, std::vector<int>& ans) {
    int l=0, r=0;
    ans[0] = 1;
    for(int i=1;i<n;++i) {
        if(i>r) {
            ans[i] = 1;
        } else {
            ans[i] = std::min(ans[l+r-i], r-i+1);
        }
        while(i+ans[i]<n&&i-ans[i]>=0&&str[i+ans[i]]==str[i-ans[i]])++ans[i];
        if(i+ans[i]-1>r) {
            r = i+ans[i]-1;
            l = i-ans[i]+1;
        }
    }
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n, k;readInt(n, k);
        std::vector<int> str(n*2);
        for(int i=0;i<n;++i) {
            readInt(str[i*2]);
            str[i*2+1] = -1;
        }
        std::vector<int> ans(n*2);
        manacher(str, n*2, ans);
        // for(int i=0;i<n*2;++i)
        //     printf("%d ", ans[i]);
        // printf("\n");
        std::set<int> set;
        for(int i=0;i<2*n;++i) {
            if(i+ans[i]==2*n) {
                if(i-ans[i]>=0)
                    set.insert(str[i-ans[i]]);
            }
        }
        // printf("set:\n");
        // for(auto x:set)
        //     printf("%d ", x);
        // printf("\n");
        std::set<int> rest;
        for(int x=1;x<=n;++x)
            rest.insert(x);
        for(int x=1;x<=n;++x) {
            if(set.find(x)==set.end()) {
                printf("%d ", x);
                rest.erase(x);
                break;
            }
        }
        if(k>1) {
            for(int x=1;x<=n;++x) {
                if(rest.find(x)==rest.end() || x==str[2*n-2])
                    continue;
                printf("%d ", x);
                rest.erase(x);
                break;
            }
        }
        for(int i=3;i<=k;++i) {
            printf("%d ", *rest.begin());
            rest.erase(rest.begin());
        }
        printf("\n");
    }

    return 0;
}