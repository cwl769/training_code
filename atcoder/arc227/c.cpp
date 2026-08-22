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

char str[4010];
int pi[4010];

void kmp(int n) {
    pi[1] = 0;
    for (int i = 2; i <= n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && str[j + 1] != str[i])
            j = pi[j];
        if (str[j + 1] == str[i])
            ++j;
        pi[i] = j;
    }
}

int cnt[256];

void cal(int n, std::vector<char> & op) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            op.emplace_back(str[j]);
    }
}

void solve() {
    int n;
    readInt(n);
    scanf("%s", str + 1);
    kmp(n);
    // printf("%s\n", str + 1);
    // for (int i = 1; i <= n; ++i)
    //     printf("%d", pi[i]);
    // printf("\n");
    int t = n - pi[n];
    std::vector<char> op;
    if (n % t) {
        cal(n, op);
        printf("1\n");
        printf("%d\n", (int)op.size());
        for (auto x : op)
            putchar(x);
        printf("\n");
    } else {
        cal(t, op);
        printf("%d\n", n / t);
        printf("%d\n", (int)op.size());
        for (auto x : op)
            putchar(x);
        printf("\n");
    }
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}
