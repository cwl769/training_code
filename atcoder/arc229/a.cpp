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
#include <queue>
#include <stack>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

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

char str[1010];

int main() {
    int tot = 0;
    for(int i = 1; i <= 25; ++i){
        str[tot] = 'A';
        str[tot + 1] = 'R';
        tot += 2;
    }
    for(int i = 1; i <= 24; ++i){
        str[tot] = 'C';
        str[tot + 1] = 'R';
        tot += 2;
    }
    str[tot] = 'C';
    ++tot;

    int aa;readInt(aa);

    int now = 25 * 25;
    while(now > aa) {
        int f = -1;
        for (int i = 0; i + 2 < tot; ++i) {
            if(str[i] == 'A' && str[i + 1] == 'R' && str[i + 2] == 'C') {
                f = i;
                break;
            }
        }
        str[f] = 'C';
        str[f + 2] = 'A';
        --now;
    }
    printf("%s", str);

    return 0;
}