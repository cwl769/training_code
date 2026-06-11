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

i64 qpow(i64 a, i64 b) {
    i64 ans = 1;
    for(;b;b>>=1) {
        if(b&1)
            ans = ans * a;
        a = a * a;
    }
    return ans;
}

char tmp[510];
char str[510];

char charset[] = "*()";

#include <stack>
bool check(char *str, int n, int k) {
    if(str[0] == '*' || str[n-1] == '*')
        return false;
    for(int i=0,cnt=0;i<n;++i) {
        if(str[i] == '*') {
            ++cnt;
            if(cnt > k)
                return false;
        } else {
            cnt = 0;
        }
    }
    std::stack<int> stack;
    for(int i=0;i<n;++i) {
        if(str[i] == '(') {
            stack.push(i);
        } else if( str[i] == ')') {
            if(stack.empty())
                return false;
            int l = stack.top()+1;
            int r = i-1;
            if(str[l]=='*'&&str[r]=='*') {
                if(r - l + 1 > k)
                    return false;
                for(int j=l;j<=r;++j)
                    if(str[j]!='*')
                        return false;
            }
            stack.pop();
        }
    }
    return stack.empty();
}

void solve() {
    int n, k;readInt(n, k);
    scanf("%s", tmp+1);
    int cnt = 0;
    veci pos;
    // printf("tmp:%s\n", tmp+1);
    for(int i=1;i<=n;++i)
        if(tmp[i] == '?'){
            ++cnt;
            pos.push_back(i);
        }
    int sum = qpow(3, cnt);
    strcpy(str+1, tmp+1);
    int ans = 0;
    for(int s=0;s<sum;++s) {
        // printf("s=%d\n", s);
        for(int i=0,t=s;i<cnt;++i,t/=3) {
            str[pos[i]] = charset[t%3];
        }
        // printf("cur:%s\n", str+1);
        if(check(str+1, n, k))
            ++ans;
    }
    printf("%d\n", ans);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}