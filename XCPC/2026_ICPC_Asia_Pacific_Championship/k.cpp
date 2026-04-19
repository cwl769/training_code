#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

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

bool check(const int x, const int n, const std::vector<int>& cnt) {
    int a = x, b = x;
    int cnt0 = cnt[0];
    int cnt1 = cnt[1];
    int cntlt6 = cnt0 + cnt1 + cnt[2] + cnt[3] + cnt[4] + cnt[5];
    int cntgt5 = cnt[6] + cnt[7] + cnt[8] + cnt[9];
    int any = 0;
    if(cnt0>=a) {
        cnt0 -= a;
        cntlt6 -= a;
        // cntlt10 -= a;
        any += a;
    } else {
        cntlt6 -= cnt0;
        any += cnt0;
        a -= cnt0;
        cnt0 = 0;
        if(cnt[1]/2 < a)
            return false;
        cnt1 -= a * 2;
        cntlt6 -= a * 2; 
    }
    if(cntlt6 < b) {
        return false;
    }
    any += b;
    cntlt6 -= b;
    return (cntgt5 + cntlt6 >= any);
}

int main() {
    int T;readInt(T);
    while(T--) {
        int n;readInt(n);
        std::vector<char> str(n+2);
        scanf("%s", str.begin() + 1);
        std::vector<int> val(n+2);
        for(int i=1;i<=n;++i)
            val[i] = str[i] - '0';
        std::vector<int> cnt(10);
        for(int i=1;i<=n;++i)
            ++cnt[val[i]];
        int l = 0, r = n / 4;
        while(l < r) {
            int mid = ((l+r+1) >> 1);
            if(check(mid, n, cnt)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        printf("%d\n", l);
    }

    return 0;
}