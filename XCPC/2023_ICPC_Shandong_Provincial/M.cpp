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

typedef long long int64;
typedef long long i64;
typedef unsigned long long ui64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;


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

struct Pos {
    i64 x, y;
};

i64 oupdt(Pos a, Pos b) {
    return a.x * b.y - a.y * b.x;
}

typedef std::vector<Pos> vecpos;

void solve() {
    int n, k;readInt(n, k);
    vecpos p(n*5);
    for(int i=0;i<n;++i) {
        readInt(p[i].x, p[i].y);
    }
    for(int i=n;i<n*5;++i)
        p[i] = p[i-n];
    int a = k+1;
    i64 tmp = 0, ans = 0;
    for(int b=0;b<n;++b) {
        int c = b + k;
        if(b == 0) {
            for(int i=b+1;i<=c;++i) {
                tmp += oupdt(p[i-1], p[i]);
            }
        } else {
            tmp -= oupdt(p[b-1], p[b]);
            tmp += oupdt(p[c-1], p[c]);
        }
        if(a%n == c%n)
            ++a;
        while((a+1)%n!=b && oupdt(p[c], p[a]) + oupdt(p[a], p[b]) < oupdt(p[c], p[a+1]) + oupdt(p[a+1], p[b]))
            ++a;
        ans = std::max(ans, tmp + oupdt(p[c], p[a]) + oupdt(p[a], p[b]));
    }
    printf("%.12lf\n", ans/2.0);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}