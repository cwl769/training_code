#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>

template<typename T> 
void readInt(T& x) {
    x = 0;
    char c = getchar();
    while(c<'0'||c>'9')c=getchar();
    for(;'0'<=c&&c<='9';c=getchar()) {
        x = x * (T)10 + (c - '0');
    }
}
template<typename T, typename ...ARGS>
void readInt(T& x, ARGS&... args) {
    readInt(x);
    readInt(args...);
}

int main() {
    


    return 0;
}