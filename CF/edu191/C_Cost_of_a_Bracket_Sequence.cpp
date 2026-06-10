#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

#define debug(...) fprintf(stderr, __VA_ARGS__)

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

#include <stack>
#include <queue>

char str[5010];

void run(int n, std::vector<bool>&vl, std::vector<bool>&vr, veci& ans) {
    // int ans = 0;
    for(int i=1;i<=n;++i)
        vl[i] = vr[i] = 0;
    std::stack<int> stack;
    for(int i=1;i<=n;++i) {
        if(ans[i])continue;
        if(str[i] == '(') {
            stack.push(i);
        } else {
            if(stack.size()) {
                vl[stack.top()] = 1;
                vr[i] = 1;
                stack.pop();
            }
        }
    }
    return ;
}

// struct Data {
//     int need;
//     bool dir;//0 l, 1 r;
// };

// bool operator < (Data a, Data b) {
//     return a.need < b.need;
// }

void solve() {
    int n, k;readInt(n, k);
    scanf("%s", str+1);
    std::vector<bool> vl(n+2), vr(n+2);
    
    std::vector<int> ans(n+2);

    while (k){
        // printf("%s\nk=%d\n", str+1, k);
        run(n, vl, vr, ans);
        int cntl = 0;
        int cntr = 0;
        for(int i=1;i<=n;++i) {
            if(ans[i])continue;
            if(str[i] == '(') {
                ++cntl;
                if(vl[i]) {
                    break;
                }
            }
        }
        for(int i=n;i>=1;--i) {
            if(ans[i])continue;
            if(str[i] == ')') {
                ++cntr;
                if(vr[i]) {
                    break;
                }
            }
        }
        if(cntl == 0 || cntr == 0)
            break;
        // printf("%d %d\n", cntl, cntr);
        if(k < cntl && k < cntr)
            break;
        if(cntl < cntr) {
            for(int i=1;i<=n;++i) {
                if(ans[i])continue;
                if(str[i] == '(') {
                    ans[i] = 1;
                    if(vl[i]) {
                        break;
                    }
                }
            }
            k -= cntl;
        } else {
            for(int i=n;i>=1;--i) {
                if(ans[i])continue;
                if(str[i] == ')') {
                    ans[i] = 1;
                    if(vr[i]) {
                        break;
                    }
                }
            }
            k -= cntr;
        }
    }
    
    

    for(int i=1;i<=n;++i)
        printf("%d", ans[i]);
    printf("\n");
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}