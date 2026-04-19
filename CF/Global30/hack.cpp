#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>

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
    std::vector<int> a;
    a.push_back(998244353);
    for(int t=998244355;t<INT_MAX;++t) {
        bool flag = true;
        for(auto x:a)
            if(t%x%2==0) {
                flag = false;
                break;
            }
        if(flag) {
            a.push_back(t);
            printf("%d\n", t);
            fflush(stdout);
        }
    }
    printf("size=%d\n", (int)a.size());

    return 0;
}