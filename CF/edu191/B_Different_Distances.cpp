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

void add2(veci &ans, int &base) {
    ans.push_back(base + 1);
    ans.push_back(base + 2);
    ans.push_back(base + 1);
    ans.push_back(base + 1);
    ans.push_back(base + 2);
    ans.push_back(base + 2);
    ans.push_back(base + 1);
    ans.push_back(base + 2);
    base += 2;
}

void add3(veci &ans, int &base) {
    ans.push_back(base + 1);
    ans.push_back(base + 1);
    ans.push_back(base + 2);
    ans.push_back(base + 1);
    ans.push_back(base + 2);
    ans.push_back(base + 3);
    ans.push_back(base + 1);
    ans.push_back(base + 3);
    ans.push_back(base + 2);
    ans.push_back(base + 2);
    ans.push_back(base + 3);
    ans.push_back(base + 3);
    base += 3;
}

void solve() {
    itn n;readInt(n);
    veci ans;
    int base = 0;
    if(n & 1) {
        add3(ans, base);
        while (base < n) {
            add2(ans, base);
        }
    } else {
        while (base < n) {
            add2(ans, base);
        }        
    }
    for(auto x:ans)
        printf("%d ", x);
    printf("\n");
    return;
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }


    return 0;
}