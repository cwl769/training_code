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

struct Node {
    char *st, *ed;
    std::vector<Node*> son;
    Node():st(),ed(),son(){}
};

char s[500010], t[500010];

int cnt(char *str) {
    int ans = 0;
    for(;*str != '\0';++str) {
        if(*str == ')') {
            if(*(str-1) == '(') {
                ++ans;
            }
        }
    }
    return ans;
}

int main() {
    int T;readInt(T);
    while(T--) {
        int n;readInt(n);
        scanf("%s%s", s+1, t+1);
        
    }

    return 0;
}