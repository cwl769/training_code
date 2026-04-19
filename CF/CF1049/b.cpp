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

int getN(int x_1) {
    std::vector<int> part;
    for(int t=x_1;t;t/=10) {
        part.push_back(t%10);
    }
    if(part.back() == 9) {
        return part.size() + 1;
    } else {
        return part.size();
    }
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int x;readInt(x);
        int y = 1;
        for(int i=0,tmp=getN(x+1);i<tmp;++i) {
            y *= 10;
        }
        y -= (x+1);
        printf("%d\n", y);
    }

    return 0;
}