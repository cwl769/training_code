#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
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

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n, k;readInt(n, k);
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        std::vector<int> cnt(3*n+1);
        for(int i=1;i<=n;++i) {
            ++cnt[a[i]];
        }
        std::stack<std::pair<int, int> > stack;
        int ans = 0;
        for(int v=1;v<=n*3;++v) {
            if(cnt[v] > 1) {
                stack.push({v, cnt[v] - 1});
            } else if(cnt[v] == 1) {
                //do nothing
            } else {
                if(stack.empty())continue;
                if(stack.top().second==k) {
                    ans = std::max(ans, v - stack.top().first);
                }
                auto tmp = stack.top();stack.pop();
                stack.push({tmp.first, tmp.second - 1});
                if(stack.top().second==0) {
                    stack.pop();
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}