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
        std::vector<char> str(n+2);
        scanf("%s", str.begin());
        int cnt[2] = {0,0};
        for(int i=0;i<n;++i)
            ++cnt[str[i]-'0'];
        std::vector<int> ans;
        for(int i=0;i<cnt[0];++i)
            if(str[i]=='1')
                ans.push_back(i+1);
        for(int i=cnt[0];i<n;++i)
            if(str[i]=='0')
                ans.push_back(i+1);
        int ans_n = (int)ans.size();
        if(ans_n == 0)
            printf("Bob\n");
        else {
            printf("Alice\n");
            printf("%d\n", ans_n);
            for(int i=0;i<ans_n;++i)
                printf("%d ", ans[i]);
            printf("\n");
        }
    }

    return 0;
}