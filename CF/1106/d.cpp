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

constexpr int N = 1000010;
bool pvis[N];
int mnp[N];
veci prime;
void Euler() {
    pvis[0] = pvis[1] = 1;
    for (int x = 2; x < N; ++x) {
        if (!pvis[x]) {
            prime.emplace_back(x);
            mnp[x] = x;
        }
        for (auto p : prime) {
            int tmp = p * x;
            if (tmp >= N)
                break;
            pvis[tmp] = 1;
            mnp[tmp] = p;
            if (x % p == 0)
                break;
        }
    }
}

void solve() {
    int n;
    readInt(n);
    int ans = 0;
    int cnt = 0;
    int tn = n;
    while (tn > 1) {
        int p = mnp[tn];
        ++cnt;
        while (tn % p == 0) {
            ++ans;
            tn /= p;
        }
    }
    printf("%d\n", ans + cnt - 1);
}

int main() {
    Euler();
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}
