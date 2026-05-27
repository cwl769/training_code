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

bool solve() {
    int n;readInt(n);
    veci a(n);
    for(int i=0;i<n;++i) {
        readInt(a[i]);
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    int d = 0;
    while(a.size()) {
        // for(auto x:a)
        //     printf("%d ", x-d);
        // printf("\n");
        if((a.size()&1)&&((a.back()-d)&1))
            return true;
        int val = a.back()-d;
        if(((a.back()-d)&1)==0) {
            while(a.size()&&a.back()-d==val)
                a.pop_back();
            continue;
        }
        int cnt = 0;
        int i=a.size()-1;
        for(;i>=0;--i) {
            if(a[i]-d == val)
                ++cnt;
            else
                break;
        }
        if(i>=0&&a[i]-d==val+1&&(cnt&1)) {
            return true;
        }
        while(a.size()&&a.back()-d==val)
            a.pop_back();
        if(cnt&1) {
            ++d;
        }
    }
    return false;
}

int main() {
    int T;readInt(T);
    while(T--) {
        if(!solve())
            printf("Maya\n");
        else
            printf("Insight\n");
    }

    return 0;
}