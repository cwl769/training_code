#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

i64 lowbit(i64 x) {
    return x & (-x);
}

int main() {
    i64 n;scanf("%lld", &n);
    if(n & 1)
        printf("1\n");
    else {
        i64 t = n / 2;
        if(lowbit(t + 1) == t + 1)
            ++t;
        printf("%lld\n", t);
    }

    return 0;
}