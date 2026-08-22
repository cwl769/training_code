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

struct Data {
    i64 len, val;
    std::vector<char> ori;
};

bool cmp(const Data& a, const Data& b) {
    if(a.len == b.len) {
        return a.val < b.val;
    }
    return a.len < b.len;
}

bool cmphead(const Data& a, const Data& b) {
    return a.val < b.val;
}

bool cmpleft(const Data& a, const Data& b) {
    int n = std::max(a.len, b.len);
    for(int i = 0; i < n; ++i) {
        char va = '0', vb = '0';
        if(i < a.len)
            va = a.ori[i];
        if(i < b.len)
            vb = b.ori[i];
        if(va != vb)
            return va > vb;
    }
    return false;
}

void print(Data a) {
    for(auto x : a.ori)
        putchar(x);
}

char str[100];

void solve() {
    int n, k;
    readInt(n, k);
    std::vector<Data> dat(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        dat[i].len = strlen(str);
        dat[i].val = 0;
        for (int j = 0; j < dat[i].len; ++j) {
            dat[i].val = dat[i].val * 10ll + (str[j] - '0');
            dat[i].ori.push_back(str[j]);
        }
    }
    std::sort(dat.begin(), dat.end(), cmp);
    std::sort(dat.begin(), dat.end() - (k - 1), cmphead);
    if(dat[n - k].val) {
    } else {
        std::sort(dat.begin(), dat.end() - (k - 1), cmp);
        i64 mxi = 0;
        for (int i = n - k + 1; i < n; ++i)
            if(dat[i].val > dat[mxi].val)
                mxi = i;
        if(mxi == 0) {
            printf("0\n");
            return;
        }
        std::swap(dat[n - k], dat[mxi]);
    }
    std::sort(dat.begin() + n - k + 1, dat.end(), cmpleft);
    printf("%lld", dat[n - k].val);
    for (int i = n - k + 1; i < n; ++i)
        print(dat[i]);
    printf("\n"); 
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}