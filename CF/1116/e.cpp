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

void solve1() {
    
    
}

void solve2() {

    
}

char which_round[10];
int main() {
    int whrnd;
    scanf("%s", which_round);
    if (which_round[0] == 'f')
        whrnd = 1;
    else
        whrnd = 2;
    int T;readInt(T);
    while(T--) {
        if (whrnd == 1)
            solve1();
        else
            solve2();
    }

    return 0;
}
