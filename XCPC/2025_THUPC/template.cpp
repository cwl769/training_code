#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

template<typename T>
void readInt(T& x) {
    bool f = 0;
    x = 0;
    char c = getchar();
    for(;c<'0'||c>'9';c=getchar()){if(c=='-')f=!f;}
    for(;'0'<=c&&c<='9';c=getchar())
        x = x * 10 + (c - '0');
    if(f)x = -x;
}

template<typename T, typename ...ARGS>
void readInt(T& x, ARGS&... args) {
    readInt(x);
    readInt(args...);
}

int main() {
    

    return 0;
}