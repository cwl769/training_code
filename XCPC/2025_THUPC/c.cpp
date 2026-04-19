#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
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
    int T;readInt(T);
    for(;T;--T) {
        int n, x;readInt(n, x);
        // printf("%d %d\n", n, x);
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i) {
            readInt(a[i]);
        }
        if(n==1) {
            printf("%d\n", a[1]);
            continue;
        }
        if(n<=3) {
            int mx = INT_MIN;
            for(int i=1;i<=n;++i)
                mx = std::max(mx, a[i]);
            printf("%d\n", mx);
            continue;
        }

        if(x==1) {
            int mni = -1;
            for(int i=3;i<=n;++i)
                if(mni==-1 || a[i]<a[mni])
                    mni = i;
            if(mni!=3)
                std::swap(a[3], a[mni]);
            ++x;
        } else if(x==n) {
            int mni = -1;
            for(int i=1;i<n-1;++i)
                if(mni==-1 || a[i]<a[mni])
                    mni = i;
            if(mni!=n-2)
                std::swap(a[n-2], a[mni]);
            --x;
        }

        std::vector<int> tmp;
        tmp.push_back(a[x]);
        if(x>1)
            tmp.push_back(a[x-1]);
        if(x<n)
            tmp.push_back(a[x+1]);
        int mn = INT_MAX;
        for(int i=1;i<x-1;++i)
            mn = std::min(mn, a[i]);
        for(int i=x+2;i<=n;++i)
            mn = std::min(mn, a[i]);
        std::sort(tmp.begin(), tmp.end());
        if(tmp.back()>mn)
            tmp.back() = mn;
        std::sort(tmp.begin(), tmp.end());
        printf("%d\n", *(tmp.rbegin()));
    }

    return 0;
}