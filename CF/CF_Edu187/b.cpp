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

char str[100];

int main() {
    int T;readInt(T);
    while(T--) {
        scanf("%s", str);
        std::vector<int> v;
        int sum = 0;
        v.push_back(str[0]-'1');
        sum += str[0] - '0';
        for(char *p=str+1;*p!='\0';++p) {
            v.push_back(*p-'0');
            sum += v.back();
        }
        std::sort(v.begin(), v.end());
        int ans = 0;
        while(sum >= 10) {
            ++ans;
            sum -= v.back();
            v.pop_back();
        }
        printf("%d\n", ans);
    }

    return 0;
}