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

struct BIT {
    int *c;
    int N;
    BIT(int n) {
        N = n + 10;
        c = (int*)calloc(N, sizeof(int));
    }
    ~BIT(){free(c);}
    void add(int x, int v) {
        for(;x<N;x+=(x&(-x)))
            c[x] += v;
    }
    int query(int x) {
        int ans = 0;
        for(;x;x-=(x&(-x)))
            ans += c[x];
        return ans;
    }
} bit(2000010);

int n;

void add(int x) {
    bit.add(x + (n+10), 1);
}
int query(int x) {
    return bit.query(2000010) - bit.query(x + (n+10));
}

int main() {
    readInt(n);
    std::vector<char> str(n+2);
    scanf("%s", str.begin() + 1);
    int pub = 0;
    int64 ans = 0;
    for(int i=1;i<=n;++i) {
        int val = 0;
        if(str[i] == 'A')
            val = 1;
        if(str[i] == 'B')
            val = -1;
        pub += val;
        add(-pub + val);
        ans += query(-pub);
    }
    printf("%lld\n", ans);

    return 0;
}