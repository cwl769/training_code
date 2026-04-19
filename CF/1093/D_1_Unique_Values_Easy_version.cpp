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
#include <random>

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

bool check1(int x, const veci& a, const veci& b) {
    printf("? %d ", x+1);
    for(int i=0;i<=x;++i)
        printf("%d ", a[i]);
    printf("\n");
    fflush(stdout);
    int cnt1;readInt(cnt1);
    printf("? %d ", (int)b.size() + (int)a.size() - x - 1);
    for(int i=x+1;i<((int)a.size());++i)
        printf("%d ", a[i]);
    for(int i=0;i<(int)b.size();++i)
        printf("%d ", b[i]);
    printf("\n");
    fflush(stdout);
    int cnt2;readInt(cnt2);
    return cnt1 != cnt2;
}

bool check2(int x, const veci& a, const veci& b) {
    int cnt1, cnt2;
    int as = a.size();
    int bs = b.size();
    int n = a.size() + b.size();
    printf("? %d ", as + x + 1);
    for(auto v:a)
        printf("%d ", v);
    for(int i=0;i<=x;++i)
        printf("%d ", b[i]);
    printf("\n");
    fflush(stdout);
    readInt(cnt1);
    printf("? %d ", n - as - x - 1);
    for(int i=x+1;i<bs;++i)
        printf("%d ", b[i]);
    printf("\n");
    fflush(stdout);
    readInt(cnt2);
    return cnt1 <= cnt2;
}

bool check2(int x, const veci& a, const veci& b) {
    int cnt1, cnt2;
    int as = a.size();
    int bs = b.size();
    int n = a.size() + b.size();
    printf("? %d ", as + x + 1);
    for(auto v:a)
        printf("%d ", v);
    for(int i=0;i<=x;++i)
        printf("%d ", b[i]);
    printf("\n");
    fflush(stdout);
    readInt(cnt1);
    printf("? %d ", n - as - x - 1);
    for(int i=x+1;i<bs;++i)
        printf("%d ", b[i]);
    printf("\n");
    fflush(stdout);
    readInt(cnt2);
    return cnt1 == cnt2;
}

void fin(const veci& a, const veci& b) {
    int x = 0, y = 0, z = 0;
    int l = 0, r = (int)a.size() - 1;
    while(l < r) {
        int mid = ((l+r)>>1);
        if(check1(mid, a, b))
            r = mid;
        else 
            l = mid + 1;
    }
    x = l;
    l = 0;r = (int)b.size() - 1;
    while(l < r) {
        int mid = ((l+r)>>1);
        if(check2(mid, a, b))
            r = mid;
        else 
            l = mid + 1;
    }
    y = l;
    l = 0;r = (int)b.size() - 1;
    while(l < r) {
        int mid = ((l+r)>>1);
        if(check2(mid, a, b))
            r = mid;
        else 
            l = mid + 1;
    }
    z = l;
    printf("! %d %d %d\n", x, y, z);
    fflush(stdout);
}

std::mt19937 gen(114514);

void solve() {
    int n;readInt(n);
    while(1) {
        std::vector<int> vec;
        for(int i=1;i<=n*2+1;++i)
            vec.push_back(i);
        std::shuffle(vec.begin(), vec.end(), gen);
        printf("? %d ", )
        if() {
            
            return;
        }
    }
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}