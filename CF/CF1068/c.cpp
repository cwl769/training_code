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
        int n, k;readInt(n, k);
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        std::set<int> set, set2;
        for(int i=1;i<=n;++i)
            set.insert(a[i]), set2.insert(a[i]);
        std::vector<int> ans;
        bool exist = true;
        // printf("set\n");
        // for(auto x:set)
        //     printf("%d ", x);
        // printf("\n");
        while(!set2.empty()) {
            int x = *set2.begin();
            ans.push_back(x);
            for(int t=x;t<=k;t+=x) {
                if(set.find(t)==set.end()) {
                    exist = false;
                    break;
                }
                set2.erase(t);
            }
            if(!exist)break;
        }
        if(exist) {
            printf("%d\n", (int)ans.size());
            for(auto x:ans)
                printf("%d ", x);
            printf("\n");
        }
        else
            printf("-1\n");
    }

    return 0;
}