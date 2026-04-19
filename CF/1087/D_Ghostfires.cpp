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
typedef std::vector<int> vector;

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

int mx;
std::vector<char> ans;

void build(int r, int g, int b, char cr, char cg, char cb) {
    if(r >= g + b) {
        int len = g + b + std::min(r, g+b+1);
        if(len > mx) {
            mx = len;
            ans.resize(len);
            for(int i=0;i<len;i+=2)
                ans[i] = cr;
            for(int i=1;i<2*g;i+=2)
                ans[i] = cg;
            for(int i=2*g+1;i<len;i+=2)
                ans[i] = cb;
        }
    } else {
        int len = r + std::min(g + b, r+1);
        if(len > mx) {
            mx = len;
            ans.resize(len);
            for(int i=0;i<g*2&&i<len;i+=2)
                ans[i] = cg;
            for(int i=g*2;i<len;i+=2)
                ans[i] = cb;
            for(int i=1;i<len;i+=2)
                ans[i] = cr;
        }
    }
    if(r >= 2 && g>1 && b>1) {
        int len = 2 + std::min(g, b) * 2;
        if(len > mx) {
            mx = len;
            ans.resize(len);
            ans[0] = cr;
            ans[len-1] = cr;
            for(int i=1;i<len-1;i+=2)
                ans[i] = cg;
            for(int i=2;i<len-1;i+=2)
                ans[i] = cb;
        }
    }
}

int main() {
    int T;readInt(T);
    while (T--) {
        int r, g, b;readInt(r, g, b);
        mx = 0;
        ans.clear();
        build(r, g, b, 'R', 'G', 'B');
        build(g, r, b, 'G', 'R', 'B');
        build(b, r, g, 'B', 'R', 'G');
        for(int i=0;i<mx;++i)
            printf("%c", ans[i]);
        printf("\n");
    }

    return 0;
}